#version 330 core

in  vec2 objPosition;
out vec4 FragColor;

uniform vec2 resolution;
uniform float time;

vec3 palette(float t) {
    vec3 a = vec3(0.000, 0.500, 0.500);
    vec3 b = vec3(0.000, 0.500, 0.500);
    vec3 c = vec3(0.000, 1.000, 0.000);
    vec3 d = vec3(0.000, 0.000, 0.000);
    return a + b*cos(6.28318 * (c*t + d));
}

void main()
{
    vec2 uv = objPosition.xy;
    //vec2 uv = gl_FragCoord.xy / resolution.xy;
    //uv = 2.0*uv - 1.0;
    //uv *= (resolution.xy/resolution.x);
    

    float d = 0.5*uv.y*sin(uv.x+16.0*time);
    d += cos(4.0*time);
    
    FragColor = vec4(palette(d),1.0);
}
