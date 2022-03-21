#include "engine.hpp"
#include "wall.hpp"
#include <iostream>
const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine(){
    resolution = Vector2f(Map::MAP_SIZE*Map::CELL_SIZE,Map::MAP_SIZE*Map::CELL_SIZE);
    window.create(VideoMode(resolution.x,resolution.y),"Bomber-Man",Style::Default);
    window.setFramerateLimit(FPS);
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

    for(int i=0;i<Map::WALL_QUANTITY;i++){

        Wall wall = map.getWalls()[i];
        window.draw(wall) ;
    }
    window.display();
}
void Engine::input(){
    Event event{};
    while(window.pollEvent(event)){
        if(event.type == Event::Closed){
            window.close();
        }

        if(event.type == Event::KeyPressed){
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }

        }


    }

}