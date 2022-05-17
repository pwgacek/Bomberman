#include "engine.hpp"
#include "map_elements/wall.hpp"
#include <iostream>
const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine(): gameOver(Map::MAP_SIZE*Map::CELL_SIZE,Map::MAP_SIZE*Map::CELL_SIZE),
infoBar(Map::MAP_SIZE*Map::CELL_SIZE,Map::CELL_SIZE,0,Map::MAP_SIZE*Map::CELL_SIZE){

    resolution = Vector2f(Map::MAP_SIZE*Map::CELL_SIZE,(Map::MAP_SIZE+1)*Map::CELL_SIZE);
    window.create(VideoMode((int)resolution.x,(int)resolution.y),
                  "Bomber-Man",Style::Default);
    window.setFramerateLimit(FPS);

    firstPlayerMoveFlags = {{"left",false},{"right",false},{"up",false},{"down",false}};
    secondPlayerMoveFlags = {{"left",false},{"right",false},{"up",false},{"down",false}};

    infoBar.setFirstPlayerHpText(map.getBomberman(1).getHealth());
    infoBar.setSecondPlayerHpText(map.getBomberman(2).getHealth());

    sequence = new Vector2i[Map::MAP_SIZE*Map::MAP_SIZE];
    map.generateSequence(sequence);

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
    if(map.getBomberman(1).getHealth() < 1){
        winner = 2;
        endOfGame = true;
    }
    else if(map.getBomberman(2).getHealth() < 1){
        winner = 1;
        endOfGame = true;
    }

    if(!endOfGame){
        //set direction of bomberman
        map.getBomberman(1).changeDirection(firstPlayerMoveFlags);
        map.getBomberman(2).changeDirection(secondPlayerMoveFlags);
        //move bomberman
        map.move(map.getBomberman(1),firstPlayerMoveFlags,5);
        map.move(map.getBomberman(2),secondPlayerMoveFlags,5);

        //animate bomberman
        if(changeBombermanTextureClock.getElapsedTime().asSeconds() > 0.1){
            changeBombermanTextureClock.restart();
            map.getBomberman(1).changeTexture();
            map.getBomberman(2).changeTexture();

        }

        //animate bomb
        if(bombClock.getElapsedTime().asSeconds() > 0.1){
            bombClock.restart();
            map.animateBombs();
            map.showExplosion();
        }

        // places bomb (max 1 per  sec)
        if(firstPlayerBombFlag && firstPlayerSetBombClock.getElapsedTime().asSeconds() > 1){
            firstPlayerSetBombClock.restart();
            map.setBomb(map.getBomberman(1));
        }

        if(secondPlayerBombFlag && secondPlayerSetBombClock.getElapsedTime().asSeconds() > 1){
            secondPlayerSetBombClock.restart();
            map.setBomb(map.getBomberman(2));
        }
        // check if player is damaged
        if(map.bombermanDamaged(map.getBomberman(1)) && firstPlayerDamagedClock.getElapsedTime().asSeconds()>1){
            firstPlayerDamagedClock.restart();
            map.getBomberman(1).changeHealth(-1);
            infoBar.setFirstPlayerHpText(map.getBomberman(1).getHealth());
        }
        if(map.bombermanDamaged(map.getBomberman(2)) && secondPlayerDamagedClock.getElapsedTime().asSeconds()>1){
            secondPlayerDamagedClock.restart();
            map.getBomberman(2).changeHealth(-1);
            infoBar.setSecondPlayerHpText(map.getBomberman(2).getHealth());
        }
    }
    else{
        if(sequenceIncrementator < Map::MAP_SIZE*Map::MAP_SIZE){
            map.putOneBlock(sequence[sequenceIncrementator++]);
        }


    }

    //draw bombs
    for(const auto & i : map.getBombs()){
        window.draw(i);
    }
    //draw bomberman
    window.draw(map.getBomberman(1));
    window.draw(map.getBomberman(2));

    //draw map elements
    for(int i=0;i<Map::MAP_SIZE*Map::MAP_SIZE;i++){
        window.draw(map.getMapElements()[i]) ;
    }

    //draw gameOverText if all block are put
    if(sequenceIncrementator == Map::MAP_SIZE*Map::MAP_SIZE) {
        window.draw(gameOver.getGameOverText());
        window.draw(gameOver.getWinnerText());
        window.draw(gameOver.getWinnerHead(winner));
    }


    //draw info

    window.draw(infoBar.getFirstPlayerHead());
    window.draw(infoBar.getSecondPlayerHead());
    window.draw(infoBar.getFirstPlayerHpText());
    window.draw(infoBar.getSecondPlayerHpText());


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

                case Keyboard::A:    firstPlayerMoveFlags["left"]=true; break;
                case Keyboard::D:   firstPlayerMoveFlags["right"]=true; break;
                case Keyboard::W:     firstPlayerMoveFlags["up"]=true;break;
                case Keyboard::S:    firstPlayerMoveFlags["down"]=true;break;

                case Keyboard::Left:   secondPlayerMoveFlags["left"]=true; break;
                case Keyboard::Right:   secondPlayerMoveFlags["right"]=true; break;
                case Keyboard::Up:     secondPlayerMoveFlags["up"]=true;break;
                case Keyboard::Down:    secondPlayerMoveFlags["down"]=true;break;

                case Keyboard::V: firstPlayerBombFlag=true;break;
                case Keyboard::M: secondPlayerBombFlag=true;break;

                default : break;
            }
        }

        if (event.type == ::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case Keyboard::A:    firstPlayerMoveFlags["left"]=false; break;
                case Keyboard::D:   firstPlayerMoveFlags["right"]=false; break;
                case Keyboard::W:     firstPlayerMoveFlags["up"]=false; break;
                case Keyboard::S:    firstPlayerMoveFlags["down"]=false; break;

                case Keyboard::Left:    secondPlayerMoveFlags["left"]=false; break;
                case Keyboard::Right:   secondPlayerMoveFlags["right"]=false; break;
                case Keyboard::Up:     secondPlayerMoveFlags["up"]=false; break;
                case Keyboard::Down:    secondPlayerMoveFlags["down"]=false; break;

                case Keyboard::V: firstPlayerBombFlag= false;break;
                case Keyboard::M: secondPlayerBombFlag= false;break;

                default : break;
            }
        }



    }


}

Engine::~Engine() {
    delete [] sequence;
}

