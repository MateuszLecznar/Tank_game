#ifndef ITEMS_H
#define ITEMS_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

class Items
{
public:
    Items(float width, float height,std::string HP,int gracz);


    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu;

};

#endif // ITEMS_H
