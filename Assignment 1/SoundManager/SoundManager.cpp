#include "SoundManager.h"
#include <vector>
#include <fstream>
#include <cstdarg>  // For variable argument functions


SoundManager::SoundManager() {
	// Open the device
	device = alcOpenDevice(nullptr);  // Use the default device
	if (!device) {
		printf("Failed to open audio device!\n");
	}

	// Create the context
	context = alcCreateContext(device, nullptr);
	if (!alcMakeContextCurrent(context)) {
		printf("Failed to set audio context!\n");
	}

	// Generate a source for background music
	alGenSources(1, &musicSource);
}

SoundManager::~SoundManager() {
	cleanup();
}

bool SoundManager::loadWAV(const std::string& name, const std::string& filename) {
	// Load the WAV file into a buffer
	std::ifstream file(filename, std::ios::binary);
	if (!file) {
		printf("Failed to load WAV file: %s\n", filename.c_str());
		return false;
	}

	// Skip the WAV header (44 bytes) and load the data
	file.seekg(44, std::ios::beg);
	std::vector<char> bufferData(std::istreambuf_iterator<char>(file), {});

	ALuint buffer;
	alGenBuffers(1, &buffer);
	alBufferData(buffer, AL_FORMAT_MONO16, bufferData.data(), bufferData.size(), 44100);

	// Store the buffer in the map
	buffers[name] = buffer;

	// Create a new source for the sound effect
	ALuint source;
	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);

	// Store the source in the map
	sources[name] = source;

	return true;
}

void SoundManager::playSound(const std::string& name) {
	// Play the sound effect from the corresponding source
	alSourcePlay(sources[name]);
}

bool SoundManager::loadBackgroundMusic(const std::string& name, const std::string& filename) {
	// Load background music in the same way as sound effects
	return loadWAV(name, filename);
}

void SoundManager::playBackgroundMusic(const std::string& name) {
	// Attach the buffer to the music source and play it
	alSourcei(musicSource, AL_BUFFER, buffers[name]);
	alSourcePlay(musicSource);
}

void SoundManager::stopBackgroundMusic() {
	alSourceStop(musicSource);  // Stop the background music
}

void SoundManager::cleanup() {
	// Stop all sources before deleting
	for (auto it = sources.begin(); it != sources.end(); ++it) {
		ALuint source = it->second;
		alSourceStop(source);  // Stop source
		alDeleteSources(1, &source);  // Delete source
	}

	// Clear the source map after deletion
	sources.clear();

	// Delete all buffers
	for (auto it = buffers.begin(); it != buffers.end(); ++it) {
		ALuint buffer = it->second;
		alDeleteBuffers(1, &buffer);  // Delete buffer
	}

	// Clear the buffer map after deletion
	buffers.clear();

	// Stop and delete the music source if it's valid
	if (alIsSource(musicSource)) {
		alSourceStop(musicSource);  // Stop the music source
		alDeleteSources(1, &musicSource);  // Delete the music source
	}

	// Reset the OpenAL context and close the device
	alcMakeContextCurrent(nullptr);  // Detach the current context
	if (context) {
		alcDestroyContext(context);  // Destroy the OpenAL context
		context = nullptr;
	}

	if (device) {
		alcCloseDevice(device);  // Close the OpenAL device
		device = nullptr;
	}
}


//int main(int argc, char** argr) {
//	SoundManager soundManager;
//	soundManager.loadWAV("jump", "sounds/powerup.wav");
//	soundManager.playSound("jump");
//	//soundManager.loadBackgroundMusic("login", "sounds/music.wav");
//	return 0;
//}
