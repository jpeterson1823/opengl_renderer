#include "game/World.hpp"
#include "render/ResourceManager.hpp"
#include <iostream>

World::World() {
    std::cout << "World Created.\n";
}

World::~World() {
    for (GameObject* g : gameObjects)
        delete g;
    std::cout << "World Destroied.\n";
}

GameObject* World::createObject() {
    // get next available ID
    unsigned int id = this->gameObjects.size();

    // create obj and add it to gameObjects
    GameObject* obj = new GameObject(id, 0, 0, 3, 0);
    this->gameObjects.push_back(obj);

    return obj;
}

GameObject* World::getObject(unsigned int id) {
    if (id < gameObjects.size()) {
        return gameObjects[id];
    }
    return nullptr;
}
