#ifndef BULLET_H
#define BULLET_H
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<cmath>
#include <vector>
#include<ctime>
#include<iostream>
#include"player.h"

class bullet: public sf::Sprite
{
public:
    float framerate = 0.f;
    int width = 0;
    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;
    float timer = 0.f;
    sf::Vector2f before;
    //movement variables
    sf::Vector2f direction;
    sf::Vector2f velocity;
    float angel;
    float rotation;
    float rotationSpeed = 180.f;
    float maxVelocity = 200.f;
    float acceleration = 4800.f;
    float deceleration = 100;
    bool grounded = false;
    bool prime=false;


    bullet(sf::Texture& animationSheet,Player hero);

    void moveSprite(const int dir, const float& dt);
    void update(const float& dt);
};

#endif // BULLET_H
