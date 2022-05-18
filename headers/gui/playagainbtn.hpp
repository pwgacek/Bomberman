//
// Created by pawel on 18.05.2022.
//

#ifndef BOMBERMAN_PLAYAGAINBTN_HPP
#define BOMBERMAN_PLAYAGAINBTN_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class PlayAgainBtn {
public:
    bool checkClick(Vector2f) const;
    PlayAgainBtn(float,float,float);
    const Sprite &getSprite() const;

private:
    Sprite sprite;
    Texture texture;
    float size;




};


#endif //BOMBERMAN_PLAYAGAINBTN_HPP
