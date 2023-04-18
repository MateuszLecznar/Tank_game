#include "boom.h"
#include "bullet.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"player.h"
#include<cmath>
#include <vector>
#include<ctime>
Boom::Boom(sf::Texture& animationSheet,Player &hero)
{
        this->setTexture(animationSheet);
       setPosition(hero.getPosition().x-46,hero.getPosition().y-46);
       setScale(0.7,0.7);

        //setOrigin(24,25);
};
Boom::Boom(sf::Texture& animationSheet,sf::Sprite &bul)
{
        this->setTexture(animationSheet);
       setPosition(bul.getPosition().x-26,bul.getPosition().y-26);
       setScale(0.7,0.7);

        //setOrigin(24,25);
};

void Boom :: playAnimation(float dt)
{
    this->timer += dt;

    if (this->timer > 1 / this->framerate) {
        this->timer = 0.f;

        if (this->currentRect != this->endRect) {
            this->currentRect.left += this->width;
        }
        else {
            this->currentRect = this->startRect;
        }
        this->setTextureRect(this->currentRect);
    }
}

void Boom :: addAnimation(float framerate,
    const int start_frame_x, const int start_frame_y,
    const int length, const int frame_width, const int frame_height) {

    //start_frame_x - on which column animation starts
    //start_frame_y - on which row animation stars
    //length - how many frames there are in animation
    //frame_width/height - dimesns of single frame

    this->framerate = framerate;
    this->width = frame_width;

    this->startRect = sf::IntRect(start_frame_x * frame_width, start_frame_y * frame_height,
        frame_width, frame_height);
    this->currentRect = this->startRect;

    this->endRect = sf::IntRect(
        start_frame_x * frame_width + frame_width * (length -1),
        (start_frame_y) * frame_height,
        frame_width, frame_height);

    this->setTextureRect(this->startRect);

}
