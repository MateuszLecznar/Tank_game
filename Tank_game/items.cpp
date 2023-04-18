#include "items.h"




Items::Items(float width, float height,std::string HP,int gracz)
{
    if (!font.loadFromFile("/media/mateusz/Data/C++_projects/Game/Tank_game/HVD_Peace.ttf"))
    {
        // handle error
    }
    std::string player=std::to_string(gracz);
    menu.setFont(font);
    menu.setFillColor(sf::Color(139,0,0));
    menu.setString("Player "+player+"   HP: "+HP);
    menu.setPosition(width,height);
}




