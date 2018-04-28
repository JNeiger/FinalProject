#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform vec3 color;
uniform sampler2D name;

void main()
{
   if (texture(name, TexCoord).x > 0.1f) {
       FragColor = texture(name, TexCoord);
   } else {
       FragColor = vec4(color, 1.0f);
   }
}