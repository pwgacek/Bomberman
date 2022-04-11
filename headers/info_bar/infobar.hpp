//
// Created by pawel on 11.04.2022.
//

#ifndef BOMBERMAN_INFOBAR_HPP
#define BOMBERMAN_INFOBAR_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;
using namespace std;
class InfoBar {
public:

    InfoBar(unsigned int,unsigned int,unsigned int,unsigned int);

    InfoBar();

    Sprite& getFirstPlayerText();
    Sprite& getSecondPlayerText();

private:
    unsigned int width;
    unsigned int height;
    unsigned int shiftX;
    unsigned int shiftY;
    Sprite firstPlayerText;
    Sprite secondPlayerText;
    Texture firstPlayerTextTexture;
    Texture secondPlayerTextTexture;


};


#endif //BOMBERMAN_INFOBAR_HPP
