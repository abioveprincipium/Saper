#ifndef CPP_MSSFMLVIEW_H
#define CPP_MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"

// docelowo - to MUSI być w osobnych plikach - tak jak klasa MinesweeperBoard !
class MSSFMLView
{
    MinesweeperBoard & board;
    sf::RectangleShape sq; // wyrysowanie jednego pola
    sf::RectangleShape sq_r; //revealed fild
    sf::CircleShape bomb;
    sf::CircleShape flag;
    sf::Font font; //ustawinie czcionki
    sf::Text saper;
    sf::Text won;
    sf::Text lost;
    sf::Text n1,n2,n3,n4;

    //Realne pole planszty w px
    int sq_size = 40;
    int px_board_w = board.get_width()*sq_size;
    int px_board_h = board.get_height()*sq_size;
    int OfX=px_board_w*0.15; //ofset
    int OfY=px_board_h*0.15;


public:
    explicit MSSFMLView(MinesweeperBoard & b);

    void draw (sf::RenderWindow & win);
};







#endif //CPP_MSSFMLVIEW_H
