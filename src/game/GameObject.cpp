#include "game/GameObject.hpp"
#include "render/ResourceManager.hpp"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

GameObject::GameObject(int id, float xpos, float ypos, float hitRadius) : id(id), xpos(xpos), ypos(ypos), hitRadius(hitRadius) {
    modelMat = glm::mat4(1.0f);
    ResourceManager::GenerateDefaultShader();
    std::cout << "GameObject Created.\n";
};

GameObject::~GameObject() {
    std::cout << "GameObject Destroied.\n";
}

void GameObject::setX(float val) {
    this->xpos = val;
}

float GameObject::getX() {
    return this->xpos;
}

void GameObject::setY(float val) {
    this->ypos = val;
}

float GameObject::getY() {
    return this->ypos;
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
