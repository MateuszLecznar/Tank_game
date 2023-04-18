#ifndef BOOM_H
#define BOOM_H
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<cmath>
#include <vector>
#include<ctime>
#include<iostream>
#include"player.h"
#include"bullet.h"


class Boom:public sf::Sprite
{
public:
    Boom(sf::Texture& animationSheet,Player &hero);
    Boom(sf::Texture& animationSheet,sf::Sprite &bul);

    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;
     float timer = 0.f;
     float framerate = 0.f;
     int startFrameX = 0;
     int startFrameY = 0;
     int length = 0;
     int width = 0;
     int height = 0;



    void playAnimation( float dt);

void addAnimation(const float framerate,
    const int start_frame_x, const int start_frame_y,
    const int length, const int frame_width, const int frame_height);
};
#endif // BOOM_H
