//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP


#include "wall.hpp"

class Map {
public:
    static const unsigned int WALL_QUANTITY = 200;
    static const unsigned int CELL_SIZE = 50;
    static const unsigned int MAP_SIZE = 15;
    Map();
    ~Map();
    Wall* getWalls() const;
private:
    Texture wallTexture;
    Wall* walls;
    void generateWalls();
};


#endif //PACMAN_MAP_HPP
