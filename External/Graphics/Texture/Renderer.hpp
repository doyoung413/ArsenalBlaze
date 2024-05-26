#pragma once
#include "Texture.hpp"
#include "Animation.hpp"
#include "../Shader/Shader.hpp"
#include "../Color/Color4f.hpp"

#include "glm.hpp"

struct Sprite
{
    Texture2D texture;
    Animation animation;
    bool isAnimated = false;
};

class Renderer
{
public:
    // Constructor (inits shaders/shapes)
    //Renderer(Shader shader);
    // Destructor
    ~Renderer();

    void initRenderData();
    void initRectangleBar();
    void DrawSprite(Texture2D& texture, glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);
    void DrawSpriteWithAnimation(Sprite& sprite, float dt, glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);
    void DrawSpriteWithAnimation(Sprite& sprite, Animation& animation, float dt, glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);
    void ResetAnimation(Sprite& sprite);

    void DrawRectangle(glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);
    void DrawRectangleLine(glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);

    void DrawCircleLine(glm::vec3 position, float radius, int segments, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);

    void DrawHPBar(Texture2D& texture, int health, int MaxHealth, glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);

    //void DrawRectangleLine(glm::vec3 position, glm::vec3 size, float rotate = 0.0f, Color4f color = Color4f(1.0f, 1.0f, 1.0f, 1.0f), float depth = 0.f);
    void SetShader(Shader shader_) { shader = shader_; }
    Shader GetShader() { return shader; }

    unsigned int GetVerticeHandle() { return verticesHandle; }
private:
    // Render state
    Shader       shader;
    unsigned int verticesHandle = 0;
    unsigned int dataBufferHandle = 0;

    unsigned int barVerticesHandle = 0;
    unsigned int barDataBufferHandle = 0;
};
