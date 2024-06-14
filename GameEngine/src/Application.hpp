/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Application.hpp
//Description: Header file for handling of the application
/*-------------------------------------------------------*/
#pragma once
#include "Instance.hpp"
#include "Timer.hpp"

class Application
{
public:
    Application() = default;
    ~Application();

    void Init(const char* title, int windowWidth, int windowHeight, bool fullScreen = false, FrameRate frameRate = FrameRate::FPS_60);
    void Update();
    void End();
    void Input();

private:
    SpriteManager spriteManager;
    CameraManager cameraManager;
    ObjectManager objectManager;
    LevelManager levelManager;
    InputManager inputManager;
    ParticleManager particleManager;
    BackgroundManager backgroundManager;
    SoundManager soundManager;
    Window window;

    GameManager gameManager;

    Timer timer;
};