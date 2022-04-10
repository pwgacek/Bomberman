//
// Created by pawel on 10.04.2022.
//

#include "map_elements/explosion.hpp"

Explosion::Explosion(Vector2f &position, Texture &texture, unsigned int size) {
    this->setPosition(position.x,position.y);
    this->setTexture(texture);
    this->scale((float)size/(float)texture.getSize().x,(float)size/(float)texture.getSize().y);
    this->mapElementType = MapElementType::explosion;
}
