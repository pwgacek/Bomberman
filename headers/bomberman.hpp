//
// Created by pawel on 21.03.2022.
//

#ifndef BOMBERMAN_BOMBERMAN_HPP
#define BOMBERMAN_BOMBERMAN_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
class Bomberman : public Sprite {

public:
    static const unsigned int BOMBERMAN_HEIGHT = 24;
    static const unsigned int BOMBERMAN_WIDTH = 16;
    static const unsigned int BOMBERMAN_SPRITES = 27;
    enum Direction{
        none,
        left,
        right,
        up,
        down

    };

    Direction getDirection();
    void addDirection(Direction d);
    void removeDirection(Direction d);
    Bomberman(int,int,unsigned int);
    ~Bomberman();
    void changeTexture();



private:
    int textureIndex = 1;
    int earlierTextureIndex = -1;
    Texture* textureArray = nullptr;

    Direction *directionQueue;
    bool containsDirection(Direction d);
    void fillTextureArray();
};


#endif //BOMBERMAN_BOMBERMAN_HPP
