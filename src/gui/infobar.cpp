//
// Created by pawel on 11.04.2022.
//

#include <iostream>
#include "gui/infobar.hpp"

InfoBar::InfoBar(unsigned int width, unsigned int height,unsigned int shiftX,unsigned int shiftY){

    if(!firstPlayerHeadTexture.loadFromFile("../assets/p1head.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!secondPlayerHeadTexture.loadFromFile("../assets/p2head.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if (!arcadeFont.loadFromFile("../assets/ARCADECLASSIC.ttf"))
    {
        cout << "can't load font" << endl;
    }

    firstPlayerHead.setTexture(firstPlayerHeadTexture);
    secondPlayerHead.setTexture(secondPlayerHeadTexture);
    firstPlayerHead.setPosition((float)shiftX,(float)shiftY);
    secondPlayerHead.setPosition((float)width - (float)secondPlayerHeadTexture.getSize().x - 100,(float)shiftY);
    firstPlayerHead.scale((float)60/(float)firstPlayerHeadTexture.getSize().x,(float)60/(float)firstPlayerHeadTexture.getSize().x);
    secondPlayerHead.scale((float)60/(float)secondPlayerHeadTexture.getSize().x,(float)60/(float)secondPlayerHeadTexture.getSize().x);

//    firstPlayerText.setFont(arcadeFont);
//    secondPlayerText.setFont(arcadeFont);
//    firstPlayerText.setCharacterSize(48);
//    secondPlayerText.setCharacterSize(48);

    firstPlayerHPText.setFont(arcadeFont);
    secondPlayerHPText.setFont(arcadeFont);
    firstPlayerHPText.setCharacterSize(50);
    secondPlayerHPText.setCharacterSize(50);

    firstPlayerHPText.setPosition((float)firstPlayerHeadTexture.getSize().x, (float)shiftY - 10);
    secondPlayerHPText.setPosition( (float)width - 100,(float)shiftY - 10);
//

}



Sprite &InfoBar::getFirstPlayerHead() {
    return firstPlayerHead;
}

Sprite &InfoBar::getSecondPlayerHead() {
    return secondPlayerHead;
}

const Text &InfoBar::getFirstPlayerHpText() const {
    return firstPlayerHPText;
}

const Text &InfoBar::getSecondPlayerHpText() const {
    return secondPlayerHPText;
}

void InfoBar::setFirstPlayerHpText(int hp) {
    firstPlayerHPText.setString(to_string(hp) + " HP");
}

void InfoBar::setSecondPlayerHpText(int hp) {
    secondPlayerHPText.setString(to_string(hp) + " HP");
}

//const Text &InfoBar::getFirstPlayerText() const {
//    return firstPlayerText;
//}
//
//const Text &InfoBar::getSecondPlayerText() const {
//    return secondPlayerText;
//}
//
