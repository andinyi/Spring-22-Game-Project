#version 330 core
layout (location = 0) in vec2 rawCoords;
layout (location = 1) in vec2 tCoordInput;

out vec2 TexturePoints;

uniform ivec3 spriteCoord;
uniform ivec2 windowSize;

void main() 
{
	gl_Position = vec4(2.0*(rawCoords.x+spriteCoord.x)/windowSize.x - 1, 2.0*(rawCoords.y+spriteCoord.y)/windowSize.y - 1, spriteCoord.z, 1.0f);
	TexturePoints = tCoordInput;
}