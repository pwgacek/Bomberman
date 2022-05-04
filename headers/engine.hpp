#ifndef PACMAN_ENGINE_HPP
#define PACMAN_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "map.hpp"
#include "gui/infobar.hpp"
#include "gui/gameover.hpp"
using namespace sf;
using namespace std;

class Engine {
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 45;
    static const Time TimePerFrame;
    Map map;
    InfoBar infoBar;
    GameOver gameOver;
    std::map<string,bool> firstPlayerMoveFlags;
    std::map<string,bool> secondPlayerMoveFlags;

    bool firstPlayerBombFlag = false;
    bool secondPlayerBombFlag = false;

    Clock changeBombermanTextureClock;
    Clock firstPlayerSetBombClock;
    Clock secondPlayerSetBombClock;
    Clock bombClock;
    Clock firstPlayerDamagedClock;
    Clock secondPlayerDamagedClock;

    bool endOfGame = false;
    Vector2i * sequence;
    int sequenceIncrementator = 0;
    int winner;



public:

    Engine();
    ~Engine();
    void draw();
    void run();
    void input();
};


#endif //PACMAN_ENGINE_HPP
