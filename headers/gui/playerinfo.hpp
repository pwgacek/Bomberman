//
// Created by pawel on 18.05.2022.
//

#ifndef BOMBERMAN_PLAYERINFO_HPP
#define BOMBERMAN_PLAYERINFO_HPP

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;
using namespace std;
class PlayerInfo {
public:
    PlayerInfo(const string&,const Vector2f&,float,const Vector2f&);

    const Sprite &getSprite() const;

    const Text &getText() const;

    void setText(int hp);

private:
    Sprite sprite;
    Texture texture;
    Font font;
    Text text;


};


#endif //BOMBERMAN_PLAYERINFO_HPP
