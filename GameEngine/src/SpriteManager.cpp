/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: SpriteManager.hpp
//Description: Source file for sprite manager class
/*-------------------------------------------------------*/
#include "SpriteManager.hpp"
#include "Instance.hpp"

#include "gl/glew.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Texture2D SpriteManager::LoadTexture(const char* file, std::string name)
{
	sprites[name].texture = LoadImageFromFile(file);
	sprites[name].isAnimated = false;
	sprites[name].animation.Initialize(1, 1, 1.f, renderer.GetShader(), false);
	return sprites[name].texture;
}

Texture2D SpriteManager::LoadAnimatedTexture(const char* file, std::string name, int column, int row, float speed, bool loop, bool isPaused)
{
	sprites[name].texture = LoadImageFromFile(file);
	sprites[name].isAnimated = true;
	sprites[name].animation.Initialize(column, row, speed, renderer.GetShader(), loop, isPaused);
	return sprites[name].texture;
}

Texture2D* SpriteManager::GetTexture(std::string name)
{
	return &sprites[name].texture;
}

Sprite* SpriteManager::GetSprite(std::string name)
{
	return &sprites[name];
}

void SpriteManager::DrawStart()
{
	GetShader().SendUniformVariable("view", Instance::GetCameraManager()->GetViewMatrix());
	GetShader().SendUniformVariable("projection", Instance::GetCameraManager()->GetProjectionMatrix());

	glClearColor(backGroundColor.red, backGroundColor.green, backGroundColor.blue, backGroundColor.alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);

}

void SpriteManager::DrawEnd()
{
	glFinish();
}

void SpriteManager::InitRenderer(const std::filesystem::path& vertexPath,
	const std::filesystem::path& fragmentPath)
{
	Shader temp(vertexPath, fragmentPath);

	renderer.SetShader(temp);
	renderer.initRenderData();
	renderer.initRectangleBar();
}

void SpriteManager::DrawSprite(std::string name, glm::vec3 position, float angle, glm::vec3 scale, Color4f color, float depth)
{
	if (GetSprite(name)->isAnimated == false)
	{
		renderer.DrawSprite(*GetTexture(name), position, scale, angle, color, depth);
	}
}

void SpriteManager::DrawSpriteWithAnimation(std::string name, float dt, glm::vec3 position, float angle, glm::vec3 scale, Color4f color, float depth)
{
	Sprite* s = GetSprite(name);
	if (s->isAnimated == true)
	{
		renderer.DrawSpriteWithAnimation(*s, dt, position, scale, angle, color, depth);
	}
}

void SpriteManager::DrawSpriteWithAnimation(std::string name, Animation& animation, float dt, glm::vec3 position, float angle, glm::vec3 scale, Color4f color, float depth)
{
	Sprite* s = GetSprite(name);
	if (s->isAnimated == true)
	{
		renderer.DrawSpriteWithAnimation(*s, animation, dt, position, scale, angle, color, depth);
	}
}

void SpriteManager::DrawRectangle(glm::vec3 position, float angle, glm::vec3 scale, Color4f color, float depth)
{
	renderer.DrawRectangle(position, scale, angle, color, depth);
}

void SpriteManager::DrawRectangleLine(glm::vec3 position, float angle, glm::vec3 scale, Color4f color, float depth)
{
	renderer.DrawRectangleLine(position, scale, angle, color, depth);
}

void SpriteManager::DrawCircleLine(glm::vec3 position, float radius, int segments, Color4f color, float depth)
{
	renderer.DrawCircleLine(position, radius, segments, color, depth);
}

void SpriteManager::DrawHPBar(std::string name, int health, int MaxHealth, glm::vec3 position, float angle, glm::vec3 scale, Color4f color, float depth)
{
	renderer.DrawHPBar(*GetTexture(name), health, MaxHealth, position, scale, angle, color, depth);
}

Texture2D SpriteManager::LoadImageFromFile(const char* file)
{
	Texture2D texture;

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(file, &width, &height, &nrChannels, STBI_rgb_alpha);

	texture.Generate(glm::vec2{ width, height }, data);
	stbi_image_free(data);
	return texture;
}
