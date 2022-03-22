//
// Created by pawel on 21.03.2022.
//

#include "map.hpp"
#include "bomberman.hpp"
#include <iostream>
#include <cmath>

Map::Map()   {

    generateMapElements();




}

Map::~Map() {
    printf("usuwam mape\n");
    delete [] mapElements;
}



Wall *Map::getMapElements() const {
    return mapElements;
}

void Map::generateMapElements() {

    mapElements = new Wall[MAP_SIZE*MAP_SIZE];

    if(!wallTexture.loadFromFile("assets/wall.png")){
        std::cout << "can't load image" <<std::endl;
    }

    //int q=0;
    Vector2f v1,v2,v3,v4;
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

    for(int i=2;i<MAP_SIZE-2;i+=2){
        for(int j=2;j<MAP_SIZE-2;j+=2){
            v1.x = (float)i*CELL_SIZE;
            v1.y = (float)j*CELL_SIZE;
            mapElements[i*MAP_SIZE+j] = Wall(v1,wallTexture,CELL_SIZE);
        }
    }

}

Bomberman &Map::getBomberman() const{
    return const_cast<Bomberman &>(bomberman);
}

bool Map::canMove(Bomberman &bomber,Bomberman::Direction direction) {
    int index,index2;
    index = (int) (bomber.getPosition().x / CELL_SIZE) * MAP_SIZE +
            (int)(bomber.getPosition().y / CELL_SIZE);
    if(direction==Bomberman::right || direction==Bomberman::left){
        index2 = (int) (bomber.getPosition().x / CELL_SIZE) * MAP_SIZE +
                 (int)floor(int(bomber.getPosition().y+CELL_SIZE-1) / CELL_SIZE);
    }else{
        index2 = (int) floor(int(bomber.getPosition().x+CELL_SIZE-1)/ CELL_SIZE) * MAP_SIZE +
                 (int)(bomber.getPosition().y / CELL_SIZE);
    }



    //printf("char: %c index: %d index2: %d pos: x:%f,y:%f\n",direction,index,index2,bomber.getPosition().x,bomber.getPosition().y);


    switch (direction) {
        case Bomberman::left:{
                if((int)bomber.getPosition().x % CELL_SIZE == 0){
                    if(mapElements[index-MAP_SIZE].getPosition().x != -1 || mapElements[index2-MAP_SIZE].getPosition().x !=-1)
                        return false;
                }
                break;
        }
        case Bomberman::right:{

            if((int)bomber.getPosition().x % CELL_SIZE == 0){
                if(mapElements[index+MAP_SIZE].getPosition().x != -1 || mapElements[index2+MAP_SIZE].getPosition().x !=-1)
                    return false;
            }
            break;
        }
        case Bomberman::up:{
            if((int)bomber.getPosition().y % CELL_SIZE == 0){
                if(mapElements[index-1].getPosition().y != -1 || mapElements[index2-1].getPosition().y != -1)
                    return false;
                break;
            }


        }
       case Bomberman::down:{
           if((int)bomber.getPosition().y % CELL_SIZE == 0){
               if(mapElements[index+1].getPosition().y != -1 || mapElements[index2+1].getPosition().y != -1)
                   return false;
           }

            break;
        }
        default:break;
    }
    return true;

}





