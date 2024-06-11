/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: InputManagers.hpp
//Description: Header file for input device management
/*-------------------------------------------------------*/
#pragma once
#include "InputKeys.hpp"
#include "glm.hpp"

#include <iostream>
#include <unordered_map>

class CameraManager;
class InputManager
{
public:
	InputManager();
	~InputManager();

	void FindAndAddController();

	void InputPollEvent(SDL_Event& event);

	bool IsKeyPressed(KEYBOARDKEYS keycode);
	bool IsKeyPressOnce(KEYBOARDKEYS keycode);

	bool IsMouseButtonPressed(MOUSEBUTTON button);
	bool IsMouseButtonPressOnce(MOUSEBUTTON button);
	glm::vec2 GetMousePosition();

	bool IsGamepadButtonPressed(GAMEPADBUTTONS button);
	bool IsGamepadButtonPressOnce(GAMEPADBUTTONS button);

	KEYBOARDKEYS KeyBoardToEnum(std::string key);
	std::string KeyBoardToString(KEYBOARDKEYS key);
	KEYBOARDKEYS GetPressKey();

	GAMEPADBUTTONS GamePadToEnum(std::string key);
	std::string GamePadToString(GAMEPADBUTTONS key);
	GAMEPADBUTTONS GetPressGamePadButton();
protected:
	void KeyDown(KEYBOARDKEYS keycode)
	{
		SetKeyState(keycode, true);
	}

	void KeyUp(KEYBOARDKEYS keycode)
	{
		SetKeyState(keycode, false);
	}

	void MouseButtonDown(MOUSEBUTTON button, int /*x*/, int /*y*/)
	{
		SetMouseButtonState(button, true);
	}

	void MouseButtonUp(MOUSEBUTTON button, int /*x*/, int /*y*/)
	{
		SetMouseButtonState(button, false);
	}

	void SetKeyState(KEYBOARDKEYS keycode, bool state)
	{
		keyStates[keycode] = state;
	}

	void SetMouseButtonState(MOUSEBUTTON button, bool state)
	{
		mouseButtonStates[button] = state;
	}

	void GamepadButtonDown(GAMEPADBUTTONS button)
	{
		SetGamepadButtonState(button, true);
	}

	void GamepadButtonUp(GAMEPADBUTTONS button)
	{
		SetGamepadButtonState(button, false);
	}

	void SetGamepadButtonState(GAMEPADBUTTONS button, bool state)
	{
		gamepadButtonStates[button] = state;
	}

	bool IsGamepadConnected()
	{
		return (gamepad != nullptr);
	}

private:
	std::unordered_map<KEYBOARDKEYS, bool> keyStates;
	std::unordered_map<KEYBOARDKEYS, bool> keyStatePrev;

	std::unordered_map<MOUSEBUTTON, bool> mouseButtonStates;
	std::unordered_map<MOUSEBUTTON, bool> mouseButtonStatePrev;

	std::unordered_map<GAMEPADBUTTONS, bool> gamepadButtonStates;
	std::unordered_map<GAMEPADBUTTONS, bool> gamepadButtonStatePrev;

	SDL_GameController* gamepad = nullptr;
};