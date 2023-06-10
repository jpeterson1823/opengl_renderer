#version 330 core

out vec4 FragColor;

uniform vec2  resolution;
uniform float time;

vec3 palette( float t ) {
    vec3 a = vec3(0.731, 1.098, 0.192);
    vec3 b = vec3(0.358, 1.090, 0.657);
    vec3 c = vec3(1.077, 0.360, 0.328);
    vec3 d = vec3(0.965, 2.265, 0.837);

    return a + b*cos( 6.28318*(c*t+d) );
}


void main() {
    // Normalized pixel coordinates
    vec2 uv = (gl_FragCoord.xy * 2.0 - resolution.xy) / resolution.y;

    // find radius from origin of pixel
    float sinScale = 1.0;
    float r = length(uv);
    r = 0.25*sin(r*sinScale - 2.0*time) + 0.25;

    
    // create color vec
    vec3 color = palette(r);
    FragColor = vec4(color, 1.0f);
}