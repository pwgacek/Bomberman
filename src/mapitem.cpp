//
// Created by pawel on 21.03.2022.
//

#include "mapitem.hpp"

MapItem::MapItem(Vector2i position) {
    this->position = position;

}

Vector2i MapItem::getPosition() {
    return position;
}