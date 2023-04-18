#include "bullet.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"player.h"
#include<cmath>
#include <vector>
#include<ctime>

bullet:: bullet(sf::Texture& animationSheet,Player hero)
{
    this->setTexture(animationSheet);
   setPosition(hero.getPosition());
   setScale(0.06,0.06);
   direction=hero.direction;
    velocity.x=hero.velocity.x+10;
    velocity.y=hero.velocity.y+10;
    setOrigin(24,25);

};
    void bullet::moveSprite(const int dir, const float& dt) {

          this->move(this->direction * (this->maxVelocity *dir * dt));

      }
    void bullet::update(const float& dt) {

    //        this->hitbox.setPosition(this->getPosition());
    //        this->hitbox.setOrigin(this->getOrigin());



        if (this->velocity.x > 0.f) { //if going in right diraction

            //deceleration
            this->velocity.x -= this->deceleration * dt;
            if (this->velocity.x < 0.f)
                this->velocity.x = 0.f;

            //max velocity check
            if (this->velocity.x > this->maxVelocity)
                this->velocity.x = maxVelocity;
        }
        else if (this->velocity.x < 0.f) { //if going left

            //decelaretion
            this->velocity.x += deceleration * dt;
            if (this->velocity.x > 0.f)
                this->velocity.x = 0.f;

            //max velocity check
            if (this->velocity.x < -this->maxVelocity)
                this->velocity.x = -this->maxVelocity;
        }

        if (this->velocity.y > 0.f) { //if going down
        //deceleration y positive
            this->velocity.y -= this->deceleration * dt;
            if (this->velocity.y < 0.f)
                this->velocity.y = 0.f;

            //max velocity check
            if (this->velocity.y > this->maxVelocity)
                this->velocity.y = maxVelocity;
        }
        else if (this->velocity.y < 0.f) { //id going up
            //decelaretion y negative
            this->velocity.y += deceleration * dt;
            if (this->velocity.y > 0.f)
                this->velocity.y = 0.f;

            //max velocity chechk y negative
            if (this->velocity.y < -this->maxVelocity)
                this->velocity.y = -this->maxVelocity;
        }

        //std::cout << this->velocity.x << " | " << this->velocity.y << "\n";
        this->move(this->velocity * dt);
    }


