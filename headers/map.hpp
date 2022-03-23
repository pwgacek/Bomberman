//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP


#include "mapelement.hpp"
#include "bomberman.hpp"
#include "wall.hpp"
#include "corridor.hpp"


class Map {
public:
    static const unsigned int WALL_QUANTITY = 92;
    static const unsigned int CELL_SIZE = 50;
    static const unsigned int MAP_SIZE = 15;
    Map();
    ~Map();
    MapElement* getMapElements() const;
    Bomberman &getBomberman() const;
    bool canMove(Bomberman&);
private:

    const Bomberman bomberman = Bomberman(CELL_SIZE, CELL_SIZE, CELL_SIZE);
    Texture wallTexture;
    MapElement* mapElements;
    void generateMapElements();

};


#endif //PACMAN_MAP_HPP
