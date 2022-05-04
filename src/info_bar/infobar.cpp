//
// Created by pawel on 11.04.2022.
//

#include <iostream>
#include "info_bar/infobar.hpp"

InfoBar::InfoBar(unsigned int width, unsigned int height,unsigned int shiftX,unsigned int shiftY){
    if(!firstPlayerTextTexture.loadFromFile("../assets/p1text.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!secondPlayerTextTexture.loadFromFile("../assets/p2text.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!firstPlayerHeadTexture.loadFromFile("../assets/p1head.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!secondPlayerHeadTexture.loadFromFile("../assets/p2head.png")){
        std::cout << "can't load image" <<std::endl;
    }

    firstPlayerText.setTexture(firstPlayerTextTexture);
    secondPlayerText.setTexture(secondPlayerTextTexture);
    firstPlayerText.setPosition((float)shiftX,(float)shiftY);
    secondPlayerText.setPosition((float)width-(float)secondPlayerTextTexture.getSize().x,(float)shiftY);

    firstPlayerHead.setTexture(firstPlayerHeadTexture);
    secondPlayerHead.setTexture(secondPlayerHeadTexture);
    firstPlayerHead.setPosition((float)shiftX+(float)firstPlayerTextTexture.getSize().x,(float)shiftY);
    secondPlayerHead.setPosition((float)width-50 -(float)secondPlayerTextTexture.getSize().x,(float)shiftY);
    firstPlayerHead.scale((float)50/(float)firstPlayerHeadTexture.getSize().x,(float)50/(float)firstPlayerHeadTexture.getSize().x);
    secondPlayerHead.scale((float)50/(float)secondPlayerHeadTexture.getSize().x,(float)50/(float)secondPlayerHeadTexture.getSize().x);


    sf::Font font;
    if (!font.loadFromFile("../assets/ARCADECLASSIC.ttf"))
    {
        cout << "can't load font" << endl;
    }
    firstPlayerHPText.setFont(font);
    secondPlayerHPText.setFont(font);
    firstPlayerHPText.setCharacterSize(24);
    secondPlayerHPText.setCharacterSize(24);
    firstPlayerHPText.setFillColor(Color::White);
    secondPlayerHPText.setFillColor(Color::White);
    firstPlayerHPText.setString("10");
    secondPlayerHPText.setString("10");
    firstPlayerHPText.setPosition((float)shiftX,(float)shiftY);
    secondPlayerHPText.setPosition((float)width-(float)secondPlayerTextTexture.getSize().x,(float)shiftY);


}

Sprite &InfoBar::getFirstPlayerText() {
    return firstPlayerText;
}



Sprite &InfoBar::getSecondPlayerText() {
    return secondPlayerText;
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
    firstPlayerHPText.setString(to_string(hp));
}

void InfoBar::setSecondPlayerHpText(int hp) {
    secondPlayerHPText.setString(to_string(hp));
}

