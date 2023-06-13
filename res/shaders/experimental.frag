#version 330 core

out vec4 FragColor;

uniform float time;

void main() {
    vec3 itime = vec3(time);
    vec3 stagSin = vec3(sin(time), sin(time+90), sin(time+180));
    vec2 uv = gl_FragCoord.xy/vec2(1000.0f);
    //vec3 color = vec3(0.5f) + 0.5*cos(itime+uv.xyx+vec3(0,90,180));

    FragColor = vec4(color, 1.0f);
}
