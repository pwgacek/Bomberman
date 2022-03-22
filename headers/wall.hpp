//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_WALL_HPP
#define PACMAN_WALL_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;
class Wall : public Sprite {
public:
    Wall();
    Wall(Vector2f&,Texture&,unsigned int);
private:
    Texture texture;
};


#endif //PACMAN_WALL_HPP
