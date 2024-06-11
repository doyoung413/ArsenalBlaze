#pragma once
#include <fstream>
#include <string>

namespace FileManager
{
	void LoadSetting(const std::filesystem::path& filePath);
	void SaveSetting(const std::filesystem::path& outFilePath);
};