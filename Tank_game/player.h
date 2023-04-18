     #ifndef PLAYER_H
#define PLAYER_H
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<cmath>
#include <vector>
#include<ctime>
#include<iostream>


class Player: public sf::Sprite
{
public:

      int HP=100;
      std::string strHP=std::to_string(HP);
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
      sf::RectangleShape hitbox;

  Player(sf::Texture& animationSheet);

  void addAnimation(const float framerate, const int start_frame_x, const int start_frame_y,const int length, const int frame_width, const int frame_height) ;

  void playAnimation(const float& dt);

  void moveSprite(const int dir, const float& dt);

  void rotateSprite(const int dir, const float& dt);

  void updateCollisions(std::vector<sf::Sprite>& platforms, const float& dt);

  void update(const float& dt);

  sf::Vector2f rotateVector(const sf::Vector2f& org, const float rotation);

};
#endif // PLAYER_H
