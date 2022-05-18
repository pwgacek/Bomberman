//
// Created by pawel on 18.05.2022.
//

#include "gui/playagainbtn.hpp"

PlayAgainBtn::PlayAgainBtn(float x, float y,float size) {
    if(texture.loadFromFile("../assets/play_again.png")){
        std::cout << "can't load image" <<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(x,y));
    sprite.setScale(size/(float)texture.getSize().x,size/(float)texture.getSize().y);

}

const Sprite &PlayAgainBtn::getSprite() const {
    return sprite;
}

bool PlayAgainBtn::checkClick(Vector2f) {
    return false;
}
