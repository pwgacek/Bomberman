//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP


#include "mapelement.hpp"
#include "bomberman.hpp"
#include "wall.hpp"
#include "corridor.hpp"
#include "chest.hpp"
#include "bomb.hpp"

class Map {
public:
    static const unsigned int WALL_QUANTITY = 92;
    static const unsigned int CELL_SIZE = 50;
    static const unsigned int MAP_SIZE = 15;
    static const unsigned int PLAYERS_NUMBER = 2;
    Map();
    ~Map();
    MapElement* getMapElements() const;
    Bomberman &getBomberman(int);
    bool canMove(Bomberman&);
    void setBomb(Bomberman&b);
    void checkBombs();
    int getBombsSize();
    Bomb& getBomb(int);
private:

    Bomberman *bombermans;

    Texture wallTexture;
    Texture chestTexture;
    Texture* bombTextureArray;
    MapElement* mapElements;
    void generateMapElements();
    void fillBombTextureArray();
    std::vector<Bomb>bombs;


};


#endif //PACMAN_MAP_HPP
