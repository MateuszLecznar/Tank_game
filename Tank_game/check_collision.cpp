#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include <vector>
#include<ctime>
#include<iostream>
#include"player.h"
#include"bullet.h"
#include"boom.h"
#include <SFML/Audio.hpp>



void check_bomb_collision(Player &hero1,sf::Texture &heroAnimationSheet1,std::vector<sf::Sprite> walls,std::vector<bullet>&bomba,sf::Texture &explosionTexture,std::vector<Boom>&explosiaa){

    for(auto enemy=bomba.begin();enemy!=bomba.end();)
    {
        bool add=false;
        //auto b=*enemy;
        if((*enemy).getGlobalBounds().intersects(hero1.getGlobalBounds()))
        {
           enemy= bomba.erase(enemy);
           hero1.HP-=20;
            hero1.strHP=std::to_string(hero1.HP);
           // heroAnimationSheet1.loadFromFile("KV-2_previewdestroyed.png");
            Boom explosion(explosionTexture,hero1);
            explosion.addAnimation(10,0,0,9,96,96);
            explosiaa.emplace_back(explosion);




         add=true;
        }
         if(add==false){
        for(auto wall:walls){

            if((*enemy).getGlobalBounds().intersects(wall.getGlobalBounds())&&add==false){

                enemy= bomba.erase(enemy);
                Boom explosion(explosionTexture,wall);
                explosion.addAnimation(10,0,0,9,96,96);
                explosiaa.emplace_back(explosion);

                add=true;
            }}};

if(add==false){
            enemy++;}}}

void check_bomb_collision1(Player &hero,sf::Texture &heroAnimationSheet1,std::vector<sf::Sprite> walls,std::vector<bullet>&bomba1,sf::Texture &explosionTexture,std::vector<Boom>&explosia){
    for(auto enemy=bomba1.begin();enemy!=bomba1.end();)
    {
        bool add=false;
        //auto b=*enemy;
        if((*enemy).getGlobalBounds().intersects(hero.getGlobalBounds()))
        {
           enemy= bomba1.erase(enemy);
           hero.HP-=20;
           hero.strHP=std::to_string(hero.HP);
        // heroAnimationSheet1.loadFromFile("KV-2_previewdestroyed.png");
         Boom explosion(explosionTexture,hero);
          explosion.addAnimation(10,0,0,9,96,96);
         explosia.emplace_back(explosion);
         add=true;
        }
         if(add==false){
        for(auto wall:walls){

            if((*enemy).getGlobalBounds().intersects(wall.getGlobalBounds())&&add==false){

                enemy= bomba1.erase(enemy);
                Boom explosion(explosionTexture,wall);
                 explosion.addAnimation(10,0,0,9,96,96);
                explosia.emplace_back(explosion);
                add=true;
            }}};

if(add==false){
            enemy++;}}}
