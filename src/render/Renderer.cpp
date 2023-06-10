#include "render/Renderer.hpp"
#include "render/ResourceManager.hpp"
#include "game/GameObject.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <GLFW/glfw3.h>

Camera* Renderer::camera = nullptr;
glm::mat4 Renderer::projection = glm::mat4(1.0f);
glm::vec2 Renderer::resolution = glm::vec2(0.0f);

// Creates camera and projection matrix objects
void Renderer::Initialize(float scrWidth, float scrHeight) {
    camera = new Camera();
    resolution = glm::vec2(scrWidth, scrHeight);
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
    glm::vec3 color = gobj->getColor();

    if (t != nullptr)
        t->bind();
    s->use();
    s->setVec3("color", color);
    s->setVec2("resolution", resolution);
    s->setFloat("time", glfwGetTime());
    s->setMVP(gobj->getModelMat(), camera->view, projection);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
