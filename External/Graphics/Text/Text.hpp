#pragma once
#include "../Texture/Texture.hpp"
#include "../Shader/Shader.hpp"
#include "../Color/Color4f.hpp"

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

class Text
{
	struct Character
	{
		char id = 0;
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
		int xOffset = 0;
		int yOffset = 0;
		int xAdvance = 0;
		int page = 0;
	};

	struct Information
	{
		int fontSize = 0;
		int lineHeight = 0;
		int imageWidth = 0;
		int imageHeight = 0;
		int pages = 0;
		std::wstring   fontName{};
		std::vector<std::wstring>
			pageNames{};
	};

public:
	Text() = default;
	void LoadFromFile(const std::filesystem::path& filename);
	void DrawTextWithColor(std::string text, float x, float y, float angle = 0.f, float scale = 1.f, Color4f color = {1.f, 1.f, 1.f, 1.f});

	Shader GetShader() { return textShader; }
	void SetShader(Shader shader) { textShader = shader; }

	float GetFontSize() { return static_cast<float>(info.fontSize); }
	void SetDepth(float value) { depth = value; }

private:
	bool ReadFromFile(const std::filesystem::path& filename);
	Texture2D LoadImageFromFile(std::filesystem::path file);

	Character GetCharacter(char characterID) const noexcept;
	bool HasCharacter(char characterID) const noexcept;

	std::unordered_map<char, Character> characters{};
	Information                            info{};
	std::vector<Texture2D>                 pageTextures{};

	Shader textShader;
	unsigned int verticesHandle = 0;
	unsigned int dataBufferHandle = 0;
	float depth = 0.f;
};