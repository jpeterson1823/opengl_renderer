#include "game/World.hpp"
#include "render/ResourceManager.hpp"

World::World() {}

World::~World() {
    for (GameObject* g : gameObjects)
        delete g;
}

GameObject* World::createObject() {
    // get next available ID
    unsigned int id = this->gameObjects.size();

    // create obj and add it to gameObjects
    GameObject* obj = new GameObject(id, 0, 0, 3);
    this->gameObjects.push_back(obj);

    ResourceManager::GenerateShader("/home/invisa/Documents/code_stuffs/opengl_snake/graphics/shaders/obj.vert", "/home/invisa/Documents/code_stuffs/opengl_snake/graphics/shaders/obj.frag");

    // return its id
    return obj;
}
