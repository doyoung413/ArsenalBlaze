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
#include "LevelManager.hpp"
#include "ParticleManager.hpp"
#include "GameManager.hpp"
#include "SoundManager.hpp"
#include "BackgroundManager.hpp"
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
    static LevelManager* GetLevelManager() { return GetInstance().levelManager; }
    static ParticleManager* GetParticleManager() { return GetInstance().particleManager; }
    static SoundManager* GetSoundManager() { return GetInstance().soundManager; }
    static BackgroundManager* GetBackgroundManager() { return GetInstance().backgroundManager; }
    static Window* GetWindow() { return GetInstance().window; }
    static GameManager* GetGameManager() { return GetInstance().gameManager; }

    void SetSpriteManager(SpriteManager* manager) { spriteManager = manager; }
    void SetCameraManager(CameraManager* manager) { cameraManager = manager; }
    void SetInputManager(InputManager* manager) { inputManager = manager; }
    void SetObjectManager(ObjectManager* manager) { objectManager = manager; }
    void SetLevelManager(LevelManager* manager) { levelManager = manager; }
    void SetParticleManager(ParticleManager* manager) { particleManager = manager; }
    void SetSoundManagerManager(SoundManager * manager) { soundManager = manager; }
    void SetBackgroundManager(BackgroundManager* manager) { backgroundManager = manager; }
    void SetWindow(Window* window_) { window = window_; }
    void SetGameManager(GameManager* manager) { gameManager = manager; }
private:
    SpriteManager* spriteManager = nullptr;
    CameraManager* cameraManager = nullptr;
    InputManager* inputManager = nullptr;
    ObjectManager* objectManager = nullptr;
    LevelManager* levelManager = nullptr;
    ParticleManager* particleManager = nullptr;
    BackgroundManager* backgroundManager = nullptr;
    SoundManager* soundManager = nullptr;
    Window* window = nullptr;

    GameManager* gameManager = nullptr;

    Instance() {}
};
