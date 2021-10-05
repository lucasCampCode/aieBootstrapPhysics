// A simple vertex shader
#version 410

layout( location = 0 ) in vec4 vPosition;
layout(location = 1) in vec4 vColor;

uniform mat4 projectionViewModel;

out vec4 fColor;

void main() {
	gl_Position = projectionViewModel * vPosition;
	fColor = vColor;
}