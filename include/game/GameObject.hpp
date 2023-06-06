#pragma once

class GameObject {
private:
    float xpos;
    float ypos;
    float hitRadius;
    unsigned int id;

public:
    GameObject(int id, float xpos, float ypos, float hitRadius);

    void  setX(float val);
    float getX();

    void  setY(float val);
    float getY();

    void  setHitRadius(float val);
    float getHitRadius();

    unsigned int getGameId();
};
