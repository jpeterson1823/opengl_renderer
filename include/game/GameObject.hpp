#pragma once
#include <glm/glm.hpp>

class GameObject {
private:
    float xpos;
    float ypos;
    float hitRadius;
    unsigned int id;

    glm::mat4 modelMat;

public:
    GameObject(int id, float xpos, float ypos, float hitRadius);
    ~GameObject();

    void  setX(float val);
    float getX();

    void  setY(float val);
    float getY();

    void  setHitRadius(float val);
    float getHitRadius();

    unsigned int getGameId();

    glm::mat4 getModelMat();
};
