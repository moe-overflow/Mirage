/*
#version 330 core
out vec4 FragColor;
in vec3 ourColor;


void main()
{
    FragColor = vec4(ourColor, 1.0f);
}
*/

#version 330 core
layout (location = 0) out vec4 color;

uniform vec4 myColor;

void main()
{
    color = myColor;
}