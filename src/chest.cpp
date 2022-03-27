//
// Created by pawel on 23.03.2022.
//

#include "chest.hpp"

Chest::Chest(Vector2f &position, Texture &texture, unsigned int size) {
    this->setPosition(position.x,position.y);
    this->setTexture(texture);
    this->scale((float)size/(float)texture.getSize().x,(float)size/(float)texture.getSize().y);
    this->mapElementType = MapElementType::chest;
}
