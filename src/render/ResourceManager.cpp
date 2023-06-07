#include "render/ResourceManager.hpp"
#include <iostream>
#include <bits/stdc++.h>

#include <filesystem>
namespace fs = std::filesystem;

// run default constructor for static vectors
ShaderAtlas* ResourceManager::shaderAtlas;
TextureAtlas* ResourceManager::textureAtlas;

// run default constructor for static strings
std::string ResourceManager::resDir;
std::string ResourceManager::shaderDir;
std::string ResourceManager::textureDir;

void ResourceManager::Initialize() {
    // initialize resource atlases
    shaderAtlas = new ShaderAtlas();
    textureAtlas = new TextureAtlas();

    // initialize consts
    resDir = fs::current_path().string() + "/res";
    shaderDir = resDir + "/shaders";
    textureDir = resDir + "/textures";

    std::cout << "resDir=" << resDir << std::endl;
    std::cout << "shaderDir=" << shaderDir << std::endl;
    std::cout << "textureDir=" << textureDir << std::endl;

    std::cout << "ResourceManager initialized.\n";
}

// Destructor: Destroies all game resources
void ResourceManager::DestroyResources() {
    // delete shaders
    for (ShaderGameObjPair pair : *shaderAtlas) {
        delete pair.first;
    }

    // delete textures
    for (TextureGameObjPair pair : *textureAtlas) {
        delete pair.first;
    }

    std::cout << "ResourceManager cleaned up.\n";
}

// Generate the default shader
unsigned int ResourceManager::GenerateDefaultShader() {
    // generate default shader path strings
    std::string vpath, fpath;
    vpath = shaderDir + "/default.vert";
    fpath = shaderDir + "/default.frag";

    // load shader and return its id
    return ResourceManager::GenerateShader(vpath.c_str(), fpath.c_str());
}

// Generates new shader and returns its gameId
unsigned int ResourceManager::GenerateShader(const char* vertPath, const char* fragPath) {
    // load shader and dynamically allocate object
    Shader* s = new Shader(vertPath, fragPath);

    // default vertices
    float v[30] = {
        // positions
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,

         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
	};

    // shader setup
    glGenVertexArrays(1, &s->vao);
    glGenBuffers(1, &s->vbo);

    glBindVertexArray(s->vao);
    glBindBuffer(GL_ARRAY_BUFFER, s->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*30, v, GL_STATIC_DRAW);

    GLsizei step = 3 * sizeof(float);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, step, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    // get shader id
    unsigned int id = shaderAtlas->size();

    // create ShaderGameObjPair
    ShaderGameObjPair pair;
    pair.first = s;

    // add shader to atlas
    shaderAtlas->push_back(pair);
    
    // return shader's id
    return id;
}

// Generates new texture and returns its gameId
unsigned int ResourceManager::GenerateTexture(const char* imgPath) {
    // load texture and dynamically allocate object
    Texture2D* t = new Texture2D(imgPath, true);

    // get texture id
    unsigned int id = textureAtlas->size();

    // create TextureGameObjPair
    TextureGameObjPair pair;
    pair.first = t;

    // add texture to atlas
    textureAtlas->push_back(pair);

    // return texture's id
    return id;
}

// Returns shader that corresponds with provided ID
Shader* ResourceManager::GetShader(unsigned int shaderId) {
    if (shaderId >= shaderAtlas->size())
        return nullptr;
    return (*shaderAtlas)[shaderId].first;
}

// Returns texture that corresponds with provided ID
Texture2D* ResourceManager::GetTexture(unsigned int textureId) {
    if (textureId >= textureAtlas->size())
        return nullptr;
    return (*textureAtlas)[textureId].first;
}

