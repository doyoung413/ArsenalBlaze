#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cmath>

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <codecvt>

#include "SoundManager.hpp"

SoundManager::~SoundManager()
{
	Shutdown();
}

void SoundManager::Initialize(int maxChannel)
{
	result = FMOD::System_Create(&system);
	ErrorCheck(result);

	result = system->init(maxChannel, FMOD_INIT_NORMAL, 0);
	ErrorCheck(result);

	for (int i = 0; i <= maxChannel; i++)
	{
		Channel channel;
		channels.push_back(std::move(channel));
		channels.back().channel->setVolume(channels.back().soundVolume);
	}
}

void SoundManager::Update()
{
	result = system->update();
	ErrorCheck(result);
}

void SoundManager::Shutdown()
{
	ClearSounds();

	channels.clear();

	system->release();
	system->close();
}

void SoundManager::ClearSounds()
{
	for (auto sound : sounds)
	{
		result = sound.sound->release();
		ErrorCheck(result);
	}

	for (auto channel : channels)
	{
		result = channel.channel->stop();
		ErrorCheck(result);
	}

	sounds.clear();
	soundMaxIndex = 0;
}

void SoundManager::ErrorCheck(FMOD_RESULT result_)
{
	if (result_ != FMOD_OK && result_ != FMOD_ERR_INVALID_HANDLE)
	{
		exit(-1);
	}
}

void SoundManager::LoadFile(std::string filepath, std::string name, bool loop)
{
	Sound sound;
	sounds.push_back(std::move(sound));
	if (loop == true)
	{
		result = system->createSound(filepath.c_str(), FMOD_LOOP_NORMAL | FMOD_2D | FMOD_3D, nullptr, &sounds[soundMaxIndex].sound);
		ErrorCheck(result);
	}
	else
	{
		result = system->createSound(filepath.c_str(), FMOD_DEFAULT | FMOD_2D | FMOD_3D, nullptr, &sounds[soundMaxIndex].sound);
		ErrorCheck(result);
	}
	sounds[soundMaxIndex].name = name;
	++soundMaxIndex;
}

void SoundManager::LoadSoundFilesFromFolder(const std::string& folderPath)
{
	WIN32_FIND_DATAA   findData;
	HANDLE hFind;

	std::string searchPath = folderPath + "/*";

	hFind = FindFirstFileA(searchPath.c_str(), &findData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				continue;

			std::string fileName = findData.cFileName;
			std::string filePath = folderPath + "/" + fileName;

			std::string extension = filePath.substr(filePath.find_last_of('.') + 1);
			std::transform(extension.begin(), extension.end(), extension.begin(),
				[](unsigned char c) -> char { return static_cast<char>(std::tolower(c)); });

			if (extension == "wav")
			{
#ifdef _DEBUG
				std::cout << "Load Sound Complete : " << fileName << std::endl;
#endif
				LoadFile(filePath, fileName);
			}

		} while (FindNextFileA(hFind, &findData));

		FindClose(hFind);
	}
}

void SoundManager::Play(std::string name, int channelIndex, bool loop)
{
	int index = FindSoundIndexWithName(name);
	Play(index, channelIndex, loop);
}

void SoundManager::Play(int index, int channelIndex, bool loop)
{
	result = system->update();
	ErrorCheck(result);

	if (sounds[index].sound != nullptr)
	{
		result = system->playSound(sounds[index].sound, nullptr, false, &channels[channelIndex].channel);
		ErrorCheck(result);

		result = channels[channelIndex].channel->setVolume(channels[channelIndex].soundVolume);
		ErrorCheck(result);

		FMOD_MODE mode = loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		result = sounds[index].sound->setMode(mode);
		ErrorCheck(result);

	}
}

void SoundManager::Stop(int channelIndex)
{
	if (channels[channelIndex].channel != nullptr)
	{
		if (IsPlaying(channelIndex) == true)
		{
			result = channels[channelIndex].channel->stop();
			ErrorCheck(result);
		}
	}
}

void SoundManager::Pause(int channelIndex, FMOD_BOOL state)
{
	if (channels[channelIndex].channel != nullptr)
	{
		if (IsPlaying(channelIndex) == true)
		{
			result = channels[channelIndex].channel->setPaused(state);
			ErrorCheck(result);
		}
	}
}

void SoundManager::Pause(int channelIndex)
{
	if (channels[channelIndex].channel != nullptr)
	{
		if (IsPlaying(channelIndex) == true)
		{
			if (IsPaused(channelIndex) == false)
			{
				result = channels[channelIndex].channel->setPaused(true);
				ErrorCheck(result);
			}
			else
			{
				result = channels[channelIndex].channel->setPaused(false);
				ErrorCheck(result);
			}
		}
	}
}

bool SoundManager::IsPlaying(int channelIndex)
{
	if (channels[channelIndex].channel != nullptr)
	{
		bool isplay = false;
		result = channels[channelIndex].channel->isPlaying(&isplay);
		ErrorCheck(result);
		return isplay;
	}
	return false;
}

bool SoundManager::IsPaused(int channelIndex)
{
	if (channels[channelIndex].channel != nullptr)
	{
		bool ispaused = false;
		result = channels[channelIndex].channel->getPaused(&ispaused);
		ErrorCheck(result);
		return ispaused;
	}
	return false;
}

void SoundManager::VolumeUp(int channelIndex)
{
	SetVolume(channelIndex, channels[channelIndex].soundVolume + 0.05f);
}

void SoundManager::VolumeDown(int channelIndex)
{
	SetVolume(channelIndex, channels[channelIndex].soundVolume - 0.05f);
}

void SoundManager::SetVolume(int channelIndex, float volume)
{
	//if (channels[channelIndex].channel != nullptr)
	{
		result = channels[channelIndex].channel->setVolume(volume);
		ErrorCheck(result);

		channels[channelIndex].soundVolume = std::clamp(volume, 0.f, 1.f);
	}
}

int SoundManager::FindSoundIndexWithName(std::string name)
{
	auto it = std::find_if(sounds.begin(), sounds.end(), [&](const Sound& sound) {
		return sound.name == name; });

	if (static_cast<Sound>(*it).sound != nullptr)
	{
		return static_cast<int>(std::distance(sounds.begin(), it));
	}
	else
	{
		return NULL;
	}
}
