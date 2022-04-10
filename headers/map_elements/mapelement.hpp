//
// Created by pawel on 23.03.2022.
//

#ifndef BOMBERMAN_MAPELEMENT_HPP
#define BOMBERMAN_MAPELEMENT_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

class MapElement : public Sprite {
public:
    enum MapElementType{corridor,wall,chest,explosion};
    MapElementType getMapElementType();

protected:
    MapElementType mapElementType;
};


#endif //BOMBERMAN_MAPELEMENT_HPP
