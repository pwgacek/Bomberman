//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP


#include "wall.hpp"
#include "bomberman.hpp"


class Map {
public:
    static const unsigned int WALL_QUANTITY = 92;
    static const unsigned int CELL_SIZE = 50;
    static const unsigned int MAP_SIZE = 15;
    Map();
    ~Map();
    Wall* getMapElements() const;
    Bomberman &getBomberman() const;
    bool canMove(Bomberman&,Bomberman::Direction);
private:

    const Bomberman bomberman = Bomberman(CELL_SIZE, CELL_SIZE, CELL_SIZE);
    Texture wallTexture;
    Wall* mapElements;
    void generateMapElements();

};


#endif //PACMAN_MAP_HPP
