#include "player.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include <vector>
#include<ctime>
#include<iostream>



Player:: Player(sf::Texture& animationSheet) {
    this->setTexture(animationSheet);
    this->direction = sf::Vector2f(0, 1);
    this->rotation = 0;

    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setOutlineThickness(3.f);
   this->hitbox.setFillColor(sf::Color::Transparent);
};

void Player::addAnimation(const float framerate,
    const int start_frame_x, const int start_frame_y,
    const int length, const int frame_width, const int frame_height) {

    this->framerate = framerate;
    this->width = frame_width;

    this->startRect = sf::IntRect(start_frame_x * frame_width, start_frame_y * frame_height,frame_width, frame_height);
    this->currentRect = this->startRect;

    this->endRect = sf::IntRect(
        start_frame_x * frame_width + frame_width * (length - 1),
        (start_frame_y)*frame_height,
        frame_width, frame_height);

    this->setTextureRect(this->startRect);

}
void Player::playAnimation(const float& dt) {
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


void Player::moveSprite(const int dir, const float& dt) {

      this->move(this->direction * (this->maxVelocity *dir * dt));

  }

void Player::rotateSprite(const int dir, const float& dt) {
      float rot = this->rotationSpeed * dir * dt;
      this->rotation += rot;
      this->rotate(rot);
      this->direction = rotateVector(this->direction, rot);
       this->angel=rot;
  }

void Player::updateCollisions(std::vector<sf::Sprite>& platforms, const float& dt) {

    sf::FloatRect playerBounds = this->getGlobalBounds();

    for (auto& platform : platforms) {

        sf::FloatRect wallBounds = platform.getGlobalBounds();
        if (wallBounds.intersects(playerBounds)) {




            //Bottom collision
            if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left
                )
            {

                this->move(0, wallBounds.top - (playerBounds.top + playerBounds.height));
            }

            //Top Collision
            else if (playerBounds.top > wallBounds.top
                && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left
                )
            {

                this->move(0,  wallBounds.top + wallBounds.height - playerBounds.top  );
            }

            //Right collisin
            if (playerBounds.left < wallBounds.left
                && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top
                )
            {

                this->move(wallBounds.left - (playerBounds.left + playerBounds.width), 0);
            }

            //Left Collision
            else if (playerBounds.left > wallBounds.left
                && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top
                )
            {

                this->move(wallBounds.left + wallBounds.width - (playerBounds.left ), 0);
            }
        }


    }
        }
void Player::update(const float& dt) {

//        this->hitbox.setPosition(this->getPosition());
//        this->hitbox.setOrigin(this->getOrigin());
    this->hitbox.setPosition(this->getGlobalBounds().left,this->getGlobalBounds().top);
    this->hitbox.setSize(sf::Vector2f(this->getGlobalBounds().width,this->getGlobalBounds().height));


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

        //ilaretion
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

sf::Vector2f normalize(sf::Vector2f& vector)
{
    return vector / (float)sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

sf::Vector2f Player::rotateVector(const sf::Vector2f& org, const float rotation)
{
    sf::Vector2f rotated;
    double deg = (M_PI / 180) * rotation;

    rotated.x = cos(deg) * org.x - sin(deg) * org.y;
    rotated.y = sin(deg) * org.x + cos(deg) * org.y;
    return normalize(rotated);

}

