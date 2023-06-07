#pragma once

#include <vector>
#include <utility>
#include "render/Shader.hpp"
#include "render/Texture2D.hpp"
#include "game/GameObject.hpp"

// typedef for readability and legibility
typedef std::pair<Shader*, std::vector<GameObject*>> ShaderGameObjPair;
typedef std::pair<Texture2D*, std::vector<GameObject*>> TextureGameObjPair;
typedef std::vector<ShaderGameObjPair> ShaderAtlas;
typedef std::vector<TextureGameObjPair> TextureAtlas;

class ResourceManager {
private:
    static ShaderAtlas* shaderAtlas;
    static TextureAtlas* textureAtlas;

    static std::string resDir;
    static std::string shaderDir;
    static std::string textureDir;
    static std::string defaultShaderPath;
    static std::string defaultTexturePath;

public:
    static void Initialize();
    static void DestroyResources();

    static unsigned int GenerateShader(const char* vertPath, const char* fragPath);
    static unsigned int GenerateDefaultShader();
    static unsigned int GenerateTexture(const char* imgPath);

    static Shader*    GetShader (unsigned int shaderId);
    static Texture2D* GetTexture(unsigned int textureId);
};
