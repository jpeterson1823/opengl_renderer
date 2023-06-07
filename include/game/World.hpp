#pragma once
#include <vector>
#include "game/GameObject.hpp"

class World {
private:
    std::vector<GameObject*> gameObjects;

public:
    World();
    ~World();

    GameObject* createObject();
    GameObject* getObject(unsigned int id);
};
