#include "game/GameObject.hpp"
#include "render/ResourceManager.hpp"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

GameObject::GameObject(int id, float xpos, float ypos, float hitRadius, unsigned int shaderId) {
    this->id = id;
    this->shaderId = shaderId;
    this->hitRadius = hitRadius;
    this->color = glm::vec3(1.0f);

    modelMat = glm::mat4(1.0f);
    //modelMat = glm::scale(modelMat, glm::vec3(0.05f));

    std::cout << "GameObject Created.\n";
};

GameObject::~GameObject() {
    std::cout << "GameObject Destroied.\n";
}

void GameObject::setHitRadius(float val) {
    this->hitRadius = val;
}

float GameObject::getHitRadius() {
    return this->hitRadius;
}

unsigned int GameObject::getGameId() {
    return this->id;
}

glm::mat4 GameObject::getModelMat() {
    return this->modelMat;
}

void GameObject::move(glm::vec3 velocity) {
    modelMat = glm::translate(modelMat, velocity);
}
