//
// Created by pawel on 11.04.2022.
//

#ifndef BOMBERMAN_INFOBAR_HPP
#define BOMBERMAN_INFOBAR_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include "playerinfo.hpp"
using namespace sf;
using namespace std;
class InfoBar {
public:

    InfoBar(unsigned int,unsigned int,unsigned int,unsigned int);

    const PlayerInfo &getFirstPlayerInfo() const;

    const PlayerInfo &getSecondPlayerInfo() const;

    void setFirstPlayerText(int);
    void setSecondPlayerText(int);

private:
    PlayerInfo firstPlayerInfo;
    PlayerInfo secondPlayerInfo;

};


#endif //BOMBERMAN_INFOBAR_HPP
