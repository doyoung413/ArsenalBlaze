#pragma once
#include "Object/EnemyType.hpp"

#include <fstream>
#include <string>

EnemyType CharEnemyTypeToEnum(std::string type);
const char* EnemyTypeEnumToChar(EnemyType type);

namespace FileManager
{
	void LoadSetting(const std::filesystem::path& filePath);
	void SaveSetting(const std::filesystem::path& outFilePath);

	void LoadLevelData(const std::filesystem::path& filePath);
	void SaveLevelData(const std::filesystem::path& outFilePath);
};