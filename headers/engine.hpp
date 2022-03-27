#ifndef PACMAN_ENGINE_HPP
#define PACMAN_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "map.hpp"
using namespace sf;
using namespace std;

class Engine {
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 45;
    static const Time TimePerFrame;
    Map map;

    bool leftFlag = false;
    bool rightFlag = false;
    bool upFlag = false;
    bool downFlag = false;

    bool leftFlag2 = false;
    bool rightFlag2 = false;
    bool upFlag2 = false;
    bool downFlag2 = false;

    float changeX=0;
    float changeY=0;

    Vector2f changedPosition;

public:



    Engine();
    void draw();
    void run();
    void input();
};


#endif //PACMAN_ENGINE_HPP
