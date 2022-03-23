//
// Created by pawel on 21.03.2022.
//

#include <iostream>
#include "wall.hpp"
using namespace std;
using namespace sf;
Wall::Wall(Vector2f& position,Texture& texture,unsigned int size){
    this->setPosition(position.x,position.y);
    this->setTexture(texture);
    this->scale((float)size/(float)texture.getSize().x,(float)size/(float)texture.getSize().y);
    this->mapElementType = MapElementType::wall;
}
