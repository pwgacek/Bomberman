//
// Created by pawel on 11.04.2022.
//

#include <iostream>
#include "gui/infobar.hpp"

InfoBar::InfoBar(unsigned int width, unsigned int height,unsigned int shiftX,unsigned int shiftY):
firstPlayerInfo("../assets/p1head.png",Vector2f((float)shiftX,(float)shiftY),60,Vector2f(70,shiftY - 10)),
secondPlayerInfo("../assets/p2head.png",Vector2f((float)width  - 160,(float)shiftY),60,Vector2f((float)width - 90,(float)shiftY - 10)){


//
//    firstPlayerHead.setPosition((float)shiftX,(float)shiftY);
//    secondPlayerHead.setPosition((float)width - (float)secondPlayerHeadTexture.getSize().x - 100,(float)shiftY);

//    firstPlayerHead.scale((float)60/(float)firstPlayerHeadTexture.getSize().x,(float)60/(float)firstPlayerHeadTexture.getSize().x);
//    secondPlayerHead.scale((float)60/(float)secondPlayerHeadTexture.getSize().x,(float)60/(float)secondPlayerHeadTexture.getSize().x);
//
//
//    firstPlayerHPText.setFont(arcadeFont);
//    secondPlayerHPText.setFont(arcadeFont);
//    firstPlayerHPText.setCharacterSize(50);
//    secondPlayerHPText.setCharacterSize(50);

//    firstPlayerHPText.setPosition((float)firstPlayerHeadTexture.getSize().x, (float)shiftY - 10);
//    secondPlayerHPText.setPosition( (float)width - 100,(float)shiftY - 10);
//

}

const PlayerInfo &InfoBar::getFirstPlayerInfo() const {
    return firstPlayerInfo;
}

const PlayerInfo &InfoBar::getSecondPlayerInfo() const {
    return secondPlayerInfo;
}

void InfoBar::setFirstPlayerText(int hp) {
    firstPlayerInfo.setText(hp);
}

void InfoBar::setSecondPlayerText(int hp) {
    secondPlayerInfo.setText(hp);
}


