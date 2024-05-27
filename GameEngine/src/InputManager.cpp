/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: InputManagers.cpp
//Description: Source file for input device management
/*-------------------------------------------------------*/
#include "InputManager.hpp"
#include "Instance.hpp"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
	if (gamepad != nullptr)
	{
		SDL_GameControllerClose(gamepad);
		gamepad = nullptr;
	}
}

void InputManager::FindAndAddController()
{
	int numJoysticks = SDL_NumJoysticks();
	for (int i = 0; i < numJoysticks; i++)
	{
		if (SDL_IsGameController(i))
		{
			gamepad = SDL_GameControllerOpen(i);
			std::cout << SDL_GameControllerMapping(gamepad) << std::endl;
		}
	}

	if (gamepad == nullptr)
	{
		std::cout << "game controller not found" << std::endl;
	}
}

void InputManager::InputPollEvent(SDL_Event& event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		KeyDown(static_cast<KEYBOARDKEYS>(event.key.keysym.sym));
		break;
	case SDL_KEYUP:
		KeyUp(static_cast<KEYBOARDKEYS>(event.key.keysym.sym));
		break;
	case SDL_MOUSEBUTTONDOWN:
		MouseButtonDown(static_cast<MOUSEBUTTON>(event.button.button), event.button.x, event.button.y);
		break;
	case SDL_MOUSEBUTTONUP:
		MouseButtonUp(static_cast<MOUSEBUTTON>(event.button.button), event.button.x, event.button.y);
		break;
	case SDL_CONTROLLERBUTTONDOWN:
		GamepadButtonDown(static_cast<GAMEPADBUTTONS>(event.cbutton.button));
		break;
	case SDL_CONTROLLERBUTTONUP:
		GamepadButtonUp(static_cast<GAMEPADBUTTONS>(event.cbutton.button));
		break;
	default:
		break;
	}
}

bool InputManager::IsKeyPressed(KEYBOARDKEYS keycode)
{
	auto it = keyStates.find(keycode);
	if (it != keyStates.end())
	{
		keyStatePrev[keycode] = it->second;
		return it->second;
	}
	return false;
}

bool InputManager::IsKeyPressOnce(KEYBOARDKEYS keycode)
{
	auto it = keyStates.find(keycode);
	if (it != keyStates.end())
	{
		bool isPressed = it->second && !keyStatePrev[keycode];
		keyStatePrev[keycode] = it->second;
		return isPressed;
	}
	return false;
}

bool InputManager::IsMouseButtonPressed(MOUSEBUTTON button)
{
	auto it = mouseButtonStates.find(button);
	if (it != mouseButtonStates.end())
	{
		mouseButtonStatePrev[button] = it->second;
		return it->second;
	}
	return false;
}

bool InputManager::IsMouseButtonPressOnce(MOUSEBUTTON button)
{
	auto it = mouseButtonStates.find(button);
	if (it != mouseButtonStates.end())
	{
		bool isPressed = it->second && !mouseButtonStatePrev[button];
		mouseButtonStatePrev[button] = it->second;
		return isPressed;
	}
	return false;
}

glm::vec2 InputManager::GetMousePosition()
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	glm::vec2 pos = { mouseX, mouseY };
	glm::vec2 windowViewSize = Instance::GetCameraManager()->GetViewSize();
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(Instance::GetWindow()->GetWindow(), &w, &h);
	float zoom = Instance::GetCameraManager()->GetZoom();

	pos = { windowViewSize.x / 2.f * (pos.x / (static_cast<float>(w) / 2.f) - 1) / zoom, -(windowViewSize.y / 2.f * (pos.y / (static_cast<float>(h) / 2.f) - 1) / zoom) };
	return ceil(pos);
}

bool InputManager::IsGamepadButtonPressed(GAMEPADBUTTONS button)
{
	auto it = gamepadButtonStates.find(button);
	if (it != gamepadButtonStates.end())
	{
		gamepadButtonStatePrev[button] = it->second;
		return it->second;
	}
	return false;
}

bool InputManager::IsGamepadButtonPressOnce(GAMEPADBUTTONS button)
{
	auto it = gamepadButtonStates.find(button);
	if (it != gamepadButtonStates.end())
	{
		bool isPressed = it->second && !gamepadButtonStatePrev[button];
		gamepadButtonStatePrev[button] = it->second;
		return isPressed;
	}
	return false;
}

KEYBOARDKEYS InputManager::GetPressKey()
{
	if (IsKeyPressed(KEYBOARDKEYS::ENTER))
		return KEYBOARDKEYS::ENTER;
	if (IsKeyPressed(KEYBOARDKEYS::ESCAPE))
		return KEYBOARDKEYS::ESCAPE;
	if (IsKeyPressed(KEYBOARDKEYS::BACKSPACE))
		return KEYBOARDKEYS::BACKSPACE;
	if (IsKeyPressed(KEYBOARDKEYS::TAB))
		return KEYBOARDKEYS::TAB;
	if (IsKeyPressed(KEYBOARDKEYS::SPACE))
		return KEYBOARDKEYS::SPACE;
	if (IsKeyPressed(KEYBOARDKEYS::EXCLAIM))
		return KEYBOARDKEYS::EXCLAIM;
	if (IsKeyPressed(KEYBOARDKEYS::QUOTEDBL))
		return KEYBOARDKEYS::QUOTEDBL;
	if (IsKeyPressed(KEYBOARDKEYS::HASH))
		return KEYBOARDKEYS::HASH;
	if (IsKeyPressed(KEYBOARDKEYS::PERCENT))
		return KEYBOARDKEYS::PERCENT;
	if (IsKeyPressed(KEYBOARDKEYS::DOLLAR))
		return KEYBOARDKEYS::DOLLAR;
	if (IsKeyPressed(KEYBOARDKEYS::AMPERSAND))
		return KEYBOARDKEYS::AMPERSAND;
	if (IsKeyPressed(KEYBOARDKEYS::QUOTE))
		return KEYBOARDKEYS::QUOTE;
	if (IsKeyPressed(KEYBOARDKEYS::LEFTPAREN))
		return KEYBOARDKEYS::LEFTPAREN;
	if (IsKeyPressed(KEYBOARDKEYS::RIGHTPAREN))
		return KEYBOARDKEYS::RIGHTPAREN;
	if (IsKeyPressed(KEYBOARDKEYS::ASTERISK))
		return KEYBOARDKEYS::ASTERISK;
	if (IsKeyPressed(KEYBOARDKEYS::PLUS))
		return KEYBOARDKEYS::PLUS;
	if (IsKeyPressed(KEYBOARDKEYS::COMMA))
		return KEYBOARDKEYS::COMMA;
	if (IsKeyPressed(KEYBOARDKEYS::MINUS))
		return KEYBOARDKEYS::MINUS;
	if (IsKeyPressed(KEYBOARDKEYS::PERIOD))
		return KEYBOARDKEYS::PERIOD;
	if (IsKeyPressed(KEYBOARDKEYS::SLASH))
		return KEYBOARDKEYS::SLASH;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_0))
		return KEYBOARDKEYS::NUMBER_0;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_1))
		return KEYBOARDKEYS::NUMBER_1;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_2))
		return KEYBOARDKEYS::NUMBER_2;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_3))
		return KEYBOARDKEYS::NUMBER_3;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_4))
		return KEYBOARDKEYS::NUMBER_4;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_5))
		return KEYBOARDKEYS::NUMBER_5;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_6))
		return KEYBOARDKEYS::NUMBER_6;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_7))
		return KEYBOARDKEYS::NUMBER_7;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_8))
		return KEYBOARDKEYS::NUMBER_8;
	if (IsKeyPressed(KEYBOARDKEYS::NUMBER_9))
		return KEYBOARDKEYS::NUMBER_9;
	if (IsKeyPressed(KEYBOARDKEYS::COLON))
		return KEYBOARDKEYS::COLON;
	if (IsKeyPressed(KEYBOARDKEYS::SEMICOLON))
		return KEYBOARDKEYS::SEMICOLON;
	if (IsKeyPressed(KEYBOARDKEYS::LESS))
		return KEYBOARDKEYS::LESS;
	if (IsKeyPressed(KEYBOARDKEYS::EQUALS))
		return KEYBOARDKEYS::EQUALS;
	if (IsKeyPressed(KEYBOARDKEYS::GREATER))
		return KEYBOARDKEYS::GREATER;
	if (IsKeyPressed(KEYBOARDKEYS::QUESTION))
		return KEYBOARDKEYS::QUESTION;
	if (IsKeyPressed(KEYBOARDKEYS::AT))
		return KEYBOARDKEYS::AT;
	if (IsKeyPressed(KEYBOARDKEYS::LEFTBRACKET))
		return KEYBOARDKEYS::LEFTBRACKET;
	if (IsKeyPressed(KEYBOARDKEYS::BACKSLASH))
		return KEYBOARDKEYS::BACKSLASH;
	if (IsKeyPressed(KEYBOARDKEYS::RIGHTBRACKET))
		return KEYBOARDKEYS::RIGHTBRACKET;
	if (IsKeyPressed(KEYBOARDKEYS::CARET))
		return KEYBOARDKEYS::CARET;
	if (IsKeyPressed(KEYBOARDKEYS::UNDERSCORE))
		return KEYBOARDKEYS::UNDERSCORE;
	if (IsKeyPressed(KEYBOARDKEYS::BACKQUOTE))
		return KEYBOARDKEYS::BACKQUOTE;
	if (IsKeyPressed(KEYBOARDKEYS::A))
		return KEYBOARDKEYS::A;
	if (IsKeyPressed(KEYBOARDKEYS::B))
		return KEYBOARDKEYS::B;
	if (IsKeyPressed(KEYBOARDKEYS::C))
		return KEYBOARDKEYS::C;
	if (IsKeyPressed(KEYBOARDKEYS::D))
		return KEYBOARDKEYS::D;
	if (IsKeyPressed(KEYBOARDKEYS::E))
		return KEYBOARDKEYS::E;
	if (IsKeyPressed(KEYBOARDKEYS::F))
		return KEYBOARDKEYS::F;
	if (IsKeyPressed(KEYBOARDKEYS::G))
		return KEYBOARDKEYS::G;
	if (IsKeyPressed(KEYBOARDKEYS::H))
		return KEYBOARDKEYS::H;
	if (IsKeyPressed(KEYBOARDKEYS::I))
		return KEYBOARDKEYS::I;
	if (IsKeyPressed(KEYBOARDKEYS::J))
		return KEYBOARDKEYS::J;
	if (IsKeyPressed(KEYBOARDKEYS::K))
		return KEYBOARDKEYS::K;
	if (IsKeyPressed(KEYBOARDKEYS::L))
		return KEYBOARDKEYS::L;
	if (IsKeyPressed(KEYBOARDKEYS::M))
		return KEYBOARDKEYS::M;
	if (IsKeyPressed(KEYBOARDKEYS::N))
		return KEYBOARDKEYS::N;
	if (IsKeyPressed(KEYBOARDKEYS::O))
		return KEYBOARDKEYS::O;
	if (IsKeyPressed(KEYBOARDKEYS::P))
		return KEYBOARDKEYS::P;
	if (IsKeyPressed(KEYBOARDKEYS::Q))
		return KEYBOARDKEYS::Q;
	if (IsKeyPressed(KEYBOARDKEYS::R))
		return KEYBOARDKEYS::R;
	if (IsKeyPressed(KEYBOARDKEYS::S))
		return KEYBOARDKEYS::S;
	if (IsKeyPressed(KEYBOARDKEYS::T))
		return KEYBOARDKEYS::T;
	if (IsKeyPressed(KEYBOARDKEYS::U))
		return KEYBOARDKEYS::U;
	if (IsKeyPressed(KEYBOARDKEYS::V))
		return KEYBOARDKEYS::V;
	if (IsKeyPressed(KEYBOARDKEYS::W))
		return KEYBOARDKEYS::W;
	if (IsKeyPressed(KEYBOARDKEYS::X))
		return KEYBOARDKEYS::X;
	if (IsKeyPressed(KEYBOARDKEYS::Y))
		return KEYBOARDKEYS::Y;
	if (IsKeyPressed(KEYBOARDKEYS::Z))
		return KEYBOARDKEYS::Z;
	if (IsKeyPressed(KEYBOARDKEYS::CAPSLOCK))
		return KEYBOARDKEYS::CAPSLOCK;
	if (IsKeyPressed(KEYBOARDKEYS::F1))
		return KEYBOARDKEYS::F1;
	if (IsKeyPressed(KEYBOARDKEYS::F2))
		return KEYBOARDKEYS::F2;
	if (IsKeyPressed(KEYBOARDKEYS::F3))
		return KEYBOARDKEYS::F3;
	if (IsKeyPressed(KEYBOARDKEYS::F4))
		return KEYBOARDKEYS::F4;
	if (IsKeyPressed(KEYBOARDKEYS::F5))
		return KEYBOARDKEYS::F5;
	if (IsKeyPressed(KEYBOARDKEYS::F6))
		return KEYBOARDKEYS::F6;
	if (IsKeyPressed(KEYBOARDKEYS::F7))
		return KEYBOARDKEYS::F7;
	if (IsKeyPressed(KEYBOARDKEYS::F8))
		return KEYBOARDKEYS::F8;
	if (IsKeyPressed(KEYBOARDKEYS::F9))
		return KEYBOARDKEYS::F9;
	if (IsKeyPressed(KEYBOARDKEYS::F10))
		return KEYBOARDKEYS::F10;
	if (IsKeyPressed(KEYBOARDKEYS::F11))
		return KEYBOARDKEYS::F11;
	if (IsKeyPressed(KEYBOARDKEYS::F12))
		return KEYBOARDKEYS::F12;
	if (IsKeyPressed(KEYBOARDKEYS::PRINTSCREEN))
		return KEYBOARDKEYS::PRINTSCREEN;
	if (IsKeyPressed(KEYBOARDKEYS::SCROLLLOCK))
		return KEYBOARDKEYS::SCROLLLOCK;
	if (IsKeyPressed(KEYBOARDKEYS::PAUSE))
		return KEYBOARDKEYS::PAUSE;
	if (IsKeyPressed(KEYBOARDKEYS::INSERT))
		return KEYBOARDKEYS::INSERT;
	if (IsKeyPressed(KEYBOARDKEYS::HOME))
		return KEYBOARDKEYS::HOME;
	if (IsKeyPressed(KEYBOARDKEYS::PAGEUP))
		return KEYBOARDKEYS::PAGEUP;
	if (IsKeyPressed(KEYBOARDKEYS::DELETE_KEY))
		return KEYBOARDKEYS::DELETE_KEY;
	if (IsKeyPressed(KEYBOARDKEYS::UNLOAD))
		return KEYBOARDKEYS::UNLOAD;
	if (IsKeyPressed(KEYBOARDKEYS::PAGEDOWN))
		return KEYBOARDKEYS::PAGEDOWN;
	if (IsKeyPressed(KEYBOARDKEYS::RIGHT))
		return KEYBOARDKEYS::RIGHT;
	if (IsKeyPressed(KEYBOARDKEYS::LEFT))
		return KEYBOARDKEYS::LEFT;
	if (IsKeyPressed(KEYBOARDKEYS::DOWN))
		return KEYBOARDKEYS::DOWN;
	if (IsKeyPressed(KEYBOARDKEYS::UP))
		return KEYBOARDKEYS::UP;
	if (IsKeyPressed(KEYBOARDKEYS::NUMLOCKCLEAR))
		return KEYBOARDKEYS::NUMLOCKCLEAR;
	if (IsKeyPressed(KEYBOARDKEYS::KP_DIVIDE))
		return KEYBOARDKEYS::KP_DIVIDE;
	if (IsKeyPressed(KEYBOARDKEYS::KP_MULTIPLY))
		return KEYBOARDKEYS::KP_MULTIPLY;
	if (IsKeyPressed(KEYBOARDKEYS::KP_MINUS))
		return KEYBOARDKEYS::KP_MINUS;
	if (IsKeyPressed(KEYBOARDKEYS::KP_PLUS))
		return KEYBOARDKEYS::KP_PLUS;
	if (IsKeyPressed(KEYBOARDKEYS::KP_ENTER))
		return KEYBOARDKEYS::KP_ENTER;
	if (IsKeyPressed(KEYBOARDKEYS::KP_1))
		return KEYBOARDKEYS::KP_1;
	if (IsKeyPressed(KEYBOARDKEYS::KP_2))
		return KEYBOARDKEYS::KP_2;
	if (IsKeyPressed(KEYBOARDKEYS::KP_3))
		return KEYBOARDKEYS::KP_3;
	if (IsKeyPressed(KEYBOARDKEYS::KP_4))
		return KEYBOARDKEYS::KP_4;
	if (IsKeyPressed(KEYBOARDKEYS::KP_5))
		return KEYBOARDKEYS::KP_5;
	if (IsKeyPressed(KEYBOARDKEYS::KP_6))
		return KEYBOARDKEYS::KP_6;
	if (IsKeyPressed(KEYBOARDKEYS::KP_7))
		return KEYBOARDKEYS::KP_7;
	if (IsKeyPressed(KEYBOARDKEYS::KP_8))
		return KEYBOARDKEYS::KP_8;
	if (IsKeyPressed(KEYBOARDKEYS::KP_9))
		return KEYBOARDKEYS::KP_9;
	if (IsKeyPressed(KEYBOARDKEYS::KP_0))
		return KEYBOARDKEYS::KP_0;
	if (IsKeyPressed(KEYBOARDKEYS::KP_PERIOD))
		return KEYBOARDKEYS::KP_PERIOD;
	if (IsKeyPressed(KEYBOARDKEYS::LCTRL))
		return KEYBOARDKEYS::LCTRL;
	if (IsKeyPressed(KEYBOARDKEYS::LSHIFT))
		return KEYBOARDKEYS::LSHIFT;
	if (IsKeyPressed(KEYBOARDKEYS::LALT))
		return KEYBOARDKEYS::LALT;
	if (IsKeyPressed(KEYBOARDKEYS::LGUI))
		return KEYBOARDKEYS::LGUI;
	if (IsKeyPressed(KEYBOARDKEYS::RCTRL))
		return KEYBOARDKEYS::RCTRL;
	if (IsKeyPressed(KEYBOARDKEYS::RSHIFT))
		return KEYBOARDKEYS::RSHIFT;
	if (IsKeyPressed(KEYBOARDKEYS::RALT))
		return KEYBOARDKEYS::RALT;
	if (IsKeyPressed(KEYBOARDKEYS::RGUI))
		return KEYBOARDKEYS::RGUI;
	if (IsKeyPressed(KEYBOARDKEYS::MODE))
		return KEYBOARDKEYS::MODE;

	return KEYBOARDKEYS::UNKNOWN;
}

KEYBOARDKEYS InputManager::KeyBoardToEnum(std::string key)
{

	if (key == "ENTER")
		return KEYBOARDKEYS::ENTER;

	if (key == "ESCAPE")
		return KEYBOARDKEYS::ESCAPE;

	if (key == "BACKSPACE")
		return KEYBOARDKEYS::BACKSPACE;

	if (key == "TAB")
		return KEYBOARDKEYS::TAB;

	if (key == "SPACE")
		return KEYBOARDKEYS::SPACE;

	if (key == "EXCLAIM")
		return KEYBOARDKEYS::EXCLAIM;

	if (key == "QUOTEDBL")
		return KEYBOARDKEYS::QUOTEDBL;

	if (key == "HASH")
		return KEYBOARDKEYS::HASH;

	if (key == "PERCENT")
		return KEYBOARDKEYS::PERCENT;

	if (key == "DOLLAR")
		return KEYBOARDKEYS::DOLLAR;

	if (key == "AMPERSAND")
		return KEYBOARDKEYS::AMPERSAND;

	if (key == "QUOTE")
		return KEYBOARDKEYS::QUOTE;

	if (key == "LEFTPAREN")
		return KEYBOARDKEYS::LEFTPAREN;

	if (key == "RIGHTPAREN")
		return KEYBOARDKEYS::RIGHTPAREN;

	if (key == "ASTERISK")
		return KEYBOARDKEYS::ASTERISK;

	if (key == "PLUS")
		return KEYBOARDKEYS::PLUS;

	if (key == ("MINUS"))
		return KEYBOARDKEYS::MINUS;

	if (key == ("COMMA"))
		return KEYBOARDKEYS::COMMA;

	if (key == "PERIOD")
		return KEYBOARDKEYS::PERIOD;

	if (key == "SLASH")
		return KEYBOARDKEYS::SLASH;

	if (key == "NUMBER_0")
		return KEYBOARDKEYS::NUMBER_0;

	if (key == "NUMBER_1")
		return KEYBOARDKEYS::NUMBER_1;

	if (key == "NUMBER_2")
		return KEYBOARDKEYS::NUMBER_2;

	if (key == "NUMBER_3")
		return KEYBOARDKEYS::NUMBER_3;

	if (key == "NUMBER_4")
		return KEYBOARDKEYS::NUMBER_4;

	if (key == "NUMBER_5")
		return KEYBOARDKEYS::NUMBER_5;

	if (key == "NUMBER_6")
		return KEYBOARDKEYS::NUMBER_6;

	if (key == "NUMBER_7")
		return KEYBOARDKEYS::NUMBER_7;

	if (key == "NUMBER_8")
		return KEYBOARDKEYS::NUMBER_8;

	if (key == "NUMBER_9")
		return KEYBOARDKEYS::NUMBER_9;

	if (key == "COLON")
		return KEYBOARDKEYS::COLON;

	if (key == "SEMICOLON")
		return KEYBOARDKEYS::SEMICOLON;

	if (key == "LESS")
		return KEYBOARDKEYS::LESS;

	if (key == "EQUALS")
		return KEYBOARDKEYS::EQUALS;

	if (key == "GREATER")
		return KEYBOARDKEYS::GREATER;

	if (key == "QUESTION")
		return KEYBOARDKEYS::QUESTION;

	if (key == "AT")
		return KEYBOARDKEYS::AT;

	if (key == "LEFTBRACKET")
		return KEYBOARDKEYS::LEFTBRACKET;

	if (key == "BACKSLASH")
		return KEYBOARDKEYS::BACKSLASH;

	if (key == "RIGHTBRACKET")
		return KEYBOARDKEYS::RIGHTBRACKET;

	if (key == "CARET")
		return KEYBOARDKEYS::CARET;

	if (key == "UNDERSCORE")
		return KEYBOARDKEYS::UNDERSCORE;

	if (key == "BACKQUOTE")
		return KEYBOARDKEYS::BACKQUOTE;

	if (key == "A")
		return KEYBOARDKEYS::A;

	if (key == "B")
		return KEYBOARDKEYS::B;

	if (key == "C")
		return KEYBOARDKEYS::C;

	if (key == "D")
		return KEYBOARDKEYS::D;

	if (key == "E")
		return KEYBOARDKEYS::E;

	if (key == "F")
		return KEYBOARDKEYS::F;

	if (key == "G")
		return KEYBOARDKEYS::G;

	if (key == "H")
		return KEYBOARDKEYS::H;

	if (key == "I")
		return KEYBOARDKEYS::I;

	if (key == "J")
		return KEYBOARDKEYS::J;

	if (key == "K")
		return KEYBOARDKEYS::K;

	if (key == "L")
		return KEYBOARDKEYS::L;

	if (key == "M")
		return KEYBOARDKEYS::M;

	if (key == "N")
		return KEYBOARDKEYS::N;

	if (key == "O")
		return KEYBOARDKEYS::O;

	if (key == "P")
		return KEYBOARDKEYS::P;

	if (key == "Q")
		return KEYBOARDKEYS::Q;

	if (key == "R")
		return KEYBOARDKEYS::R;

	if (key == "S")
		return KEYBOARDKEYS::S;

	if (key == "T")
		return KEYBOARDKEYS::T;

	if (key == "U")
		return KEYBOARDKEYS::U;

	if (key == "V")
		return KEYBOARDKEYS::V;

	if (key == "W")
		return KEYBOARDKEYS::W;

	if (key == "X")
		return KEYBOARDKEYS::X;

	if (key == "Y")
		return KEYBOARDKEYS::Y;

	if (key == "Z")
		return KEYBOARDKEYS::Z;

	if (key == "CAPSLOCK")
		return KEYBOARDKEYS::CAPSLOCK;

	if (key == "F1")
		return KEYBOARDKEYS::F1;

	if (key == "F2")
		return KEYBOARDKEYS::F2;

	if (key == "F3")
		return KEYBOARDKEYS::F3;

	if (key == "F4")
		return KEYBOARDKEYS::F4;

	if (key == "F5")
		return KEYBOARDKEYS::F5;

	if (key == "F6")
		return KEYBOARDKEYS::F6;

	if (key == "F7")
		return KEYBOARDKEYS::F7;

	if (key == "F8")
		return KEYBOARDKEYS::F8;

	if (key == "F9")
		return KEYBOARDKEYS::F9;

	if (key == "F10")
		return KEYBOARDKEYS::F10;

	if (key == "F11")
		return KEYBOARDKEYS::F11;

	if (key == "F12")
		return KEYBOARDKEYS::F12;

	if (key == "PRINTSCREEN")
		return KEYBOARDKEYS::PRINTSCREEN;

	if (key == "SCROLLLOCK")
		return KEYBOARDKEYS::SCROLLLOCK;

	if (key == "PAUSE")
		return KEYBOARDKEYS::PAUSE;

	if (key == "INSERT")
		return KEYBOARDKEYS::INSERT;

	if (key == "HOME")
		return KEYBOARDKEYS::HOME;

	if (key == "PAGEUP")
		return KEYBOARDKEYS::PAGEUP;

	if (key == "DELETE_KEY")
		return KEYBOARDKEYS::DELETE_KEY;

	if (key == "UNLOAD")
		return KEYBOARDKEYS::UNLOAD;

	if (key == "PAGEDOWN")
		return KEYBOARDKEYS::PAGEDOWN;

	if (key == "RIGHT")
		return KEYBOARDKEYS::RIGHT;

	if (key == "LEFT")
		return KEYBOARDKEYS::LEFT;

	if (key == "DOWN")
		return KEYBOARDKEYS::DOWN;

	if (key == "UP")
		return KEYBOARDKEYS::UP;

	if (key == "NUMLOCKCLEAR")
		return KEYBOARDKEYS::NUMLOCKCLEAR;

	if (key == "KP_DIVIDE")
		return KEYBOARDKEYS::KP_DIVIDE;

	if (key == "KP_MULTIPLY")
		return KEYBOARDKEYS::KP_MULTIPLY;

	if (key == "KP_MINUS")
		return KEYBOARDKEYS::KP_MINUS;

	if (key == "KP_PLUS")
		return KEYBOARDKEYS::KP_PLUS;

	if (key == "KP_ENTER")
		return KEYBOARDKEYS::KP_ENTER;

	if (key == "KP_1")
		return KEYBOARDKEYS::KP_1;

	if (key == "KP_2")
		return KEYBOARDKEYS::KP_2;

	if (key == "KP_3")
		return KEYBOARDKEYS::KP_3;

	if (key == "KP_4")
		return KEYBOARDKEYS::KP_4;

	if (key == "KP_5")
		return KEYBOARDKEYS::KP_5;

	if (key == "KP_6")
		return KEYBOARDKEYS::KP_6;

	if (key == "KP_7")
		return KEYBOARDKEYS::KP_7;

	if (key == "KP_8")
		return KEYBOARDKEYS::KP_8;

	if (key == "KP_9")
		return KEYBOARDKEYS::KP_9;

	if (key == "KP_0")
		return KEYBOARDKEYS::KP_0;

	if (key == "KP_PERIOD")
		return KEYBOARDKEYS::KP_PERIOD;

	if (key == "LCTRL")
		return KEYBOARDKEYS::LCTRL;

	if (key == "LSHIFT")
		return KEYBOARDKEYS::LSHIFT;

	if (key == "LALT")
		return KEYBOARDKEYS::LALT;

	if (key == "LGUI")
		return KEYBOARDKEYS::LGUI;

	if (key == "RCTRL")
		return KEYBOARDKEYS::RCTRL;

	if (key == "RSHIFT")
		return KEYBOARDKEYS::RSHIFT;

	if (key == "RALT")
		return KEYBOARDKEYS::RALT;

	if (key == "RGUI")
		return KEYBOARDKEYS::RGUI;

	if (key == "MODE")
		return KEYBOARDKEYS::MODE;


	return KEYBOARDKEYS::UNKNOWN;

}

std::string InputManager::KeyBoardToString(KEYBOARDKEYS key)
{
	switch (key)
	{
	case KEYBOARDKEYS::ENTER:
		return "ENTER";
		break;
	case KEYBOARDKEYS::ESCAPE:
		return "ESCAPE";
		break;
	case KEYBOARDKEYS::BACKSPACE:
		return "BACKSPACE";
		break;
	case KEYBOARDKEYS::TAB:
		return "TAB";
		break;
	case KEYBOARDKEYS::SPACE:
		return "SPACE";
		break;
	case KEYBOARDKEYS::EXCLAIM:
		return "EXCLAIM";
		break;
	case KEYBOARDKEYS::QUOTEDBL:
		return "QUOTEDBL";
		break;
	case KEYBOARDKEYS::HASH:
		return "HASH";
		break;
	case KEYBOARDKEYS::PERCENT:
		return "PERCENT";
		break;
	case KEYBOARDKEYS::DOLLAR:
		return "DOLLAR";
		break;
	case KEYBOARDKEYS::AMPERSAND:
		return "AMPERSAND";
		break;
	case KEYBOARDKEYS::QUOTE:
		return "QUOTE";
		break;
	case KEYBOARDKEYS::LEFTPAREN:
		return "LEFTPAREN";
		break;
	case KEYBOARDKEYS::RIGHTPAREN:
		return "RIGHTPAREN";
		break;
	case KEYBOARDKEYS::ASTERISK:
		return "ASTERISK";
		break;
	case KEYBOARDKEYS::PLUS:
		return "PLUS";
		break;
	case KEYBOARDKEYS::COMMA:
		break;
	case KEYBOARDKEYS::MINUS:
		return "MINUS";
		break;
	case KEYBOARDKEYS::PERIOD:
		return "PERIOD";
		break;
	case KEYBOARDKEYS::SLASH:
		return "SLASH";
		break;
	case KEYBOARDKEYS::NUMBER_0:
		return "NUMBER_0";
		break;
	case KEYBOARDKEYS::NUMBER_1:
		return "NUMBER_1";
		break;
	case KEYBOARDKEYS::NUMBER_2:
		return "NUMBER_2";
		break;
	case KEYBOARDKEYS::NUMBER_3:
		return "NUMBER_3";
		break;
	case KEYBOARDKEYS::NUMBER_4:
		return "NUMBER_4";
		break;
	case KEYBOARDKEYS::NUMBER_5:
		return "NUMBER_5";
		break;
	case KEYBOARDKEYS::NUMBER_6:
		return "NUMBER_6";
		break;
	case KEYBOARDKEYS::NUMBER_7:
		return "NUMBER_7";
		break;
	case KEYBOARDKEYS::NUMBER_8:
		return "NUMBER_8";
		break;
	case KEYBOARDKEYS::NUMBER_9:
		return "NUMBER_9";
		break;
	case KEYBOARDKEYS::COLON:
		return "COLON";
		break;
	case KEYBOARDKEYS::SEMICOLON:
		return "SEMICOLON";
		break;
	case KEYBOARDKEYS::LESS:
		return "LESS";
		break;
	case KEYBOARDKEYS::EQUALS:
		return "EQUALS";
		break;
	case KEYBOARDKEYS::GREATER:
		return "GREATER";
		break;
	case KEYBOARDKEYS::QUESTION:
		return "QUESTION";
		break;
	case KEYBOARDKEYS::AT:
		return "AT";
		break;

	case KEYBOARDKEYS::LEFTBRACKET:
		return "LEFTBRACKET";
		break;
	case KEYBOARDKEYS::BACKSLASH:
		return "BACKSLASH";
		break;
	case KEYBOARDKEYS::RIGHTBRACKET:
		return "RIGHTBRACKET";
		break;
	case KEYBOARDKEYS::CARET:
		return "CARET";
		break;
	case KEYBOARDKEYS::UNDERSCORE:
		return "UNDERSCORE";
		break;
	case KEYBOARDKEYS::BACKQUOTE:
		return "BACKQUOTE";
		break;
	case KEYBOARDKEYS::A:
		return "A";
		break;
	case KEYBOARDKEYS::B:
		return "B";
		break;
	case KEYBOARDKEYS::C:
		return "C";
		break;
	case KEYBOARDKEYS::D:
		return "D";
		break;
	case KEYBOARDKEYS::E:
		return "E";
		break;
	case KEYBOARDKEYS::F:
		return "F";
		break;
	case KEYBOARDKEYS::G:
		return "G";
		break;
	case KEYBOARDKEYS::H:
		return "H";
		break;
	case KEYBOARDKEYS::I:
		return "I";
		break;
	case KEYBOARDKEYS::J:
		return "J";
		break;
	case KEYBOARDKEYS::K:
		return "K";
		break;
	case KEYBOARDKEYS::L:
		return "L";
		break;
	case KEYBOARDKEYS::M:
		return "M";
		break;
	case KEYBOARDKEYS::N:
		return "N";
		break;
	case KEYBOARDKEYS::O:
		return "O";
		break;
	case KEYBOARDKEYS::P:
		return "P";
		break;
	case KEYBOARDKEYS::Q:
		return "Q";
		break;
	case KEYBOARDKEYS::R:
		return "R";
		break;
	case KEYBOARDKEYS::S:
		return "S";
		break;
	case KEYBOARDKEYS::T:
		return "T";
		break;
	case KEYBOARDKEYS::U:
		return "U";
		break;
	case KEYBOARDKEYS::V:
		return "V";
		break;
	case KEYBOARDKEYS::W:
		return "W";
		break;
	case KEYBOARDKEYS::X:
		return "X";
		break;
	case KEYBOARDKEYS::Y:
		return "Y";
		break;
	case KEYBOARDKEYS::Z:
		return "Z";
		break;
	case KEYBOARDKEYS::CAPSLOCK:
		return "CAPSLOCK";
		break;
	case KEYBOARDKEYS::F1:
		return "F1";
		break;
	case KEYBOARDKEYS::F2:
		return "F2";
		break;
	case KEYBOARDKEYS::F3:
		return "F3";
		break;
	case KEYBOARDKEYS::F4:
		return "F4";
		break;
	case KEYBOARDKEYS::F5:
		return "F5";
		break;
	case KEYBOARDKEYS::F6:
		return "F6";
		break;
	case KEYBOARDKEYS::F7:
		return "F7";
		break;
	case KEYBOARDKEYS::F8:
		return "F8";
		break;
	case KEYBOARDKEYS::F9:
		return "F9";
		break;
	case KEYBOARDKEYS::F10:
		return "F10";
		break;
	case KEYBOARDKEYS::F11:
		return "F11";
		break;
	case KEYBOARDKEYS::F12:
		return "F12";
		break;
	case KEYBOARDKEYS::PRINTSCREEN:
		return "PRINTSCREEN";
		break;
	case KEYBOARDKEYS::SCROLLLOCK:
		return "SCROLLLOCK";
		break;
	case KEYBOARDKEYS::PAUSE:
		return "PAUSE";
		break;
	case KEYBOARDKEYS::INSERT:
		return "INSERT";
		break;
	case KEYBOARDKEYS::HOME:
		return "HOME";
		break;
	case KEYBOARDKEYS::PAGEUP:
		return "PAGEUP";
		break;
	case KEYBOARDKEYS::DELETE_KEY:
		return "DELETE_KEY";
		break;
	case KEYBOARDKEYS::UNLOAD:
		return "UNLOAD";
		break;
	case KEYBOARDKEYS::PAGEDOWN:
		return "PAGEDOWN";
		break;
	case KEYBOARDKEYS::RIGHT:
		return "RIGHT";
		break;
	case KEYBOARDKEYS::LEFT:
		return "LEFT";
		break;
	case KEYBOARDKEYS::DOWN:
		return "DOWN";
		break;
	case KEYBOARDKEYS::UP:
		return "UP";
		break;
	case KEYBOARDKEYS::NUMLOCKCLEAR:
		return "NUMLOCKCLEAR";
		break;
	case KEYBOARDKEYS::KP_DIVIDE:
		return "KP_DIVIDE";
		break;
	case KEYBOARDKEYS::KP_MULTIPLY:
		return "KP_MULTIPLY";
		break;
	case KEYBOARDKEYS::KP_MINUS:
		return "KP_MINUS";
		break;
	case KEYBOARDKEYS::KP_PLUS:
		return "KP_PLUS";
		break;
	case KEYBOARDKEYS::KP_ENTER:
		return "KP_ENTER";
		break;
	case KEYBOARDKEYS::KP_1:
		return "KP_1";
		break;
	case KEYBOARDKEYS::KP_2:
		return "KP_2";
		break;
	case KEYBOARDKEYS::KP_3:
		return "KP_3";
		break;
	case KEYBOARDKEYS::KP_4:
		return "KP_4";
		break;
	case KEYBOARDKEYS::KP_5:
		return "KP_5";
		break;
	case KEYBOARDKEYS::KP_6:
		return "KP_6";
		break;
	case KEYBOARDKEYS::KP_7:
		return "KP_7";
		break;
	case KEYBOARDKEYS::KP_8:
		return "KP_8";
		break;
	case KEYBOARDKEYS::KP_9:
		return "KP_9";
		break;
	case KEYBOARDKEYS::KP_0:
		return "KP_0";
		break;
	case KEYBOARDKEYS::KP_PERIOD:
		return "KP_PERIOD";
		break;
	case KEYBOARDKEYS::LCTRL:
		return "LCTRL";
		break;
	case KEYBOARDKEYS::LSHIFT:
		return "LSHIFT";
		break;
	case KEYBOARDKEYS::LALT:
		return "LALT";
		break;
	case KEYBOARDKEYS::LGUI:
		return "LGUI";
		break;
	case KEYBOARDKEYS::RCTRL:
		return "RCTRL";
		break;
	case KEYBOARDKEYS::RSHIFT:
		return "RSHIFT";
		break;
	case KEYBOARDKEYS::RALT:
		return "RALT";
		break;
	case KEYBOARDKEYS::RGUI:
		return "RGUI";
		break;
	case KEYBOARDKEYS::MODE:
		return "MODE";
		break;
	default:
		return "UNKNOWN";
		break;
	}
	return "UNKNOWN";
}

GAMEPADBUTTONS InputManager::GamePadToEnum(std::string key)
{
	if (key == "A")
		return GAMEPADBUTTONS::A;
	if (key == "B")
		return GAMEPADBUTTONS::B;
	if (key == "X")
		return GAMEPADBUTTONS::X;
	if (key == "Y")
		return GAMEPADBUTTONS::Y;
	if (key == "BACK")
		return GAMEPADBUTTONS::BACK;
	if (key == "GUIDE")
		return GAMEPADBUTTONS::GUIDE;
	if (key == "START")
		return GAMEPADBUTTONS::START;
	if (key == "LEFTSTICK")
		return GAMEPADBUTTONS::LEFTSTICK;
	if (key == "RIGHTSTICK")
		return GAMEPADBUTTONS::RIGHTSTICK;
	if (key == "LEFTSHOULDER")
		return GAMEPADBUTTONS::LEFTSHOULDER;
	if (key == "RIGHTSHOULDER")
		return GAMEPADBUTTONS::RIGHTSHOULDER;
	if (key == "DPAD_UP")
		return GAMEPADBUTTONS::DPAD_UP;
	if (key == "DPAD_DOWN")
		return GAMEPADBUTTONS::DPAD_DOWN;
	if (key == "DPAD_LEFT")
		return GAMEPADBUTTONS::DPAD_LEFT;
	if (key == "DPAD_RIGHT")
		return GAMEPADBUTTONS::DPAD_RIGHT;
	if (key == "MISC1")
		return GAMEPADBUTTONS::MISC1;
	if (key == "PADDLE1")
		return GAMEPADBUTTONS::PADDLE1;
	if (key == "PADDLE2")
		return GAMEPADBUTTONS::PADDLE2;
	if (key == "PADDLE3")
		return GAMEPADBUTTONS::PADDLE3;
	if (key == "PADDLE4")
		return GAMEPADBUTTONS::PADDLE4;
	if (key == "TOUCHPAD")
		return GAMEPADBUTTONS::TOUCHPAD;

	return GAMEPADBUTTONS::INVALID;
}

std::string InputManager::GamePadToString(GAMEPADBUTTONS key)
{
	switch (key)
	{
	case GAMEPADBUTTONS::A:
		return "A";
		break;
	case GAMEPADBUTTONS::B:
		return "B";
		break;
	case GAMEPADBUTTONS::X:
		return "X";
		break;
	case GAMEPADBUTTONS::Y:
		return "Y";
		break;
	case GAMEPADBUTTONS::BACK:
		return "BACK";
		break;
	case GAMEPADBUTTONS::GUIDE:
		return "GUIDE";
		break;
	case GAMEPADBUTTONS::START:
		return "START";
		break;
	case GAMEPADBUTTONS::LEFTSTICK:
		return "LEFTSTICK";
		break;
	case GAMEPADBUTTONS::RIGHTSTICK:
		return "RIGHTSTICK";
		break;
	case GAMEPADBUTTONS::LEFTSHOULDER:
		return "LEFTSHOULDER";
		break;
	case GAMEPADBUTTONS::RIGHTSHOULDER:
		return "RIGHTSHOULDER";
		break;
	case GAMEPADBUTTONS::DPAD_UP:
		return "DPAD_UP";
		break;
	case GAMEPADBUTTONS::DPAD_DOWN:
		return "DPAD_DOWN";
		break;
	case GAMEPADBUTTONS::DPAD_LEFT:
		return "DPAD_LEFT";
		break;
	case GAMEPADBUTTONS::DPAD_RIGHT:
		return "DPAD_RIGHT";
		break;
	case GAMEPADBUTTONS::MISC1:
		return "MISC1";
		break;
	case GAMEPADBUTTONS::PADDLE1:
		return "PADDLE1";
		break;
	case GAMEPADBUTTONS::PADDLE2:
		return "PADDLE2";
		break;
	case GAMEPADBUTTONS::PADDLE3:
		return "PADDLE3";
		break;
	case GAMEPADBUTTONS::PADDLE4:
		return "PADDLE4";
		break;
	case GAMEPADBUTTONS::TOUCHPAD:
		return "TOUCHPAD";
		break;
	}
	return "INVALID";
}

GAMEPADBUTTONS InputManager::GetPressGamePadButton()
{
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::A))
		return GAMEPADBUTTONS::A;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::B))
		return GAMEPADBUTTONS::B;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::X))
		return GAMEPADBUTTONS::X;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::Y))
		return GAMEPADBUTTONS::Y;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::BACK))
		return GAMEPADBUTTONS::BACK;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::GUIDE))
		return GAMEPADBUTTONS::GUIDE;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::START))
		return GAMEPADBUTTONS::START;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::LEFTSTICK))
		return GAMEPADBUTTONS::LEFTSTICK;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::RIGHTSTICK))
		return GAMEPADBUTTONS::RIGHTSTICK;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::LEFTSHOULDER))
		return GAMEPADBUTTONS::LEFTSHOULDER;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::RIGHTSHOULDER))
		return GAMEPADBUTTONS::RIGHTSHOULDER;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::DPAD_UP))
		return GAMEPADBUTTONS::DPAD_UP;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::DPAD_DOWN))
		return GAMEPADBUTTONS::DPAD_DOWN;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::DPAD_LEFT))
		return GAMEPADBUTTONS::DPAD_LEFT;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::DPAD_RIGHT))
		return GAMEPADBUTTONS::DPAD_RIGHT;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::MISC1))
		return GAMEPADBUTTONS::MISC1;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::PADDLE1))
		return GAMEPADBUTTONS::PADDLE1;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::PADDLE2))
		return GAMEPADBUTTONS::PADDLE2;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::PADDLE3))
		return GAMEPADBUTTONS::PADDLE3;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::PADDLE4))
		return GAMEPADBUTTONS::PADDLE4;
	if (IsGamepadButtonPressed(GAMEPADBUTTONS::TOUCHPAD))
		return GAMEPADBUTTONS::TOUCHPAD;

	return GAMEPADBUTTONS::INVALID;
}
