#pragma once
#include <vector>
#include "game/GameObject.hpp"
#include "game/Apple.hpp"

class World {
private:
    std::vector<GameObject*> gameObjects;

public:
    World();
    ~World();

    GameObject* createObject();
    GameObject* getObject(unsigned int id);

    Apple* spawnApple(float xpos, float ypos);
};
