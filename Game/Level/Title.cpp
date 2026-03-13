#include "Title.hpp"

#include <iostream>

void Title::Input()
{
	if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().UP))
	{
		if (index > 0)
		{
			index--;
		}
	}
	if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().DOWN))
	{
		if (index < 2)
		{
			index++;
		}
	}

	if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY1) || Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().START))
	{
		isSelected = true;
	}
}

void Title::Init()
{
	Instance::GetSpriteManager()->SetBackGroundColor({ 0.f,0.f,0.f,1.f });
	isSelected = false;
	index = 0;

	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(Instance::GetSpriteManager()->GetShader());
}

void Title::Update(float /*dt*/)
{
	switch (index)
	{
	case 0:
		text.DrawTextWithColor("GAME START", -64.f, -128.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
		text.DrawTextWithColor("OPTION", -45.f, -160.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("QUIT", -24.f, -192.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 1:
		text.DrawTextWithColor("GAME START", -64.f, -128.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("OPTION", -45.f, -160.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
		text.DrawTextWithColor("QUIT", -24.f, -192.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 2:
		text.DrawTextWithColor("GAME START", -64.f, -128.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("OPTION", -45.f, -160.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("QUIT", -24.f, -192.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
		break;
	}
	Input();
	if (isSelected == true)
	{
		switch (index)
		{
		case 0:
			Instance::GetLevelManager()->ChangeLevel(LevelType::SHOP);
			break;
		case 1:
			Instance::GetLevelManager()->ChangeLevel(LevelType::OPTION);
			break;
		case 2:
			Instance::GetLevelManager()->SetGameState(State::END);
			break;
		}
	}
}

void Title::Restart()
{
	End();
	Init();
}

void Title::End()
{
	Instance::GetCameraManager()->Reset();
	Instance::GetObjectManager()->DestroyAllObjects();
	Instance::GetParticleManager()->Clear();
	Instance::GetBackgroundManager()->Clear();
}
