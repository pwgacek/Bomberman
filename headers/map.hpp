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
#include "map_elements/explosion.hpp"
#include "bomb.hpp"
#include <map>
#include <unordered_map>
#include <set>

class Map {
public:

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
    void showExplosion();
    void animateBombs();
    bool bombermanDamaged(Bomberman&);
    const std::vector<Bomb> &getBombs() const;

    void generateSequence(Vector2i * sequence);
    void putOneBlock(Vector2i&);

private:

    Bomberman* bombermans;
    MapElement* mapElements;
    std::vector<Bomb>bombs;
    std::unordered_map<int,std::vector<int>> explosionHashMap;
    std::set<int> explosionToRemove;


    Texture wallTexture;
    Texture chestTexture;
    Texture explosionTexture;
    Texture* bombTextureArray;

    void generateMapElements();
    void fillBombTextureArray();
    void addExplosions(int);
    void removeExplosions(int);
    void anotherBombExplodes(int index);


};


#endif //PACMAN_MAP_HPP
