#pragma once
#include "Texture/Animation.hpp"
#include "glm.hpp"
#include <string>
#include <map>
#include <vector>

enum BackgroundType
{
	NORMAL,
	TILE,
	VPARALLEX,
	NONE
};

struct Background
{
	std::string spriteName = "none";
	glm::vec2 position { 0.f,0.f };
	glm::vec2 speed{ 0.f,0.f };

	glm::vec2 size { 0.f,0.f };
	glm::vec2 sizeIncrements{ 0.f,0.f };
	float angle = 0.f;
	float depth = -1.f;
	BackgroundType type = BackgroundType::NORMAL;

	bool isDeleteWhenOut = false;
	bool isScrolled = true;
	size_t towerFloor = 0;

	int towerHeight = 0;

	Animation backgroundAnimation;
};

class BackgroundManager
{
public:
	BackgroundManager() {};
	~BackgroundManager() {};

	void AddNormalBackground(std::string spriteName_, glm::vec2 position_, glm::vec2 size_, float angle_ = 0.f, glm::vec2 speed_ = { 0.f,0.f }, glm::vec2 sizeIncrements_ = { 0.f,0.f }, float depth_ = -1.f, bool isScrolled_ = true);
	void AddNormalBackground(std::string spriteName_, glm::vec2 position_, glm::vec2 size_, glm::vec2 amount, float angle_ = 0.f, glm::vec2 speed_ = {0.f,0.f}, glm::vec2 sizeIncrements_ = {0.f,0.f}, float depth_ = -1.f, bool isScrolled_ = false);
	
	void AddTileBackground(std::string spriteName_, std::string groupName, glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float depth_ = -1.f, bool isScrolled_ = false);
	void AddVerticalParallexBackground(std::string spriteName_, std::string groupName, glm::vec2 position_, glm::vec2 size_, float angle_ = 0.f, float speedY_ = 0.f, float depth_ = -1.f, bool isScrolled_ = false);
	void AddHorizonParallexBackground(std::string spriteName_, std::string groupName, glm::vec2 position_, glm::vec2 size_, float angle_ = 0.f, float speedX_ = 0.f, float depth_ = -1.f, bool isScrolled_ = false);
	void AddSaveBackgroundList(std::string spriteName_, std::string groupName, BackgroundType type_, glm::vec2 position_, glm::vec2 size_, float angle_ = 0.f, glm::vec2 speed_ = { 0.f,0.f }, glm::vec2 sizeIncrements_ = { 0.f,0.f }, float depth_ = -1.f);
	
	void Update(float dt);
	void Clear();

	void SetTileBackGroundSpeed(std::string group_, glm::vec2 speed, bool isDeleteWhenOut_ = false);

	std::vector<Background> GetNormalBackgroundList() { return normalBackgroundList; }
	std::map<std::string, std::vector<Background>>  GetTileBackgroundList() { return tileBackgroundList; }
	std::map<std::string, std::vector<Background>>  GetVerticalParallaxBackgroundList() { return verticalParallaxBackgroundList; }

	std::map<std::string, std::vector<Background>>& GetSaveBackgroundList() { return saveBackgroundList; }
private:
	std::vector<Background> normalBackgroundList;
	std::map<std::string ,std::vector<Background>> tileBackgroundList;
	std::map<std::string, std::vector<Background>> verticalParallaxBackgroundList;

	std::map<std::string, std::vector<Background>> saveBackgroundList;
};