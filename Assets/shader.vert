#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoords;
out vec4 shapeColors;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float depth;

//ANIMATION
uniform int frameX;
uniform int frameY;
uniform int frameIndex;
uniform float correction;
//ANIMATION

//HP
uniform float hp;
uniform float MaxHp;
//HP

uniform int shaderMode;

void main()
{
	if (shaderMode == 0) //SPRITE
	{
		TexCoords = aTexCoord;
	}
	else if(shaderMode == 1) //ANIMATION
	{
    	float unitWidth = 1.0 / frameX;
    	float unitHeight = 1.0 / frameY;

    	int indexX = frameIndex % frameX;
    	int indexY = frameIndex / frameX;
    	TexCoords.x = (aTexCoord.x * unitWidth + unitWidth * indexX);
    	TexCoords.y = (aTexCoord.y * unitHeight + unitHeight * (frameY - 1 - indexY));
	}
	else if (shaderMode == 2) //SHAPE
	{
		shapeColors = color;
	}
	else if(shaderMode == 3) //HP
	{
    	float indexX = hp / MaxHp;

    	TexCoords.x = (aTexCoord.x * indexX);
    	TexCoords.y = aTexCoord.y;
	}
	else if (shaderMode == 4) //Font
	{
		TexCoords = aTexCoord;
		shapeColors = color;
	}

    //vec4 ndc_position =  projection * view * model * vec3(aPos, 1.0);
	gl_Position = projection * view * model * vec4(aPos.x, aPos.y, depth, 1.0);
}