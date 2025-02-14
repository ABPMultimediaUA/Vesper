
#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;

void main()
{
	//color = vec4(ourColor, 1.0f);
	
	//pintando el objeto con textura y aplicando el color de antes
	//color = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0f);
	
	//mezclando dos texturas una encima de la otra
	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
}
