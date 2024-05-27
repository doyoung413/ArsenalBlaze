/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: InputManager.hpp
//Description: Header file for SDL input
/*-------------------------------------------------------*/
#pragma once
#include "Texture/Renderer.hpp"


class SpriteManager
{
public:
	Texture2D LoadTexture(const char* file, std::string name);
	Texture2D LoadAnimatedTexture(const char* file, std::string name, int column, int row, float speed, bool loop = true, bool isPaused = false);
	Texture2D* GetTexture(std::string name);
	Sprite* GetSprite(std::string name);

	void DrawStart();
	void DrawEnd();

	void InitRenderer(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
	void DrawSprite(std::string name, glm::vec3 position, float angle, glm::vec3 scale, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);
	void DrawSpriteWithAnimation(std::string name, float dt, glm::vec3 position, float angle, glm::vec3 scale, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);
	void DrawSpriteWithAnimation(std::string name, Animation& animation, float dt, glm::vec3 position, float angle, glm::vec3 scale, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);

	void DrawRectangle(glm::vec3 position, float angle, glm::vec3 scale, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);
	void DrawRectangleLine(glm::vec3 position, float angle, glm::vec3 scale, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);
	void DrawCircleLine(glm::vec3 position, float radius, int segments, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);

	void DrawHPBar(std::string name, int health, int MaxHealth, glm::vec3 position, float angle, glm::vec3 scale, Color4f color = { 1.f, 1.f, 1.f, 1.f }, float depth = 0.f);

	Shader GetShader() { return renderer.GetShader(); }
	unsigned int GetVerticeHandle() { return renderer.GetVerticeHandle(); }
	std::map<std::string, Sprite> GetSpriteMap() { return sprites; }

	void SetBackGroundColor(Color4f color) { backGroundColor = color; }
private:
	Texture2D LoadImageFromFile(const char* file);
	std::map<std::string, Sprite> sprites;

	Renderer renderer;
	Color4f backGroundColor = { 1.f,1.f,1.f,1.f };
};