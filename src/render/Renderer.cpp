#include "render/Renderer.hpp"
#include "render/ResourceManager.hpp"
#include "game/GameObject.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Camera* Renderer::camera = nullptr;
glm::mat4 Renderer::projection = glm::mat4(1.0f);

// Creates camera and projection matrix objects
void Renderer::Initialize(float scrWidth, float scrHeight) {
    camera = new Camera();
    projection = glm::perspective(glm::radians(camera->getFov()), scrWidth/scrHeight, 0.1f, 1000.0f);
    std::cout << "Renderer initialized.\n";
}

// Destroys dynamically allocated objects
void Renderer::Destroy() {
    delete camera;
    std::cout << "Renderer cleaned up.\n";
}

void Renderer::DrawLine(Line& line) {
    line.draw(camera->view, projection);
}

void Renderer::RenderGameObject(GameObject* gobj) {
    Texture2D* t = ResourceManager::GetTexture(gobj->getGameId());
    Shader* s = ResourceManager::GetShader(gobj->getGameId());
    glm::vec3 color = glm::vec3(1.0f);

    if (t != nullptr)
        t->bind();
    s->use();
    s->setVec3("color", color);
    s->setMVP(gobj->getModelMat(), camera->view, projection);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
