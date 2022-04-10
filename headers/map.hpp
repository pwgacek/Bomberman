//
// Created by pawel on 21.03.2022.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP

using namespace std;
#include "map_elements/mapelement.hpp"
#include "bomberman.hpp"
#include "map_elements/wall.hpp"
#include "map_elements/corridor.hpp"
#include "map_elements/chest.hpp"
#include "bomb.hpp"
#include <map>
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
    void move(Bomberman&,std::map<string,bool>&,float);
    void setBomb(Bomberman&);

    void animateBombs();

    const std::vector<Bomb> &getBombs() const;

private:

    Bomberman* bombermans;
    MapElement* mapElements;
    std::vector<Bomb>bombs;


    Texture wallTexture;
    Texture chestTexture;
    Texture* bombTextureArray;

    void generateMapElements();
    void fillBombTextureArray();


};


#endif //PACMAN_MAP_HPP
