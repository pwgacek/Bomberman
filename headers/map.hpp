//
// Created by pawel on 21.03.2022.
//

#ifndef BOMBERMAN_MAP_HPP
#define BOMBERMAN_MAP_HPP

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

    static const  int CELL_SIZE = 50;
    static const  int MAP_SIZE = 15;
    static const  int PLAYERS_NUMBER = 2;

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

    static void generateSequence(Vector2i * sequence);
    void putOneWall(Vector2i &v);

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
    void checkIfAnotherBombExplodes(int index);


};


#endif //BOMBERMAN_MAP_HPP
