// A simple vertex shader
#version 410

layout( location = 0 ) in vec4 vPosition;
layout( location = 1 ) in vec4 vColor;
layout(location = 2) in vec2 vTexCoord;

uniform mat4 projectionViewModel;

out vec4 fColor;
out vec2 fTexCoord;
void main() {
	gl_Position = projectionViewModel * vPosition;
	fColor = vColor;
	fTexCoord = vTexCoord;
}