#version 330 core
in vec2 TexCoords;
out vec4 FragColor;
in vec4 shapeColors;

uniform sampler2D image;
uniform vec4 spriteColor;
uniform vec4 colors;
uniform int shaderMode;

void main()
{    
	if (shaderMode == 0 || shaderMode == 1  || shaderMode == 3)
	{
		vec4 imageColors = texture(image, TexCoords);
		if (imageColors.a == 0.0)
        	discard;
    	FragColor = spriteColor * imageColors;
    }
	else if (shaderMode == 2 )
	{
    	FragColor = vec4(colors.x, colors.y, colors.z, colors.a);
	}
	else if (shaderMode == 4)
	{
		vec4 imageColors = texture(image, TexCoords);
		if (imageColors.a == 0.0)
        	discard;
    	FragColor = spriteColor * imageColors * shapeColors;
    }
}  