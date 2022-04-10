//
// Created by pawel on 27.03.2022.
//

#include <SFML/System/Clock.hpp>
#include "bomb.hpp"

Bomb::Bomb(const Vector2f &position, Texture *textureArray, unsigned int size) {

    textureIndex =0;
    this->setPosition(position.x,position.y);
    this->textureArray = textureArray;
    this->scale((float)size/(float)textureArray[0].getSize().x,(float)size/(float)textureArray[0].getSize().y);
    changeTexture();
}

void Bomb::changeTexture() {
    waiter++;
    if(waiter>10 || textureIndex== 0){
        setTexture(textureArray[textureIndex++]);
    }
}

bool Bomb::exist() const {
    return BOMB_TEXTURES > textureIndex;
}

