/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Application.hpp
//Description: Header file for handling of the application
/*-------------------------------------------------------*/
#include "Instance.hpp"

class Application
{
public:
    Application() = default;
    ~Application();

    void Init(const char* title, int windowWidth, int windowHeight, bool fullScreen = false);
    void Update();
    void End();
    void Input();

private:
    SpriteManager spriteManager;
    CameraManager cameraManager;
    ObjectManager objectManager;
    LevellManager levelManager;
    InputManager inputManager;
    Window window;
};