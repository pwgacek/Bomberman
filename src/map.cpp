//
// Created by pawel on 21.03.2022.
//

#include "map.hpp"
#include "bomberman.hpp"
#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <set>

Map::Map(){
    mapElements = new MapElement[MAP_SIZE*MAP_SIZE];
    bombTextureArray = new Texture[Bomb::BOMB_TEXTURES];
    bombermans = new Bomberman[PLAYERS_NUMBER]{Bomberman(1,CELL_SIZE,CELL_SIZE,CELL_SIZE),
                                               Bomberman(2,(MAP_SIZE-2)*CELL_SIZE,(MAP_SIZE-2)*CELL_SIZE,CELL_SIZE)};

    generateMapElements();
    fillBombTextureArray();

}

Map::~Map() {
    delete [] mapElements;
    delete [] bombTextureArray;
    delete [] bombermans;
}



MapElement *Map::getMapElements() const {
    return mapElements;
}



void Map::generateMapElements() {


    if(!wallTexture.loadFromFile("assets/wall.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!chestTexture.loadFromFile("assets/chest.png")){
        std::cout << "can't load image" <<std::endl;
    }
    if(!explosionTexture.loadFromFile("assets/explosion.png")){
        std::cout << "can't load image" <<std::endl;
    }

    Vector2f v1,v2,v3,v4;
    // create borders
    for(int i=0;i<MAP_SIZE-1;i++){

        v1.x = (float)i*CELL_SIZE;
        v1.y = 0;
        v3.x = (float)(MAP_SIZE-i-1)*CELL_SIZE;
        v3.y =(MAP_SIZE-1)*CELL_SIZE;
        v2.x =0;
        v2.y = (float)(i+1)*CELL_SIZE;
        v4.x =(MAP_SIZE-1)*CELL_SIZE;
        v4.y =(float)(MAP_SIZE-i-2)*CELL_SIZE;

        mapElements[((int)v1.x/CELL_SIZE*MAP_SIZE)+(int)v1.y/CELL_SIZE] = Wall(v1,wallTexture,CELL_SIZE);
        mapElements[((int)v2.x/CELL_SIZE*MAP_SIZE)+(int)v2.y/CELL_SIZE] = Wall(v2,wallTexture,CELL_SIZE);
        mapElements[((int)v3.x/CELL_SIZE*MAP_SIZE)+(int)v3.y/CELL_SIZE] = Wall(v3,wallTexture,CELL_SIZE);
        mapElements[((int)v4.x/CELL_SIZE*MAP_SIZE)+(int)v4.y/CELL_SIZE] = Wall(v4,wallTexture,CELL_SIZE);


    }
    //create walls
    for(int i=2;i<MAP_SIZE-2;i+=2){
        for(int j=2;j<MAP_SIZE-2;j+=2){
            v1.x = (float)i*CELL_SIZE;
            v1.y = (float)j*CELL_SIZE;
            mapElements[i*MAP_SIZE+j] = Wall(v1,wallTexture,CELL_SIZE);
        }
    }

    //random bool generation
    time_t seconds;
    seconds = time(nullptr);

    mt19937 mt(seconds);
    std::uniform_int_distribution<> distribution(0,4);

    //create corridors and chest
    std::set<int> freeSpaces;
    for(int i =1;i<=3;i++){
        freeSpaces.insert(MAP_SIZE+i);
        freeSpaces.insert(i*MAP_SIZE+1);
        freeSpaces.insert(MAP_SIZE*(MAP_SIZE-2)-(i-1) +(MAP_SIZE-2));
        freeSpaces.insert(MAP_SIZE*(MAP_SIZE-2-(i-1)) +(MAP_SIZE-2));
    }

    for(int i=0;i<MAP_SIZE*MAP_SIZE;i++){
        if(mapElements[i].getMapElementType() != MapElement::wall){
            Vector2f v((float)((int)(i/MAP_SIZE))*CELL_SIZE,(float)(i%MAP_SIZE) * CELL_SIZE);
            if(distribution(mt) < 1 || (freeSpaces.count(i)==1)) mapElements[i] = Corridor(v);
            else mapElements[i] = Chest(v,chestTexture,CELL_SIZE);

        }

    }

    Vector2f d1(CELL_SIZE,CELL_SIZE),d2((MAP_SIZE-2)*CELL_SIZE,(MAP_SIZE-2)*CELL_SIZE);
    mapElements[MAP_SIZE+1] = Corridor(d1);
    mapElements[MAP_SIZE*(MAP_SIZE-2) +(MAP_SIZE-2)] = Corridor(d2);
}


Bomberman &Map::getBomberman(int id) {
    return (bombermans[id - 1]);
}

bool Map::canMove(Bomberman &bomber) {
    int index;

    switch (bomber.getDirection()) {

        case Bomberman::left:{
            index = (int) ((int)(bomber.getPosition().x/ CELL_SIZE) * MAP_SIZE) +
                    (int)((bomber.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);

            if((int)bomber.getPosition().x % CELL_SIZE == 0){

                if(mapElements[index-MAP_SIZE].getMapElementType() == MapElement::wall ||
                mapElements[index-MAP_SIZE].getMapElementType() == MapElement::chest){
                    return false;
                }
                if(mapElements[index-MAP_SIZE].getPosition().y != bomber.getPosition().y){
                    bomber.move(0, mapElements[index-MAP_SIZE].getPosition().y -bomber.getPosition().y);
                }
            }
            break;
        }
        case Bomberman::right:{
            index = (int) ((int)((bomber.getPosition().x + (CELL_SIZE-1))/ CELL_SIZE) * MAP_SIZE) +
                    (int)((bomber.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);

            if((int)bomber.getPosition().x % CELL_SIZE == 0){

                if(mapElements[index+MAP_SIZE].getMapElementType() == MapElement::wall ||
                mapElements[index+MAP_SIZE].getMapElementType() == MapElement::chest){
                    return false;
                }
                if(mapElements[index+MAP_SIZE].getPosition().y != bomber.getPosition().y){
                    bomber.move(0, mapElements[index+MAP_SIZE].getPosition().y -bomber.getPosition().y);
                }
            }
            break;
        }
        case Bomberman::up:{
            index = (int) ((int)((bomber.getPosition().x +((float)CELL_SIZE/2)) / CELL_SIZE) * MAP_SIZE) +
                    (int)(bomber.getPosition().y/CELL_SIZE);

            if((int)bomber.getPosition().y % CELL_SIZE == 0){

                if(mapElements[index-1].getMapElementType() == MapElement::wall||
                mapElements[index-1].getMapElementType() == MapElement::chest){
                    return false;
                }
                if(mapElements[index-1].getPosition().x != bomber.getPosition().x){
                    bomber.move(mapElements[index-1].getPosition().x-bomber.getPosition().x,0);
                }
            }
            break;
        }
       case Bomberman::down:{
           index = (int) ((int)((bomber.getPosition().x +((float)CELL_SIZE/2)) / CELL_SIZE) * MAP_SIZE)  +
                   (int)((bomber.getPosition().y + (float)(CELL_SIZE-1))/CELL_SIZE);

           if((int)bomber.getPosition().y % CELL_SIZE == 0){

               if(mapElements[index+1].getMapElementType() == MapElement::wall||
               mapElements[index+1].getMapElementType() == MapElement::chest){
                   return false;
               }
               if(mapElements[index+1].getPosition().x != bomber.getPosition().x){
                   bomber.move(mapElements[index+1].getPosition().x-bomber.getPosition().x,0);

               }
           }
           break;
        }
        default:break;
    }
    return true;

}

void Map::fillBombTextureArray() {
    for(int i=0;i<Bomb::BOMB_TEXTURES;i++){
        if(!bombTextureArray[i].loadFromFile("assets/bombs.png",
           IntRect(i*(int)Bomb::BOMB_WIDTH,0,Bomb::BOMB_WIDTH,Bomb::BOMB_HEIGHT))){
            std::cout << "can't load image" <<std::endl;
        }
    }
}

void Map::setBomb(Bomberman &bomberman) {
    double bombermanCenterX = bomberman.getPosition().x + (double)CELL_SIZE/2.0;
    double bombermanCenterY = bomberman.getPosition().y + (double)CELL_SIZE/2.0;
    double bombX = (int)(bombermanCenterX/CELL_SIZE)*CELL_SIZE;
    double bombY = (int)(bombermanCenterY/CELL_SIZE)*CELL_SIZE;
    Vector2f b((float)bombX,(float)bombY);
    bool placeIsEmpty = true;
    for(const Bomb& bomb:bombs){
       if(bomb.getPosition() == b){
           placeIsEmpty = false;
           break;
       }
    }
    if(placeIsEmpty){
        bombs.emplace_back(Bomb(b,bombTextureArray,CELL_SIZE));
    }
}

void Map::animateBombs() {

    bombs.erase(std::remove_if(
            bombs.begin(), bombs.end(),[](const Bomb& b){return !b.exist();} ),bombs.end());

    for(auto & bomb : bombs){
        int status = bomb.changeTexture();
        if(status == Bomb::EXPLOSION_FRAME){
            int index = (int)((int)(bomb.getPosition().x/CELL_SIZE)*MAP_SIZE)+(int)((bomb.getPosition().y)/CELL_SIZE);
            addExplosions(index);
        }
        if(status == Bomb::BOMB_TEXTURES){
            int index = (int)((int)(bomb.getPosition().x/CELL_SIZE)*MAP_SIZE)+(int)((bomb.getPosition().y)/CELL_SIZE);
            removeExplosions(index);
        }

    }
}



void Map::addExplosions(int index) {

    vector<int> positions;
    positions.push_back(index);
    for(int i=1;i<=5;i++){
        if(mapElements[index+i].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index+i].getMapElementType() == MapElement::chest){
            positions.push_back(index+i);
            break;
        }
        positions.push_back(index+i);
        checkIfAnotherBombExplodes(index + i);


    }
    for(int i=1;i<=5;i++){
        if(mapElements[index-i].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index-i].getMapElementType() == MapElement::chest){
            positions.push_back(index-i);
            break;
        }
        positions.push_back(index-i);
        checkIfAnotherBombExplodes(index - i);
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::chest){
            positions.push_back(index+i*(int)MAP_SIZE);
            break;
        }
        positions.push_back(index+i*(int)MAP_SIZE);
        checkIfAnotherBombExplodes(index + i * (int) MAP_SIZE);
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::chest){
            positions.push_back(index-i*(int)MAP_SIZE);
            break;
        }
        positions.push_back(index-i*(int)MAP_SIZE);
        checkIfAnotherBombExplodes(index - i * (int) MAP_SIZE);

    }
    explosionHashMap[index] = positions;

}
void Map::removeExplosions(int index) {
    explosionToRemove.insert(index);
}


const std::vector<Bomb> &Map::getBombs() const {
    return bombs;
}

void Map::move(Bomberman &bomberman, map<string, bool> &playerMoveFlags, float moveSpeed) {
    if(canMove(bomberman)){
        if(bomberman.getDirection() == Bomberman::left)
            bomberman.move(-moveSpeed,0);
        if(bomberman.getDirection() == Bomberman::right)
            bomberman.move(moveSpeed,0);
        if(bomberman.getDirection() == Bomberman::up)
            bomberman.move(0,-moveSpeed);
        if(bomberman.getDirection() == Bomberman::down)
            bomberman.move(0,moveSpeed);
    }

}

void Map::showExplosion() {

    for(int index : explosionToRemove){
        for(int pos : explosionHashMap[index]){
            if(mapElements[pos].getMapElementType() == MapElement::explosion){
                Vector2f v(mapElements[pos].getPosition());
                mapElements[pos] =  Corridor(v);
            }
        }
        explosionHashMap.erase(index);
        explosionToRemove.erase(index);
    }


    for(auto & it : explosionHashMap){
        for(int pos : it.second){
            if(mapElements[pos].getMapElementType() != MapElement::explosion){
                Vector2f v(mapElements[pos].getPosition());
                mapElements[pos] =  Explosion(v,explosionTexture,CELL_SIZE);
            }
        }

    }
}

bool Map::bombermanDamaged(Bomberman &bomberman) {
    int centerIndex = (int)((int)((bomberman.getPosition().x+(float)CELL_SIZE/2)/CELL_SIZE)*MAP_SIZE) +
            (int)((bomberman.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);
    if(mapElements[centerIndex].getMapElementType() == MapElement::explosion) return true;
    return false;
}

void Map::generateSequence(Vector2i * sequence) {
    int j1=0,j2=MAP_SIZE;
    int index = 0;
    while (j1<j2){
        for(int i=j1;i < j2-1;i++){
            sequence[index++] = Vector2i(j1,i);
        }
        for(int i=j1;i < j2-1;i++){
            sequence[index++] = Vector2i(i,j2-1);
        }
        for(int i=j2-1;i>j1;i--){
            sequence[index++] = Vector2i(j2-1,i);
        }
        for(int i=j2-1;i>j1;i--){
            sequence[index++] = Vector2i(i,j1);
        }

        j2-=1;
        j1+=1;

    }
    if(MAP_SIZE % 2 == 1){
        sequence[index] = Vector2i(MAP_SIZE/2,MAP_SIZE/2);
    }
}

void Map::putOneWall(Vector2i &v) {
    Vector2f vector((float)v.x*CELL_SIZE,(float)v.y*CELL_SIZE);
    mapElements[((int)v.x*MAP_SIZE)+(int)v.y] = Wall(vector, wallTexture, CELL_SIZE);
}

void Map::checkIfAnotherBombExplodes(int index) {
    for( Bomb& bomb:bombs){
        if(bomb.getPosition() == mapElements[index].getPosition() && bomb.getTextureIndex() < Bomb::EXPLOSION_FRAME){
            bomb.setTextureIndex(Bomb::EXPLOSION_FRAME);
            addExplosions(index);
        }

    }

}
