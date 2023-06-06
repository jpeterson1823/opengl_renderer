#include "game/GameObject.hpp"

GameObject::GameObject(int id, float xpos, float ypos, float hitRadius)
    : id(id), xpos(xpos), ypos(ypos), hitRadius(hitRadius) {};

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
