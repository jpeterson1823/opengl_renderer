#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GameObject {
protected:
    float hitRadius;
    unsigned int id;
    unsigned int shaderId;

    glm::mat4 modelMat;
    glm::vec3 color;

public:
    GameObject(int id, float xpos, float ypos, float hitRadius, unsigned int shaderId);
    ~GameObject();

    inline glm::vec3 getPosition() {
        return glm::vec3(modelMat[3][0], modelMat[3][1], modelMat[3][2]);
    }

    inline void setPosition(glm::vec3 v) {
        modelMat[3][0] = v.x;
        modelMat[3][1] = v.y;
        modelMat[3][2] = v.z;
    }

    inline glm::vec3 getColor() {
        return this->color;
    }

    inline void setColor(glm::vec3 color) {
        this->color = color;
    }

    void  setHitRadius(float val);
    float getHitRadius();

    unsigned int getGameId();
    glm::mat4 getModelMat();

    void move(glm::vec3 velocity);
};
