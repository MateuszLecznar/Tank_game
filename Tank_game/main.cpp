#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<cmath>
#include <vector>
#include<ctime>
#include<iostream>
#include"player.h"
#include"bullet.h"
#include"items.h"
#include "boom.h"
//include <Keyboard.hpp>
#include <SFML/Audio.hpp>

std::vector<sf::Sprite> generateWalls(sf::Texture &texture) {
    std::vector<sf::Sprite> walls;
    int position_x = 0;
    int position_y = -130;

    for (int a = 0; a < 4; a++) {
        position_y += 220;
        for (int i = 0; i < 6; i++) {
            position_x += 200;
            sf::Sprite w1;
            w1.setTexture(texture);
            w1.setPosition(position_x, position_y);
            w1.setScale(0.5, 0.7);
            w1.setTextureRect(sf::IntRect(0, 0, w1.getGlobalBounds().width, w1.getGlobalBounds().height));
            walls.emplace_back(w1);
        }
        position_x = 0;
    }
    return walls;
}

std::vector<bullet> bomba;
std::vector<bullet> bomba1;
std::vector<Boom> explosia;

void check_bomb_collision(Player &hero1, sf::Texture &heroAnimationSheet1, std::vector<sf::Sprite> walls,
                          std::vector<bullet> &bomba, sf::Texture &explosionTexture, std::vector<Boom> &explosia);

void check_bomb_collision1(Player &hero1, sf::Texture &heroAnimationSheet1, std::vector<sf::Sprite> walls,
                           std::vector<bullet> &bomba1, sf::Texture &explosionTexture, std::vector<Boom> &explosia);

int m = 0;
int map1 = 0;
int map2 = 0;


int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1500, 900), "Window");
    window.setVerticalSyncEnabled(true);
    sf::Event sfEvent;
    sf::Clock clock;
    float dt;
    //Making walls
    sf::Texture wallTexture;
    if (!wallTexture.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/wall111.png")) { return -1; }
    wallTexture.setRepeated(true);

    std::vector<sf::Sprite> walls = generateWalls(wallTexture);

    //Background
    sf::Texture grassTexture;
    if (!grassTexture.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/grass.jpg")) { return -1; }
    grassTexture.setRepeated(true);
    grassTexture.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(grassTexture);
    wall.setPosition(0, 0);
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    //Player character
    sf::Texture heroAnimationSheet;

    if (!heroAnimationSheet.loadFromFile(
            "/media/mateusz/Data/C++_projects/Game/Tank_game/M-6_preview.png")) { return -1; };

    sf::Texture heroAnimationSheet1;
    if (!heroAnimationSheet1.loadFromFile(
            "/media/mateusz/Data/C++_projects/Game/Tank_game/KV-2_preview.png")) { return -1; };

    sf::Texture explosionTexture;
    if (!explosionTexture.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/Explosion.png")) { return -1; };

    sf::Music music;
    if (!music.openFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/the high brass.ogg"))
        return -1; // error
    music.setLoop(true);
    music.setVolume(40);
    music.play();


    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/De1athFlash.flac")) { return -1; }

    sf::SoundBuffer buffer1;
    if (!buffer1.loadFromFile(
            "/media/mateusz/Data/C++_projects/Game/Tank_game/synthetic_explosion.flac")) { return -1; }


    sf::SoundBuffer engine;
    if (!engine.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/tank1.wav")) { return -1; }
    sf::SoundBuffer engine1;
    if (!engine1.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/tank.wav")) { return -1; }


    sf::Sound shot;
    shot.setBuffer(buffer);
    shot.setPitch(0.6);
    shot.setVolume(100);


    sf::Sound shot1;
    shot1.setBuffer(buffer1);
    shot1.setPitch(0.6);
    shot1.setVolume(100);

    sf::Sound enginee;
    enginee.setBuffer(engine);
    enginee.setVolume(50);


    sf::Sound enginee1;
    enginee1.setBuffer(engine1);
    enginee1.setVolume(50);


    Player hero(heroAnimationSheet);
    Player hero1(heroAnimationSheet1);

    hero.setPosition(80, 80);
    hero1.setPosition(1350, 750);


    hero.setScale(0.4, 0.4);
    hero1.setScale(0.4, 0.4);


    hero.setOrigin(55, 100);
    hero1.setOrigin(66, 107);


    sf::Texture pocisk1;
    if (!pocisk1.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/pocisk.png")) { return -1; };
    sf::Texture pocisk;
    if (!pocisk.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/shield.png")) { return -1; };
    pocisk.setSrgb(true);

    sf::Texture win;
    if (!win.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/win_1.png")) { return -1; }
    sf::Sprite winner;
    winner.setTexture(win);
    winner.setPosition(0, 0);

    sf::Texture win1;
    if (!win.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/win_2.png")) { return -1; }
    sf::Sprite winner1;
    winner1.setTexture(win1);
    winner1.setPosition(0, 0);

    sf::Texture front;
    if (!front.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/menu.png")) { return -1; }
    sf::Sprite fronte;
    fronte.setTexture(front);
    fronte.setPosition(0, 0);


    while (window.isOpen() && m == 0) {

        while (window.pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                m = 1;
                map1 = 1;
            }
            window.draw(fronte);
            window.display();


        }
    }


    while (map1 == 1 && window.isOpen()) {

        while (window.pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed) {
                window.close();
            }
        }



        dt = clock.restart().asSeconds();


        bool sound = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            hero1.rotateSprite(-1, dt);
            if (enginee.getStatus() != sf::Sound::Playing) {
                enginee.setLoop(true);
                enginee.play();
                sound = true;
            }
        } else {
            enginee.setLoop(false);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hero1.rotateSprite(1, dt);

            if (enginee.getStatus() != sf::Sound::Playing) {
                enginee.setLoop(true);
                enginee.play();
                sound = true;
            }
        } else {
            enginee.setLoop(false);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            hero1.moveSprite(1, dt);
            if (enginee.getStatus() != sf::Sound::Playing) {
                enginee.setLoop(true);
                enginee.play();
                sound = true;
            }
        } else {
            enginee.setLoop(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            hero1.moveSprite(-1, dt);

            if (enginee.getStatus() != sf::Sound::Playing) {
                enginee.setLoop(true);
                enginee.play();
                sound = true;
            }
        } else {
            enginee.setLoop(false);
        }

        if (sound == false) {
            enginee.pause();
        }


        bool sound1 = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            hero.moveSprite(-1, dt);
            if (enginee1.getStatus() != sf::Sound::Playing) {
                enginee1.setLoop(true);
                enginee1.play();
                sound1 = true;
            }
        } else { enginee1.setLoop(false); }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            hero.moveSprite(1, dt);
            if (enginee1.getStatus() != sf::Sound::Playing) {
                enginee1.setLoop(true);
                enginee1.play();
                sound1 = true;
            }
        } else { enginee.setLoop(false); }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            hero.rotateSprite(1, dt);
            if (enginee1.getStatus() != sf::Sound::Playing) {
                enginee1.setLoop(true);
                enginee1.play();
                sound1 = true;
            }
        } else { enginee.setLoop(false); }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            hero.rotateSprite(-1, dt);
            if (enginee1.getStatus() != sf::Sound::Playing) {
                enginee1.setLoop(true);
                enginee1.play();
                sound1 = true;
            }
        } else { enginee1.setLoop(false); }


        if (sound1 == false) {
            enginee1.pause();
        }



        //Updating player
        hero.playAnimation(dt);
        hero.updateCollisions(walls, dt);
        hero.update(dt);
        hero1.playAnimation(dt);
        hero1.updateCollisions(walls, dt);
        hero1.update(dt);
        //Rendering
        window.clear();
        window.draw(wall);
        window.draw(hero);
        window.draw(hero1);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            if (hero.prime == true) {
                bullet ogien(pocisk, hero);
                bomba.emplace_back(ogien);
                shot.play();
                hero.prime = false;
            }
        } else hero.prime = true;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

            if (hero1.prime == true) {
                bullet ogien1(pocisk1, hero1);
                bomba1.emplace_back(ogien1);
                shot1.play();
                hero1.prime = false;
            }
        } else hero1.prime = true;


        for (auto &b: bomba) {
            b.moveSprite(3, dt);
            window.draw(b);


        }
        for (auto &b: bomba1) {
            b.moveSprite(3, dt);
            window.draw(b);

        }
        for (auto wall: walls) {
            window.draw(wall);
        }


        if (!bomba.empty() || !bomba1.empty()) {
            check_bomb_collision(hero1, heroAnimationSheet1, walls, bomba, explosionTexture, explosia);
            check_bomb_collision1(hero, heroAnimationSheet, walls, bomba1, explosionTexture, explosia);
        }


        if (!explosia.empty()) {

            for (auto &fire: explosia) {
                fire.playAnimation(dt);

                window.draw(fire);
            }

            for (auto fire = explosia.begin(); fire != explosia.end();) {
                if ((*fire).currentRect == (*fire).endRect) {
                    fire = explosia.erase(fire);


                } else fire++;
            }


        }


        Items HP(50, 20, hero.strHP, 1);
        Items HP1(1150, 20, hero1.strHP, 2);
        window.draw(HP.menu);
        window.draw(HP1.menu);

        if (hero.HP < 20 or hero1.HP < 20) {
            m = 0;
            map1 = 0;

        }
        window.display();
    }

    while (m == 0&&window.isOpen()) {

        while (window.pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed) {
                window.close();
            }
            if (hero.HP<10){
                window.draw(winner1);}
            else{
                window.draw(winner);
            }

            window.display();


        }
    }


    return 0;

}
