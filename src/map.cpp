//
// Created by pawel on 21.03.2022.
//
#include <cstdlib>
#include "map.hpp"
#include "bomberman.hpp"
#include <iostream>
#include <random>
#include <functional>


Map::Map(){
    mapElements = new MapElement[MAP_SIZE*MAP_SIZE];
    bombTextureArray = new Texture[Bomb::BOMB_TEXTURES];
    bombermans = new Bomberman[PLAYERS_NUMBER]{Bomberman(1,CELL_SIZE,CELL_SIZE,CELL_SIZE),
                                               Bomberman(2,(MAP_SIZE-2)*CELL_SIZE,(MAP_SIZE-2)*CELL_SIZE,CELL_SIZE)};

    generateMapElements();
    fillBombTextureArray();

}

Map::~Map() {
    printf("usuwam mape\n");
    delete [] mapElements;
    delete [] bombTextureArray;
    delete [] bombermans;
}



MapElement *Map::getMapElements() const {
    return mapElements;
}
bool randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
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
    //create corridors and chest

    for(int i=0;i<MAP_SIZE*MAP_SIZE;i++){
        if(mapElements[i].getMapElementType() != MapElement::wall){
            Vector2f v((float)((int)(i/MAP_SIZE))*CELL_SIZE,(float)(i%MAP_SIZE) * CELL_SIZE);
            if(randomBool() == 0) mapElements[i] = Corridor(v);
            else mapElements[i] = Chest(v,chestTexture,CELL_SIZE);

        }

    }
    //create chests

//    Vector2f d1(CELL_SIZE,CELL_SIZE),d2((MAP_SIZE-2)*CELL_SIZE,(MAP_SIZE-2)*CELL_SIZE);
//    mapElements[MAP_SIZE+1] = Corridor(d1);
//    mapElements[MAP_SIZE*(MAP_SIZE-2) +(MAP_SIZE-2)] = Corridor(d2);


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
    printf("bomba\n");
    double bombermanCenterX = bomberman.getPosition().x + (double)CELL_SIZE/2.0;
    double bombermanCenterY = bomberman.getPosition().y + (double)CELL_SIZE/2.0;
    double bombX = (int)(bombermanCenterX/CELL_SIZE)*CELL_SIZE;
    double bombY = (int)(bombermanCenterY/CELL_SIZE)*CELL_SIZE;
    Vector2f b((float)bombX,(float)bombY);
    bombs.emplace_back(Bomb(b,bombTextureArray,CELL_SIZE));
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
    cout << "before add: " << endl;
    for(auto & it : explosionHashMap){
        cout << it.first << " " << it.second << endl;
    }
    cout <<endl;
    for(int i=1;i<=5;i++){
        if(mapElements[index+i].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index+i].getMapElementType() == MapElement::chest){
            explosionHashMap[index+i]++;
            break;
        }
        explosionHashMap[index+i]++;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index-i].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index-i].getMapElementType() == MapElement::chest){
            explosionHashMap[index-i]++;
            break;
        }
        explosionHashMap[index-i]++;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::chest){
            explosionHashMap[index+i*(int)MAP_SIZE]++;
            break;
        }
        explosionHashMap[index+i*(int)MAP_SIZE]++;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::chest){
            explosionHashMap[index-i*(int)MAP_SIZE]++;
            break;
        }
        explosionHashMap[index-i*(int)MAP_SIZE]++;
    }
    cout << "after add: " << endl;
    for(auto & it : explosionHashMap){
        cout << it.first << " " << it.second << endl;
    }

}
void Map::removeExplosions(int index) {
    cout << "before remove: " << endl;
    for(auto & it : explosionHashMap){
        cout << it.first << " " << it.second << endl;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index+i].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index+i].getMapElementType() == MapElement::chest){
            break;
        }
        if(mapElements[index+i].getMapElementType() == MapElement::explosion){
            explosionHashMap[index+i]--;
        }
        else break;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index-i].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index-i].getMapElementType() == MapElement::chest){
            break;
        }
        if(mapElements[index-i].getMapElementType() == MapElement::explosion){
            explosionHashMap[index-i]--;
        }
        else break;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::chest){
            break;
        }
        if(mapElements[index+i*MAP_SIZE].getMapElementType() == MapElement::explosion){
            explosionHashMap[index+i*(int)MAP_SIZE]--;
        }
        else break;
    }
    for(int i=1;i<=5;i++){
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::wall){
            break;
        }
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::chest){
            break;
        }
        if(mapElements[index-i*MAP_SIZE].getMapElementType() == MapElement::explosion){
            explosionHashMap[index-i*(int)MAP_SIZE]--;
        }
        else break;
    }
    cout << "after remove: " << endl;
    for(auto & it : explosionHashMap){
        cout << it.first << " " << it.second << endl;
    }
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

    for(auto & it : explosionHashMap)
    {
        if(it.second > 0 && mapElements[it.first].getMapElementType() != MapElement::explosion){
            Vector2f v(mapElements[it.first].getPosition());
            mapElements[it.first] =  Explosion(v,explosionTexture,CELL_SIZE);
        }
        if(it.second == 0 && mapElements[it.first].getMapElementType() == MapElement::explosion){
            Vector2f v(mapElements[it.first].getPosition());
            mapElements[it.first] =  Corridor(v);
            explosionHashMap.erase(it.first);
        }

    }
}















