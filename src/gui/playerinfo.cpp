//
// Created by pawel on 18.05.2022.
//

#include "gui/playerinfo.hpp"

const Sprite &PlayerInfo::getSprite() const {
    return sprite;
}

const Text &PlayerInfo::getText() const {
    return text;
}

PlayerInfo::PlayerInfo(const string& path,const Vector2f&  spritePos, float size,const Vector2f& textPos) {
    if(!texture.loadFromFile(path)){
        std::cout << "can't load image" <<std::endl;
    }
    if(!font.loadFromFile("../assets/ARCADECLASSIC.ttf")){
        std::cout << "can't load image" <<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(spritePos);
    sprite.setScale(size/(float)texture.getSize().x,size/(float)texture.getSize().x);

    text.setFont(font);
    text.setCharacterSize(50);
    text.setPosition(textPos);
}



void PlayerInfo::setText(int hp){
    text.setString( to_string(hp) + "HP");
}

