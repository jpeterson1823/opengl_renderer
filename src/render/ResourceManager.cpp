#include "render/ResourceManager.hpp"

std::vector<Shader*> ResourceManager::shaders;
std::vector<Texture2D*> ResourceManager::textures;

// Destructor: Destroies all game resources
void ResourceManager::DestroyResources() {
    // delete shaders
    for (Shader* s : shaders)
        delete s;

    // delete textures
    for (Texture2D* t: textures)
        delete t;
}

// Generates new shader and returns its gameId
unsigned int ResourceManager::GenerateShader(const char* vertPath, const char* fragPath) {
    // load shader and dynamically allocate object
    Shader* s = new Shader(vertPath, fragPath);

    float xSpriteUnit = 0.1;
    float ySpriteUnit = 0.1;
    float x = 1.0f;
    float y = 1.0f;

    float xStart = x * xSpriteUnit;
    float yStart = (y + 1.0f) * ySpriteUnit;
    float xEnd = (x + 1.0f) * xSpriteUnit;
    float yEnd = y * ySpriteUnit;
    float v[30] = {
        // positions         // texture coords
        -0.5f,  0.5f, 0.0f,  xStart, yEnd, // top left 
         0.5f,  0.5f, 0.0f,  xEnd, yEnd, // top right
         0.5f, -0.5f, 0.0f,  xEnd, yStart, // bottom right

         0.5f, -0.5f, 0.0f,  xEnd, yStart, // bottom right
        -0.5f, -0.5f, 0.0f,  xStart, yStart, // bottom left
        -0.5f,  0.5f, 0.0f,  xStart, yEnd  // top left 
	};

    glGenVertexArrays(1, &s->vao);
    glGenBuffers(1, &s->vbo);

    glBindVertexArray(s->vao);
    glBindBuffer(GL_ARRAY_BUFFER, s->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*30, v, GL_STATIC_DRAW);

    GLsizei step = 5 * sizeof(float);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, step, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, step, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // log id and push pointer to vec
    unsigned int id = shaders.size();
    shaders.push_back(s);
    
    // return shader's id
    return id;
}

// Generates new texture and returns its gameId
unsigned int ResourceManager::GenerateTexture(const char* imgPath) {
    // load texture and dynamically allocate object
    Texture2D* t = new Texture2D(imgPath, true);

    // log id and push pointer to vec
    unsigned int id = textures.size();
    textures.push_back(t);

    // return texture's id
    return id;
}

// Returns shader that corresponds with provided ID
Shader* ResourceManager::GetShader(unsigned int gameId) {
    if (gameId >= shaders.size())
        return nullptr;
    return shaders[gameId];
}

// Returns texture that corresponds with provided ID
Texture2D* ResourceManager::GetTexture(unsigned int gameId) {
    if (gameId >= textures.size())
        return nullptr;
    return textures[gameId];
}

// Use shader for GFLW
void ResourceManager::UseShader(unsigned int gameId) {
    ResourceManager::GetShader(gameId)->use();
}

// Use texture for GLFW
void ResourceManager::BindTexture(unsigned int gameId) {
    ResourceManager::GetTexture(gameId)->bind();
}
