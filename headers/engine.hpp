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
    const unsigned int FPS = 10;
    static const Time TimePerFrame;
    const Map map;
public:
    Engine();
    void draw();
    void run();
    void input();
};


#endif //PACMAN_ENGINE_HPP
