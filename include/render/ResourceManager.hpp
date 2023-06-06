#pragma once

#include <vector>
#include "render/Shader.hpp"
#include "render/Texture2D.hpp"

class ResourceManager {
private:
    static std::vector<Shader*>    shaders;
    static std::vector<Texture2D*> textures;

public:
    static unsigned int Initialize();
    static unsigned int GenerateShader(const char* vertPath, const char* fragPath);
    static unsigned int GenerateTexture(const char* imgPath);

    static Shader*    GetShader (unsigned int gameId);
    static Texture2D* GetTexture(unsigned int gameId);

    static void UseShader(unsigned int gameId);
    static void BindTexture(unsigned int gameId);

    static void DestroyResources();
};
