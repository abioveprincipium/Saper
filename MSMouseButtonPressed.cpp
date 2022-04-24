
#include "MSMouseButtonPressed.h"
#include "SFML/Graphics.hpp"
#include "MineSweeperBoard.h"
#include "MSSFMLView.h"
#include <iostream>


MSMouseButtonPressed::MSMouseButtonPressed(MinesweeperBoard &b, MSSFMLView &v) : board(b), view(v)
{

}

void MSMouseButtonPressed::Events (sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Right){
            std::cout << "toggled" << std::endl;
            std::cout << "x: " << event.mouseButton.x << std::endl;
            std::cout << "y: " << event.mouseButton.y << std::endl;

            int row = (event.mouseButton.y-60)/40;//Odejmuje wartość offsetu+wyśrodkowanie
            int col = (event.mouseButton.x-60)/40;
            board.toggleFlag(row,col);

        }
        if (event.mouseButton.button == sf::Mouse::Left){
            std::cout << "Revealed" << std::endl;
            std::cout << "x: " << event.mouseButton.x << std::endl;
            std::cout << "y: " << event.mouseButton.y << std::endl;

            int row = ((event.mouseButton.y-60)/40);
            int col = ((event.mouseButton.x-60)/40);
            board.revealField( row,col);
        }
    }
}
