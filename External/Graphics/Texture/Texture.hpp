#pragma once
#define TEXTURE_H

#include "glm.hpp"

// Texture2D is able to store and configure a texture in OpenGL.
// It also hosts utility functions for easy management.
class Texture2D
{
public:
    void Generate(glm::vec2 size_, unsigned char* data);
    void Bind() const;
    void UnBind() const;

    unsigned int GetTexturehandle() { return textureHandle; }

private:
    unsigned int textureHandle = 0;
    glm::vec2 size {0,0};
};