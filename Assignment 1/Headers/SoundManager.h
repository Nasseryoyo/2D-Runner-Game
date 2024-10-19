#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>
#include <map>
#include <AL/al.h>
#include <AL/alc.h>

class SoundManager {
public:
	// Constructor that initializes OpenAL
	SoundManager();

	// Destructor that cleans up OpenAL
	~SoundManager();

	// Add sound to the manager with a name and file path
	void addSound(const std::string& name, const std::string& filepath);

	// Play the sound by its name
	void playSound(const std::string& name);

	// Play background music by its name with optional looping
	void playBackgroundMusic(const std::string& name, bool loop = true);

	void stopBackgroundMusic(); // To stop the background music

private:
	ALCdevice* device;
	ALCcontext* context;
	ALuint backgroundSource; // Separate source for background music
	std::map<std::string, ALuint> soundBuffers;

	// Load a WAV file and buffer it into OpenAL
	void loadWavFile(const std::string& filepath, ALuint* buffer);
};

#endif // SOUNDMANAGER_H
