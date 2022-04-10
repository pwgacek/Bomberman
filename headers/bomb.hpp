//
// Created by pawel on 27.03.2022.
//

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
class Bomb : public Sprite{
public:
    Bomb(const Vector2f&,Texture*,unsigned int);
    static const unsigned int BOMB_TEXTURES = 14;
    static const unsigned int BOMB_WIDTH = 22;
    static const unsigned int BOMB_HEIGHT = 22;
    bool exist() const;
    void changeTexture();


private:
    Texture* textureArray = nullptr;

    int textureIndex;


};


#endif //BOMBERMAN_BOMB_HPP
