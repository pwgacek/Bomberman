//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_MAPITEM_HPP
#define PACMAN_MAPITEM_HPP


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
using namespace std;

class MapItem :Sprite{
public:
    MapItem(Vector2i);
    Vector2i getPosition();

private:
    Vector2i position;

};


#endif //PACMAN_MAPITEM_HPP
