//
// Created by pawel on 04.05.2022.
//

#ifndef BOMBERMAN_GAMEOVER_HPP
#define BOMBERMAN_GAMEOVER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include "playagainbtn.hpp"

using namespace sf;
using namespace std;
class GameOver {
public:
    GameOver(int,int);



private:


    Texture firstPlayerHeadTexture;
    Texture secondPlayerHeadTexture;
    Sprite firstPlayerHead;
    Sprite secondPlayerHead;
    Text gameOverText;
    Text winnerText;
    Font arcadeFont;

    PlayAgainBtn playAgainBtn;


public:
    const Sprite &getWinnerHead(int) const;

    const PlayAgainBtn &getPlayAgainBtn() const;

    const Text &getGameOverText() const;

    const Text &getWinnerText() const;


};


#endif //BOMBERMAN_GAMEOVER_HPP
