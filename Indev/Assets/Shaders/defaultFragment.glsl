#version 330 core
out vec4 FragColor;

in vec2 TexturePoints;
			
uniform sampler2D picture;

void main()
{
	FragColor = texture(picture, TexturePoints);
}