#pragma once
#include "render/Shader.hpp"
#include "render/Camera.hpp"
#include "game/GameObject.hpp"
#include "render/shapes/Line.hpp"

class Renderer {
private:
    static Camera* camera;
    static glm::mat4 projection;
    static glm::vec2 resolution;

public:
    static void Initialize(float scrWidth, float scrHeight);
    static void Destroy();
    static void DrawLine(Line& line);

    static void RenderGameObject(GameObject* gobj);
    static void RenderWorld();
    static void Update();

    static glm::mat4 GetProjection();
    static glm::mat4 GetView();
};
