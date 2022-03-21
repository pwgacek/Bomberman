//
// Created by pawel on 21.03.2022.
//

#include "map.hpp"
#include <iostream>
Map::Map(){

    generateWalls();


}

Map::~Map() {
    printf("usuwam mape\n");
    free(walls);
}



Wall *Map::getWalls() const {
    return walls;
}

void Map::generateWalls() {

    walls = (Wall*)malloc(sizeof(Wall) * WALL_QUANTITY);

    if(!wallTexture.loadFromFile("assets/wall.png")){
        std::cout << "can't load image" <<endl;
    }

    int q=0;
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

        walls[q++] = Wall(v1,wallTexture,CELL_SIZE);
        walls[q++] = Wall(v2,wallTexture,CELL_SIZE);
        walls[q++] = Wall(v3,wallTexture,CELL_SIZE);
        walls[q++] = Wall(v4,wallTexture,CELL_SIZE);


    }

    for(int i=2;i<MAP_SIZE-2;i+=2){
        for(int j=2;j<MAP_SIZE-2;j+=2){
            v1.x = (float)i*CELL_SIZE;
            v1.y = (float)j*CELL_SIZE;
            walls[q++] = Wall(v1,wallTexture,CELL_SIZE);
        }
    }

}
