#include "SoundManager.h"
#include <cstdio>  // for printf
#include <fstream>
#include <vector>

SoundManager::SoundManager() {
	device = alcOpenDevice(nullptr); // Open default device
	if (!device) {
		printf("Failed to open sound device.\n");
		exit(EXIT_FAILURE);
	}

	context = alcCreateContext(device, nullptr); // Create context
	if (!alcMakeContextCurrent(context)) {
		printf("Failed to set sound context.\n");
		exit(EXIT_FAILURE);
	}

	alGenSources(1, &backgroundSource); // Create a source for background music
	ALenum error = alGetError();
	if (error != AL_NO_ERROR) {
		printf("Error generating background source: %s\n", alGetString(error));
	}
}

SoundManager::~SoundManager() {
	for (auto& pair : soundBuffers) {
		alDeleteBuffers(1, &pair.second);
	}
	alDeleteSources(1, &backgroundSource);

	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

void SoundManager::loadWavFile(const std::string& filepath, ALuint* buffer) {
	std::ifstream file(filepath, std::ios::binary);

	if (!file.is_open()) {
		printf("Could not open file: %s\n", filepath.c_str());
		return;
	}

	// Read WAV header (44 bytes)
	char header[44];
	file.read(header, 44);

	if (!file) {
		printf("Failed to read WAV header.\n");
		file.close();
		return;
	}

	// Extract channels, sample rate, and bits per sample from WAV header
	int channels = header[22]; // Number of channels: 1 = mono, 2 = stereo
	int sampleRate = *(int*)&header[24]; // Sample rate (44.1kHz, etc.)
	int bitsPerSample = header[34]; // Bits per sample (16-bit usually)

	// Check if the format is supported (only 16-bit PCM WAV files)
	if (bitsPerSample != 16) {
		printf("Unsupported WAV format: only 16-bit PCM supported.\n");
		file.close();
		return;
	}

	// Determine the OpenAL format based on channels
	ALenum format;
	if (channels == 1) {
		format = AL_FORMAT_MONO16;
	}
	else if (channels == 2) {
		format = AL_FORMAT_STEREO16;
	}
	else {
		printf("Unsupported channel count: %d\n", channels);
		file.close();
		return;
	}

	// Move to the data section and read the sound data
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(44, std::ios::beg);  // Skip the header

	std::vector<char> data(fileSize - 44);
	file.read(data.data(), fileSize - 44);

	if (!file) {
		printf("Failed to read WAV data.\n");
		file.close();
		return;
	}

	// Generate buffer and buffer the data with correct format
	alGenBuffers(1, buffer);
	ALenum error = alGetError();
	if (error != AL_NO_ERROR) {
		printf("Error generating buffer: %s\n", alGetString(error));
		file.close();
		return;
	}

	// Load data into the buffer
	alBufferData(*buffer, format, data.data(), data.size(), sampleRate);
	error = alGetError();
	if (error != AL_NO_ERROR) {
		printf("Error buffering data: %s\n", alGetString(error));
	}

	file.close();
}

void SoundManager::addSound(const std::string& name, const std::string& filepath) {
	ALuint buffer;
	loadWavFile(filepath, &buffer);
	soundBuffers[name] = buffer;
}

void SoundManager::playSound(const std::string& name) {
	if (soundBuffers.find(name) != soundBuffers.end()) {
		ALuint effectSource;
		alGenSources(1, &effectSource); // Generate a new source for the sound effect

		if (alIsSource(effectSource)) {
			alSourcei(effectSource, AL_BUFFER, soundBuffers[name]);

			alSourcePlay(effectSource); // Play the sound effect

			// Check for any error
			ALenum error = alGetError();
			if (error != AL_NO_ERROR) {
				printf("Error playing sound effect: %s\n", alGetString(error));
			}
		}
		else {
			printf("Invalid source for sound effect.\n");
		}
	}
	else {
		printf("Sound effect %s not found.\n", name.c_str());
	}
}



void SoundManager::playBackgroundMusic(const std::string& name, bool loop) {
	if (soundBuffers.find(name) != soundBuffers.end()) {
		alSourcei(backgroundSource, AL_BUFFER, soundBuffers[name]);
		alSourcei(backgroundSource, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
		alSourcePlay(backgroundSource);

		// Check for any error
		ALenum error = alGetError();
		if (error != AL_NO_ERROR) {
			printf("Error playing background music: %s\n", alGetString(error));
		}
	}
	else {
		printf("Background music %s not found.\n", name.c_str());
	}
}

void SoundManager::stopBackgroundMusic() {
	alSourceStop(backgroundSource); // Stop the background music
}
