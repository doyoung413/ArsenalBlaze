#include "BackgroundManager.hpp"
#include "Instance.hpp"

bool isInOfCamera(Background& back)
{
	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x),
		static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	windowSize = (windowSize / Instance::GetCameraManager()->GetZoom());
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();
	if ((back.position.x - (back.size.x)) < (windowSize.x / 2.f + cameraCenter.x) && (back.position.x + (back.size.x)) > -(windowSize.x / 2.f - cameraCenter.x)
		&& (back.position.y - (back.size.y)) < (windowSize.y / 2.f + cameraCenter.y) && (back.position.y + (back.size.y)) > -(windowSize.y / 2.f - cameraCenter.y))
	{
		return true;
	}
	return false;
}

bool isInOfCameraE(Background& back)
{
	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x),
		static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	windowSize = (windowSize / Instance::GetCameraManager()->GetZoom());
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();

	if (back.position.x - (back.size.x) < (windowSize.x / 2.f + cameraCenter.x) && back.position.x + (back.size.x) > -(windowSize.x / 2.f - cameraCenter.x)
		&& back.position.y - (back.size.y) < (windowSize.y / 2.f + cameraCenter.y) && back.position.y + (back.size.y) > -(windowSize.y / 2.f - cameraCenter.y))
	{
		return true;
	}
	return false;
}

void BackgroundManager::AddNormalBackground(std::string spriteName_, glm::vec2 position_, glm::vec2 size_, float angle_, glm::vec2 speed_, glm::vec2 sizeIncrements_, float depth_, bool isScrolled_)
{
	Background temp;
	temp.spriteName = spriteName_;
	temp.position = position_;
	temp.size = size_;
	temp.speed = speed_;
	temp.angle = angle_;
	temp.sizeIncrements = sizeIncrements_;
	temp.depth = depth_;
	temp.isScrolled = isScrolled_;
	temp.type = BackgroundType::NORMAL;

	if (Instance::GetSpriteManager()->GetSprite(spriteName_)->isAnimated == true)
	{
		temp.backgroundAnimation = Instance::GetSpriteManager()->GetSprite(spriteName_)->animation;
	}

	normalBackgroundList.push_back(temp);
	saveBackgroundList["none"].push_back(temp);
}

void BackgroundManager::AddNormalBackground(std::string spriteName_, glm::vec2 position_, glm::vec2 size_, glm::vec2 amount, float angle_, glm::vec2 speed_, glm::vec2 sizeIncrements_, float depth_, bool isScrolled_)
{
	glm::vec2 startPosition = { position_.x, position_.y };
	for (int width = 0; width < amount.x; width++)
	{
		for (int height = 0; height < amount.y; height++)
		{
			AddNormalBackground(spriteName_, startPosition, size_,
				angle_, speed_, sizeIncrements_, depth_, isScrolled_);
			startPosition.y -= size_.y * 2.f;
		}
		startPosition.x += size_.x * 2.f;
		startPosition.y = position_.y;
	}
}


void BackgroundManager::AddTileBackground(std::string spriteName_, std::string groupName, glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float depth_, bool isScrolled_)
{
	Background saveb;
	saveb.spriteName = spriteName_;
	saveb.position = position_;
	saveb.size = size_;
	saveb.speed = speed_;
	saveb.sizeIncrements = { 0.f,0.f };
	saveb.depth = depth_;
	saveb.isScrolled = isScrolled_;
	saveb.type = BackgroundType::TILE;
	saveBackgroundList[groupName].push_back(saveb);

	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x) , static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	glm::vec2 amount{ 0,0 };
	glm::vec2 startPoint{ -(windowSize.x / 2.f) + size_.x, (windowSize.y / 2.f) + size_.y };
	amount.x = ((windowSize.x / (size_.x * 2.f)) + 1.f);
	amount.y = ((windowSize.y / (size_.y * 2.f)) + 1.f);
							   
	for (int y = 0; y <= amount.y; y++)
	{
		for (int x = 0; x < amount.x; x++)
		{
			Background temp;
			temp.spriteName = spriteName_;
			temp.position = { startPoint.x + (size_.x * 2.f * x), startPoint.y - (size_.y * 2.f * y) };
			temp.size = size_;
			temp.speed = speed_;
			temp.depth = depth_;
			temp.isScrolled = isScrolled_;
			temp.type = BackgroundType::TILE;

			if (Instance::GetSpriteManager()->GetSprite(spriteName_)->isAnimated == true)
			{
				temp.backgroundAnimation = Instance::GetSpriteManager()->GetSprite(spriteName_)->animation;
			}

			tileBackgroundList[groupName].push_back(temp);
		} //계산 구조 변경 필요
	}
}

void BackgroundManager::AddVerticalParallexBackground(std::string spriteName_, std::string groupName, glm::vec2 position_, glm::vec2 size_, float angle_, float speedY_, float depth_, bool isScrolled_)
{
	Background saveb;
	saveb.spriteName = spriteName_;
	saveb.position = position_;
	saveb.size = size_;
	saveb.speed = { 0.f, speedY_ };
	saveb.angle = angle_;
	saveb.sizeIncrements = { 0.f,0.f };
	saveb.depth = depth_;
	saveb.isScrolled = isScrolled_;
	saveb.type = BackgroundType::VPARALLEX;
	saveBackgroundList[groupName].push_back(saveb);

	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x) , static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	int amount = static_cast<int>(windowSize.y / (size_.y * 2.f)) + 1;
	if (windowSize.y < (size_.y * 2.f))
	{
		amount++;
	}
	float startPoint = position_.y;

	for (int y = 0; y < amount; y++)
	{
		Background temp;
		temp.spriteName = spriteName_;
		temp.position = { position_.x, startPoint - (size_.y * 2.f * y) };
		temp.size = size_;
		temp.speed.y = speedY_;
		temp.sizeIncrements = { 0.f,0.f };
		temp.depth = depth_;
		temp.isScrolled = isScrolled_;
		temp.type = BackgroundType::VPARALLEX;

		if (Instance::GetSpriteManager()->GetSprite(spriteName_)->isAnimated == true)
		{
			temp.backgroundAnimation = Instance::GetSpriteManager()->GetSprite(spriteName_)->animation;
		}

		verticalParallaxBackgroundList[groupName].push_back(temp);
	}

}

void BackgroundManager::AddHorizonParallexBackground(std::string spriteName_, std::string groupName, glm::vec2 position_, glm::vec2 size_, float angle_, float speedX_, float depth_, bool isScrolled_)
{
	Background saveb;
	saveb.spriteName = spriteName_;
	saveb.position = position_;
	saveb.size = size_;
	saveb.speed = { speedX_,0.f };
	saveb.angle = angle_;
	saveb.sizeIncrements = { 0.f,0.f };
	saveb.depth = depth_;
	saveb.isScrolled = isScrolled_;
	saveb.type = BackgroundType::NORMAL; // 수정필요
	saveBackgroundList[groupName].push_back(saveb);

	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x) , static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	int amount = static_cast<int>(windowSize.x / (size_.x * 2.f)) + 1;
	if (windowSize.x < (size_.x * 2.f))
	{
		amount++;
	}
	float startPoint = position_.x;

	for (int x = 0; x < amount; x++)
	{
		Background temp;
		temp.spriteName = spriteName_;
		temp.position = { startPoint + (size_.x * 2.f * x), position_.y };
		temp.size = size_;
		temp.speed.x = speedX_;
		temp.sizeIncrements = { 0.f,0.f };
		temp.depth = depth_;
		temp.isScrolled = isScrolled_;
		temp.type = BackgroundType::NORMAL;

		if (Instance::GetSpriteManager()->GetSprite(spriteName_)->isAnimated == true)
		{
			temp.backgroundAnimation = Instance::GetSpriteManager()->GetSprite(spriteName_)->animation;
		}

		normalBackgroundList.push_back(temp);
	}

}

void BackgroundManager::AddSaveBackgroundList(std::string spriteName_, std::string groupName, BackgroundType type_, glm::vec2 position_, glm::vec2 size_, float angle_, glm::vec2 speed_, glm::vec2 sizeIncrements_, float depth_)
{
	Background temp;
	temp.spriteName = spriteName_;
	temp.position = position_;
	temp.size = size_;
	temp.speed = speed_;
	temp.angle = angle_;
	temp.sizeIncrements = sizeIncrements_;
	temp.depth = depth_;
	temp.type = type_;

	if (Instance::GetSpriteManager()->GetSprite(spriteName_)->isAnimated == true)
	{
		temp.backgroundAnimation = Instance::GetSpriteManager()->GetSprite(spriteName_)->animation;
	}

	saveBackgroundList[groupName].push_back(temp);
}

void BackgroundManager::Update(float dt)
{
	if (Instance::GetGameManager()->GetGameMode() != GameMode::EDITOR)
	{
		for (auto& group : tileBackgroundList)
		{
			for (int i = 0; i < group.second.size(); i++)
			{
				if (isInOfCamera(group.second.at(i)) == true)
				{
					if (Instance::GetSpriteManager()->GetSprite(group.second.at(i).spriteName)->isAnimated == true)
					{
						Instance::GetSpriteManager()->DrawSpriteWithAnimation(group.second.at(i).spriteName, group.second.at(i).backgroundAnimation, dt, { group.second.at(i).position, 0.f }, group.second.at(i).angle, {group.second.at(i).size, 0.f}, { 1.f,1.f,1.f,1.f }, group.second.at(i).depth);
					}
					else
					{
						Instance::GetSpriteManager()->DrawSprite(group.second.at(i).spriteName, {group.second.at(i).position, 0.f}, group.second.at(i).angle, {group.second.at(i).size, 0.f}, { 1.f,1.f,1.f,1.f }, group.second.at(i).depth);
					}
				}

				if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
				{
					group.second.at(i).position.y -= group.second.at(i).speed.y * dt;
				}

				if (group.second.at(i).position.y <= -(Instance::GetCameraManager()->GetViewSize().y / 2.f)
					+ Instance::GetCameraManager()->GetCenter().y - group.second.at(i).size.y)
				{
					if (group.second.at(i).isDeleteWhenOut == false)
					{
						group.second.at(i).position.y = Instance::GetCameraManager()->GetViewSize().y / 2.f + group.second.at(i).size.y + Instance::GetCameraManager()->GetCenter().y;
					}
					else
					{
						group.second.erase(group.second.begin() + i);
					}
				}
			}
		}

		for (auto& group : verticalParallaxBackgroundList)
		{
			for (auto& parallax : group.second)
			{
				//Instance::GetSpriteManager()->DrawSprite(parallax.spriteName, parallax.position, 0.f, parallax.size, { 1.f,1.f,1.f,1.f }, parallax.depth);

				if (isInOfCamera(parallax) == true)
				{
					if (Instance::GetSpriteManager()->GetSprite(parallax.spriteName)->isAnimated == true)
					{
						Instance::GetSpriteManager()->DrawSpriteWithAnimation(parallax.spriteName, parallax.backgroundAnimation, dt, { parallax.position, 0.f }, parallax.angle, {parallax.size, 0.f}, { 1.f,1.f,1.f,1.f }, parallax.depth);
					}
					else
					{
						Instance::GetSpriteManager()->DrawSprite(parallax.spriteName, {parallax.position, 0.f}, parallax.angle, {parallax.size, 0.f}, { 1.f,1.f,1.f,1.f }, parallax.depth);
					}
				}

				if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
				{
					parallax.position.y -= parallax.speed.y * dt;
				}
				if (parallax.position.y <= -(Instance::GetCameraManager()->GetViewSize().y / 2.f)
					+ Instance::GetCameraManager()->GetCenter().y - parallax.size.y)
				{
					parallax.position.y = Instance::GetCameraManager()->GetViewSize().y / 2.f + parallax.size.y + Instance::GetCameraManager()->GetCenter().y;
				}
			}
		}

		for (auto& background : normalBackgroundList)
		{
			if (background.isScrolled == false)
			{
				background.position.x += background.speed.x * dt;
				background.position.y -= background.speed.y * dt;
			}
			if (isInOfCamera(background) == true)
			{
				if (background.isScrolled == true)
				{
					background.position.x += background.speed.x * dt;
					background.position.y -= background.speed.y * dt;
				}
				if (Instance::GetSpriteManager()->GetSprite(background.spriteName)->isAnimated == true)
				{
					Instance::GetSpriteManager()->DrawSpriteWithAnimation(background.spriteName, background.backgroundAnimation, dt, { background.position, 0.f }, background.angle, { background.size, 0.f }, { 1.f,1.f,1.f,1.f }, background.depth);
				}
				else
				{
					Instance::GetSpriteManager()->DrawSprite(background.spriteName, {background.position, 0.f}, background.angle, {background.size, 0.f}, { 1.f,1.f,1.f,1.f }, background.depth);
				}
			}

			if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
			{
				if (background.isScrolled == true)
				{
					background.position.x += Instance::GetGameManager()->GetScrollSpeed().x * dt;
					background.position.y += Instance::GetGameManager()->GetScrollSpeed().y * dt;
				}
			}
		}
	}
	else
	{
		for (auto& group : saveBackgroundList)
		{
			for (auto& background : group.second)
			{
				if (isInOfCameraE(background))
				{
					if (Instance::GetSpriteManager()->GetSprite(background.spriteName)->isAnimated == true)
					{
						Instance::GetSpriteManager()->DrawSpriteWithAnimation(background.spriteName, background.backgroundAnimation, dt, {background.position, 0.f}, background.angle, {background.size, 0.f}, { 1.f,1.f,1.f,1.f }, background.depth);
					}
					else
					{
						Instance::GetSpriteManager()->DrawSprite(background.spriteName, {background.position, 0.f}, background.angle, {background.size, 0.f}, { 1.f,1.f,1.f,1.f }, background.depth);
					}
				}
			}
		}
	}
}

void BackgroundManager::Clear()
{
	normalBackgroundList.clear();
	tileBackgroundList.clear();
	verticalParallaxBackgroundList.clear();
	saveBackgroundList.clear();
}

void BackgroundManager::SetTileBackGroundSpeed(std::string group_, glm::vec2 speed, bool isDeleteWhenOut_)
{
	for (auto& group : tileBackgroundList)
	{
		if (group.first == group_)
		{
			for (auto& tile : group.second)
			{
				tile.speed = speed;
				tile.isDeleteWhenOut = isDeleteWhenOut_;
			}
		}
	}
}
