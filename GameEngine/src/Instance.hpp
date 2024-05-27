/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Instance.hpp
//Description: Header file for singletone
/*-------------------------------------------------------*/
#pragma once
#include "SpriteManager.hpp"
#include "CameraManager.hpp"
#include "InputManager.hpp"
#include "ObjectManager.hpp"
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
    static ObjectManager* GetObjectManager() { return GetInstance().objectManager; }
    static Window* GetWindow() { return GetInstance().window; }

    void SetSpriteManager(SpriteManager* manager) { spriteManager = manager; }
    void SetCameraManager(CameraManager* manager) { cameraManager = manager; }
    void SetInputManager(InputManager* manager) { inputManager = manager; }
    void SetObjectManager(ObjectManager* manager) { objectManager = manager; }
    void SetWindow(Window* window_) { window = window_; }
private:
    SpriteManager* spriteManager = nullptr;
    CameraManager* cameraManager = nullptr;
    InputManager* inputManager = nullptr;
    ObjectManager* objectManager = nullptr;
    Window* window = nullptr;

    Instance() {}
};
