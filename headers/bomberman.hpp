//
// Created by pawel on 21.03.2022.
//

#ifndef BOMBERMAN_BOMBERMAN_HPP
#define BOMBERMAN_BOMBERMAN_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "bomb.hpp"
#include <map>
using namespace sf;
using namespace std;
class Bomberman : public Sprite {

public:
    static const unsigned int BOMBERMAN_HEIGHT = 24;
    static const unsigned int BOMBERMAN_WIDTH = 16;
    static const unsigned int BOMBERMAN_SPRITES = 18;

    enum Direction{none,left,right,up,down};

    Direction getDirection();
    void addDirection(Direction d);
    void removeDirection(Direction d);
    void changeDirection(map<string,bool>&);

    void changeTexture();
    int getHealth();
    void changeHealth(int);

    Bomberman(int,int,int,unsigned int);
    ~Bomberman() override;

private:
    int id;
    int textureIndex = 1;
    int earlierTextureIndex = -1;
    int health = 3;
    Texture* textureArray;
    Direction *directionQueue;

    bool containsDirection(Direction d);
    void fillTextureArray();

};


#endif //BOMBERMAN_BOMBERMAN_HPP
