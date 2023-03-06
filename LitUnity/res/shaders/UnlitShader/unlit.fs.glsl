#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
uniform vec4 main_color=vec4(1);
uniform sampler2D texture_diffuse1;
uniform bool useTex=false;
void main()
{    
    if(useTex){
        FragColor = texture(texture_diffuse1, TexCoords);
    }else{
        FragColor=main_color;
    }
}