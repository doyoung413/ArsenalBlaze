/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Instance.hpp
//Description: Header file for singletone
/*-------------------------------------------------------*/
#pragma once
#include "SpriteManager.hpp"
#include "CameraManager.hpp"
#include "InputManager.hpp"
#include "Window.hpp"

class Instance
{
public:
    static Instance& GetInstance()
    {
        static Instance instance;
        return instance;
    }

    static SpriteManager* GetSpriteManager() { return GetInstance().spriteManager; }
    static CameraManager* GetCameraManager() { return GetInstance().cameraManager; }
    static InputManager* GetInputManager() { return GetInstance().inputManager; }
    static Window* GetWindow() { return GetInstance().window; }

    void SetSpriteManager(SpriteManager* manager) { spriteManager = manager; }
    void SetCameraManager(CameraManager* manager) { cameraManager = manager; }
    void SetInputManager(InputManager* manager) { inputManager = manager; }
    void SetWindow(Window* window_) { window = window_; }
private:
    SpriteManager* spriteManager = nullptr;
    CameraManager* cameraManager = nullptr;
    InputManager* inputManager = nullptr;
    Window* window = nullptr;

    Instance() {}
};
