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



MapElement *Map::getMapElements() const {
    return mapElements;
}

void Map::generateMapElements() {

    mapElements = new MapElement[MAP_SIZE*MAP_SIZE];

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

    for(int i=0;i<MAP_SIZE*MAP_SIZE;i++){
        if(mapElements[i].getMapElementType() != MapElement::wall){
            Vector2f v((float)((int)(i/MAP_SIZE))*CELL_SIZE,(float)(i%MAP_SIZE) * CELL_SIZE);
            mapElements[i] = Corridor(v);
        }

    }


}

Bomberman &Map::getBomberman() const{
    return const_cast<Bomberman &>(bomberman);
}

bool Map::canMove(Bomberman &bomber) {
    int index;
//    index = (int) (bomber.getPosition().x / CELL_SIZE) * MAP_SIZE +
//            (int)(bomber.getPosition().y / CELL_SIZE);
//    if(bomber.getDirection()==Bomberman::right || bomber.getDirection()==Bomberman::left){
//        index2 = (int) (bomber.getPosition().x / CELL_SIZE) * MAP_SIZE +
//                 (int)floor(int(bomber.getPosition().y+CELL_SIZE-1) / CELL_SIZE);
//    }else{
//        index2 = (int) floor(int(bomber.getPosition().x+CELL_SIZE-1)/ CELL_SIZE) * MAP_SIZE +
//                 (int)(bomber.getPosition().y / CELL_SIZE);
//    }

    //printf("char: %c index: %d index2: %d pos: x:%f,y:%f\n",direction,index,index2,bomber.getPosition().x,bomber.getPosition().y);
    index = (int)((int)bomber.getPosition().x/ CELL_SIZE * MAP_SIZE) + (int)((int)(bomber.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);
    printf("lewo: %d, ",index);
    index = (int)((int)((bomber.getPosition().x + (CELL_SIZE-1))/ CELL_SIZE) * MAP_SIZE) + (int)((int)(bomber.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);
    printf("prawo: %d\n",index);
    switch (bomber.getDirection()) {

        case Bomberman::left:{
            index = (int) ((int)(bomber.getPosition().x/ CELL_SIZE) * MAP_SIZE) + (int)((bomber.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);
            if((int)bomber.getPosition().x % CELL_SIZE == 0){
                if(mapElements[index-MAP_SIZE].getMapElementType() == MapElement::wall)return false;
                if(mapElements[index-MAP_SIZE].getPosition().y != bomber.getPosition().y)
                    bomber.move(0, mapElements[index-MAP_SIZE].getPosition().y -bomber.getPosition().y);
            }


            break;
        }
        case Bomberman::right:{
            index = (int) ((int)((bomber.getPosition().x + (CELL_SIZE-1))/ CELL_SIZE) * MAP_SIZE) + (int)((bomber.getPosition().y+(float)CELL_SIZE/2)/CELL_SIZE);
            if((int)bomber.getPosition().x % CELL_SIZE == 0){
                if(mapElements[index+MAP_SIZE].getMapElementType() == MapElement::wall)return false;
                if(mapElements[index+MAP_SIZE].getPosition().y != bomber.getPosition().y)
                    bomber.move(0, mapElements[index+MAP_SIZE].getPosition().y -bomber.getPosition().y);
            }

            break;
        }
        case Bomberman::up:{
            index = (int) ((int)((bomber.getPosition().x +((float)CELL_SIZE/2)) / CELL_SIZE) * MAP_SIZE) + (int)(bomber.getPosition().y/CELL_SIZE);
            if((int)bomber.getPosition().y % CELL_SIZE == 0){
                if(mapElements[index-1].getMapElementType() == MapElement::wall) return false;
                if(mapElements[index-1].getPosition().x != bomber.getPosition().x)
                    bomber.move(mapElements[index-1].getPosition().x-bomber.getPosition().x,0);
            }
            break;
        }
       case Bomberman::down:{
           index = (int) ((int)((bomber.getPosition().x +((float)CELL_SIZE/2)) / CELL_SIZE) * MAP_SIZE)  + (int)((bomber.getPosition().y + (float)(CELL_SIZE-1))/CELL_SIZE);
           if((int)bomber.getPosition().y % CELL_SIZE == 0){
               if(mapElements[index+1].getMapElementType() == MapElement::wall) return false;
               if(mapElements[index+1].getPosition().x != bomber.getPosition().x)
                   bomber.move(mapElements[index+1].getPosition().x-bomber.getPosition().x,0);
           }

           break;
        }
        default:break;
    }
    return true;

}





