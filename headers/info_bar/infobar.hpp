//
// Created by pawel on 11.04.2022.
//

#ifndef BOMBERMAN_INFOBAR_HPP
#define BOMBERMAN_INFOBAR_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;
using namespace std;
class InfoBar {
public:

    InfoBar(unsigned int,unsigned int,unsigned int,unsigned int);


    Sprite& getFirstPlayerText();
    Sprite& getSecondPlayerText();
    Sprite& getFirstPlayerHead();
    Sprite& getSecondPlayerHead();
    const Text &getFirstPlayerHpText() const;
    const Text &getSecondPlayerHpText() const;

    void setFirstPlayerHpText(int);
    void setSecondPlayerHpText(int);

private:

    Sprite firstPlayerText;
    Sprite secondPlayerText;
    Texture firstPlayerTextTexture;
    Texture secondPlayerTextTexture;

    Sprite firstPlayerHead;
    Sprite secondPlayerHead;
    Texture firstPlayerHeadTexture;
    Texture secondPlayerHeadTexture;
    Text firstPlayerHPText;
    Text secondPlayerHPText;

};


#endif //BOMBERMAN_INFOBAR_HPP
