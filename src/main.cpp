#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "game/World.hpp"
#include "render/Renderer.hpp"
#include "render/ResourceManager.hpp"

// Window information
const unsigned int g_WINDOW_WIDTH = 1000;
const unsigned int g_WINDOW_HEIGHT = 1000;
static GLFWwindow* g_window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processWindowInput(World& world, float deltaTime);
void gl_setup();
void gl_cleanup();


/* Note on active memory leak
 * Valgrind states:
 *      "still reachable: 265,019 bytes in 3,189 blocks"
 * when main only has gl_setup(), gl_cleanup(), and return 0;
 * Not sure what's causing it, but I can't fix it.
 */
int main() {
    std::cout << "Setting up...\n";
    gl_setup();

    ResourceManager::Initialize();
    Renderer::Initialize(g_WINDOW_WIDTH, g_WINDOW_HEIGHT);

    ResourceManager::GenerateDefaultShader();

    World world;
    Apple* obj = world.spawnApple(0.0f, 0.0f);


    // gameloop
    float currentTime, lastTime, deltaTime = 0.0f;
    while (!glfwWindowShouldClose(g_window)) {
        // time delta controls
        currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        processWindowInput(world, deltaTime);

        // clear screen
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Renderer::RenderGameObject(obj);

        // check & call events
        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }
    
    std::cout << "\nExit signal received. Cleaning up...\n\n";

    Renderer::Destroy();
    ResourceManager::DestroyResources();
    gl_cleanup();

    return 0;
}




void gl_setup() {
    // init glfw
    glfwInit();

    // window setup
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // init global window pointer
    g_window = glfwCreateWindow(g_WINDOW_WIDTH, g_WINDOW_HEIGHT, "OpenGL Snake", NULL, NULL);
    //g_window = glfwCreateWindow(g_WINDOW_WIDTH, g_WINDOW_HEIGHT, "OpenGL Snake", glfwGetPrimaryMonitor(), NULL); // fullscreen
    
    if (g_window == NULL) {
        std::cout << "[ERROR] Failed to create GLFW window." << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(g_window);

    // init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "[ERROR] Failed to initialize GLAD." << std::endl;
        exit(-1);
    }
    // set viewport
    glViewport(0, 0, g_WINDOW_WIDTH, g_WINDOW_HEIGHT);

    // enables and miscellaneous
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSetFramebufferSizeCallback(g_window, framebuffer_size_callback);

}

void gl_cleanup() {
    glfwTerminate();
    glfwDestroyWindow(g_window);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processWindowInput(World& world, float deltaTime) {
    GameObject* obj = world.getObject(0);
    float objSpeed = 20.0f * deltaTime;

    if (glfwGetKey(g_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(g_window, true);
    }
    else {
        glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
        if (glfwGetKey(g_window, GLFW_KEY_W) == GLFW_PRESS) {
            direction.y = 1.0f;
        }
        if (glfwGetKey(g_window, GLFW_KEY_S) == GLFW_PRESS) {
            direction.y = -1.0f;
        }
        if (glfwGetKey(g_window, GLFW_KEY_D) == GLFW_PRESS) {
            direction.x = 1.0f;
        }
        if (glfwGetKey(g_window, GLFW_KEY_A) == GLFW_PRESS) {
            direction.x = -1.0f;
        }

        obj->move(direction * objSpeed);
    }
}
