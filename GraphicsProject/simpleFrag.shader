//a simple fragment shader
#version 410

in vec4 fPosition;
in vec2 fTexCoord;
in vec3 fNormal;
in vec4 fColor;

uniform sampler2D diffuseTexture;

uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ks;
uniform float specularPower;

uniform vec3 lightDirection;
uniform vec4 lightAmbient;
uniform vec4 lightDiffuse;
uniform vec4 lightSpecular;
uniform float LightSpecularPower;

uniform vec3 cameraPosition;

out vec4 pColor;

void main() {
	vec3 surfaceNormal = normalize(fNormal);
	vec3 lightNormal = normalize(lightDirection);

	//calculate ambient color
	vec4 ambientColor = vec4(Ka,1) * lightAmbient;

	//caculate diffuse color;
	float lambertTerm = dot(-lightNormal, surfaceNormal);
	lambertTerm = max(0, min(1, lambertTerm));
	vec4 diffuseColor = vec4(Kd,1)  * lightDiffuse * lambertTerm;

	//calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(lightNormal,surfaceNormal);

	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0, specularTerm);
	specularTerm = pow(specularTerm, specularPower);

	vec4 specularColor = vec4(Ks,1) * lightSpecular * specularTerm;

	//color = ambientColor + diffuseColor + specularColor 
	vec4 color = ambientColor + diffuseColor + specularColor;

	pColor = fColor * texture(diffuseTexture,fTexCoord);
}