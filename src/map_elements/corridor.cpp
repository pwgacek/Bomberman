//
// Created by pawel on 23.03.2022.
//

#include "map_elements/corridor.hpp"

Corridor::Corridor(Vector2f& v) {
    this->setPosition(v);
    this->mapElementType =  MapElement::corridor;
}
