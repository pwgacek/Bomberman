#include "engine.hpp"
#include "wall.hpp"
#include <iostream>
const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);
Clock changeTextureClock;
Engine::Engine(){
    resolution = Vector2f(Map::MAP_SIZE*Map::CELL_SIZE,Map::MAP_SIZE*Map::CELL_SIZE);
    window.create(VideoMode(resolution.x,resolution.y),"Bomber-Man",Style::Default);
    window.setFramerateLimit(FPS);

    changedPosition  = map.getBomberman(1).getPosition();
}

void Engine::run() {
    // main loop -runs until the window is closed
    while(window.isOpen()){
        input();
        draw();
    }

}

void Engine::draw(){
    window.clear(Color::Black);

    for(int i=0;i<Map::MAP_SIZE*Map::MAP_SIZE;i++){

        if(map.getMapElements()[i].getPosition().x != -1)
            window.draw(map.getMapElements()[i]) ;
    }



    if(upFlag)map.getBomberman(1).addDirection(Bomberman::up);
    else map.getBomberman(1).removeDirection(Bomberman::up);

    if(leftFlag)map.getBomberman(1).addDirection(Bomberman::left);
    else map.getBomberman(1).removeDirection(Bomberman::left);

    if(rightFlag)map.getBomberman(1).addDirection(Bomberman::right);
    else map.getBomberman(1).removeDirection(Bomberman::right);

    if(downFlag)map.getBomberman(1).addDirection(Bomberman::down);
    else map.getBomberman(1).removeDirection(Bomberman::down);




    if(leftFlag && map.getBomberman(1).getDirection() == Bomberman::left) if(map.canMove(map.getBomberman(1)))map.getBomberman(1).move(-4,0);
    if(rightFlag && map.getBomberman(1).getDirection() == Bomberman::right) if(map.canMove(map.getBomberman(1)))map.getBomberman(1).move(4,0);
    if(upFlag && map.getBomberman(1).getDirection() == Bomberman::up) if(map.canMove(map.getBomberman(1)))map.getBomberman(1).move(0,-4);
    if(downFlag && map.getBomberman(1).getDirection() == Bomberman::down)if(map.canMove(map.getBomberman(1)))map.getBomberman(1).move(0,4);

    Time timeElapsed = changeTextureClock.getElapsedTime();
    if(timeElapsed.asSeconds() > 0.1){
        changeTextureClock.restart();
        map.getBomberman(1).changeTexture();

    }



    window.draw(map.getBomberman(1));
    window.draw(map.getBomberman(2));
    window.display();
}
void Engine::input(){
    Event event{};
    while(window.pollEvent(event)){
        if(event.type == Event::Closed){
            window.close();
        }



        if(event.type == Event::KeyPressed){
            switch (event.key.code) {
                case  Keyboard::Escape : window.close(); break;

                case Keyboard::A:    leftFlag=true; break;
                case Keyboard::D:   rightFlag=true; break;
                case Keyboard::W:     upFlag=true;break;
                case Keyboard::S:    downFlag=true;break;
                default : break;
            }
        }

        if (event.type == ::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case Keyboard::A:    leftFlag=false; break;
                case Keyboard::D:   rightFlag=false; break;
                case Keyboard::W:     upFlag=false; break;
                case Keyboard::S:    downFlag=false; break;

                default : break;
            }
        }



    }


}

