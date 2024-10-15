#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <map>
#include <cstdio>  // For printf

class SoundManager {
public:
	SoundManager();
	~SoundManager();

	bool loadWAV(const std::string& name, const std::string& filename);  // Load a WAV file into a named buffer
	void playSound(const std::string& name);                             // Play a named sound effect
	bool loadBackgroundMusic(const std::string& name, const std::string& filename);
	void playBackgroundMusic(const std::string& name);                   // Play background music
	void stopBackgroundMusic();                                          // Stop currently playing music
	void cleanup();                                                      // Clean up OpenAL resources

private:
	ALCdevice* device;
	ALCcontext* context;
	std::map<std::string, ALuint> buffers;  // Map of named buffers
	std::map<std::string, ALuint> sources;  // Map of named sources
	ALuint musicSource;                     // Separate source for background music
};

