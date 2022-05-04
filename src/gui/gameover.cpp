//
// Created by pawel on 04.05.2022.
//

#include "gui/gameover.hpp"
#include <iostream>

GameOver::GameOver(int width,int height) {
    if (!arcadeFont.loadFromFile("../assets/ARCADECLASSIC.ttf")){
        cout << "can't load font" << endl;
    }
    if(!firstPlayerHeadTexture.loadFromFile("../assets/p1head.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!secondPlayerHeadTexture.loadFromFile("../assets/p2head.png")){
        std::cout << "can't load image" <<std::endl;
    }

    gameOverText.setFont(arcadeFont);
    gameOverText.setCharacterSize(130);
    gameOverText.setPosition((float)width/2 - 290,(float)height/2 - 200);
    gameOverText.setString("GAME OVER");

    winnerText.setFont(arcadeFont);
    winnerText.setCharacterSize(100);
    winnerText.setPosition((float)width/2 - 170,(float)height/2 + 100 );
    winnerText.setString("WINNER");

    firstPlayerHead.setTexture(firstPlayerHeadTexture);
    secondPlayerHead.setTexture(secondPlayerHeadTexture);
    firstPlayerHead.setPosition((float)width/2 - 100,(float)(float)height/2 - 40);
    secondPlayerHead.setPosition((float)width/2 - 100,(float)(float)height/2 - 40);
    firstPlayerHead.scale((float)200/(float)firstPlayerHeadTexture.getSize().x,(float)200/(float)firstPlayerHeadTexture.getSize().x);
    secondPlayerHead.scale((float)200/(float)secondPlayerHeadTexture.getSize().x,(float)200/(float)secondPlayerHeadTexture.getSize().x);

}

const Text &GameOver::getGameOverText() const {
    return gameOverText;
}

const Text &GameOver::getWinnerText() const {
    return winnerText;
}



const Sprite &GameOver::getWinnerHead(int i) const {
    return i == 1 ? firstPlayerHead : secondPlayerHead ;
}
