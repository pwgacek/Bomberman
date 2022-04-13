//
// Created by pawel on 11.04.2022.
//

#include <iostream>
#include "info_bar/infobar.hpp"

InfoBar::InfoBar(unsigned int width, unsigned int height,unsigned int shiftX,unsigned int shiftY):
width{width},height{height},shiftX{shiftX},shiftY{shiftY} {
    if(!firstPlayerTextTexture.loadFromFile("assets/p1text.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!secondPlayerTextTexture.loadFromFile("assets/p2text.png")){
        std::cout << "can't load image" <<std::endl;
    }

    firstPlayerText.setTexture(firstPlayerTextTexture);
    secondPlayerText.setTexture(secondPlayerTextTexture);
    firstPlayerText.setPosition(shiftX,shiftY);
    secondPlayerText.setPosition(width-secondPlayerTextTexture.getSize().x,shiftY);
}

Sprite &InfoBar::getFirstPlayerText() {
    return firstPlayerText;
}



Sprite &InfoBar::getSecondPlayerText() {
    return secondPlayerText;
}
