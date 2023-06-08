#include "game/Apple.hpp"

Apple::Apple(unsigned int id, float xpos, float ypos) 
    : GameObject(id, xpos, ypos, 4, 0) {
    this->color = glm::vec3(1.0f, 0.0f, 0.0f);
}
