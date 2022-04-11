//
// Created by pawel on 21.03.2022.
//

#include "bomberman.hpp"

Bomberman::Bomberman(int i,int x,int y, unsigned int size):id{i},directionQueue{new Direction[4]{none,none,none,none}},
textureArray{new Texture[BOMBERMAN_SPRITES]}{

    this->setPosition((float)x,(float)y);
    fillTextureArray();

    this->setTexture(textureArray[textureIndex]);
    this->scale((float)size/(float)textureArray[textureIndex].getSize().x,
                (float)size/(float)textureArray[textureIndex].getSize().y);

}

Bomberman::~Bomberman(){
    printf("usuwam bombermana\n");
    delete [] textureArray;
    delete [] directionQueue;
}

void Bomberman::fillTextureArray() {
    //depending on id load specific textures
    int q = (id-1)*3;
    for(int i=0;i<BOMBERMAN_SPRITES/3;i++){

        textureArray[i].loadFromFile("assets/spr.png",IntRect(i*(int)BOMBERMAN_WIDTH,
          (int)BOMBERMAN_HEIGHT*(q),BOMBERMAN_WIDTH,BOMBERMAN_HEIGHT));
        textureArray[i+9].loadFromFile("assets/spr.png",IntRect(i*(int)BOMBERMAN_WIDTH,
           (int)BOMBERMAN_HEIGHT*(q+1),BOMBERMAN_WIDTH,BOMBERMAN_HEIGHT));

    }

}

Bomberman::Direction Bomberman::getDirection() {
    return directionQueue[0];
}

void Bomberman::addDirection(Bomberman::Direction d) {

    if(containsDirection(d))return;
    for(int i=3;i>0;i--) {
        directionQueue[i] = directionQueue[i - 1];
    }
    directionQueue[0] = d;

}

void Bomberman::removeDirection(Bomberman::Direction d) {
    if(!containsDirection(d))return;
    for(int i = 0;i<4;i++){
        if(directionQueue[i] == d){
            for(int j=i;j<3;j++){
                directionQueue[j] = directionQueue[j+1];
            }
            directionQueue[3] = none;
            break;
        }

    }

}

void Bomberman::changeDirection(map<string, bool> &playerMoveFlags) {
    if(playerMoveFlags["up"])addDirection(Bomberman::up);
    else removeDirection(Bomberman::up);

    if(playerMoveFlags["left"])addDirection(Bomberman::left);
    else removeDirection(Bomberman::left);

    if(playerMoveFlags["right"])addDirection(Bomberman::right);
    else removeDirection(Bomberman::right);

    if(playerMoveFlags["down"])addDirection(Bomberman::down);
    else removeDirection(Bomberman::down);
}


void Bomberman::changeTexture() {

    int tmp = textureIndex;
    switch(directionQueue[0]){
        case Direction::left:{
            if(textureIndex == 9 || textureIndex == 11){textureIndex = 10;}
            else if(textureIndex == 10) {
                if(earlierTextureIndex == 9){textureIndex = 11;}
                else {textureIndex = 9;}
            }
            else{textureIndex = 9;}
            break;
        }
        case Direction::right:{
            if(textureIndex == 12 || textureIndex == 14){textureIndex = 13;}
            else if(textureIndex == 13) {
                if(earlierTextureIndex == 12){textureIndex = 14;}
                else {textureIndex = 12;}
            }
            else{textureIndex = 12;}
            break;
        }

        case Direction::up:{
            if(textureIndex == 3 || textureIndex == 5){textureIndex = 4;}
            else if(textureIndex == 4) {
                if(earlierTextureIndex == 3){textureIndex =5;}
                else {textureIndex = 3;}
            }
            else{textureIndex = 3;}
            break;
        }

        case Direction::down:{
            if(textureIndex == 0 || textureIndex == 2){textureIndex = 1;}
            else if(textureIndex == 1) {
                if(earlierTextureIndex ==0){textureIndex = 2;}
                else {textureIndex = 0;}
            }
            else{textureIndex = 0;}
            break;
        }
        default:{
            textureIndex = 1;
            break;
        }

    }
    earlierTextureIndex = tmp;
    this->setTexture(textureArray[textureIndex]);

}

bool Bomberman::containsDirection(Bomberman::Direction d) {
    for(int i =0;i<4;i++){
        if(directionQueue[i] == d)return true;
    }
    return false;
}

int Bomberman::getHealth(){
    return health;
}

void Bomberman::changeHealth(int value) {
    health += value;
}








