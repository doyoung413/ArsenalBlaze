#pragma once
#ifndef BG_SOUNDMANAGER_H
#define BG_SOUNDMANAGER_H

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "fmod.hpp"

struct PlaybackTime
{
	int minutes = 0;
	int seconds = 0;
};

struct Sound
{
	FMOD::Sound* sound = nullptr;
	std::string name;
};

struct Channel
{
	FMOD::Channel* channel = nullptr;
	float soundVolume = 0.5f;
};

class SoundManager {
public:
	SoundManager() = default;
	~SoundManager();

	void Initialize(int maxChannel);
	void Update();
	void Shutdown();
	
	void ClearSounds();

	void LoadFile(std::string filepath, std::string name, bool loop = false);
	void LoadSoundFilesFromFolder(const std::string& folderPath);

	void Play(std::string name, int channelIndex, bool loop = false);
	void Play(int index, int channelIndex, bool loop = false);

	void Stop(int channelIndex);
	void Pause(int channelIndex, FMOD_BOOL state);
	void Pause(int channelIndex);

	bool IsPlaying(int channelIndex);
	bool IsPaused(int channelIndex);

	void VolumeUp(int channelIndex);
	void VolumeDown(int channelIndex);
	void SetVolume(int channelIndex, float volume);
	float GetChannelVolume(int channelIndex) { return channels.at(channelIndex).soundVolume; }


	std::vector<Sound>& GetSoundList() { return sounds; }
	int GetAmontOfSounds() { return soundMaxIndex; }
private:
	void ErrorCheck(FMOD_RESULT result_);
	int FindSoundIndexWithName(std::string name);

	std::vector<Sound> sounds;
	std::vector<Channel> channels;

	int soundMaxIndex = 0;

	FMOD::System* system;
	FMOD_RESULT result;
};
#endif