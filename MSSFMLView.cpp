#include "MSBoardTextView.h"
#include "MSSFMLView.h"
#include "MSTextController.h"
#include "MineSweeperBoard.h"
MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {

    sq = sf::RectangleShape ( sf::Vector2f(sq_size, sq_size) ) ;
    sq.setFillColor ( sf::Color(14,26,64));

    sq_r = sf::RectangleShape ( sf::Vector2f(sq_size, sq_size) ) ;
    sq_r.setFillColor ( sf::Color(16,52,100));

    bomb = sf::CircleShape(sq_size*0.25);
    bomb.setFillColor(sf::Color(148,107,45));

    flag = sf::CircleShape(sq_size*0.25, 3);
    flag.setFillColor(sf::Color(148,107,45));

    font.loadFromFile("../hp.ttf");
    saper.setFont(font);saper.setString("Saper!");saper.setCharacterSize(60);saper.setFillColor(sf::Color(148,107,45));
    won.setFont(font);won.setString("Congrats. You won!");won.setCharacterSize(60);won.setFillColor(sf::Color(148,107,45));
    lost.setFont(font);lost.setString("Oh no! Try again.");lost.setCharacterSize(60);lost.setFillColor(sf::Color(148,107,45));
    n1.setFont(font);n1.setString("1");n1.setCharacterSize(30);n1.setFillColor(sf::Color(148,107,45));
    n2.setFont(font);n2.setString("2");n2.setCharacterSize(30);n2.setFillColor(sf::Color(148,107,45));
    n3.setFont(font);n3.setString("3");n3.setCharacterSize(30);n3.setFillColor(sf::Color(148,107,45));
    n4.setFont(font);n4.setString("4");n4.setCharacterSize(30);n4.setFillColor(sf::Color(148,107,45));
}
void MSSFMLView::draw (sf::RenderWindow & win){
    // tu robimy rysowanie planszy na podstawie zawartości "board"
    saper.setPosition(px_board_w*0.5,-5);
    won.setPosition(px_board_w*0.25,-5);
    lost.setPosition(px_board_w*0.25,-5);
  //  win.draw(saper);
    //sq_r.setPosition(OfX+(sq_size+1),OfY+(sq_size+1));

    for(int row=0; row < board.get_width(); ++row) {
        for (int col = 0; col < board.get_height(); ++col) {
            sq.setPosition(OfX+(sq_size+1)*col,OfY+(sq_size+1)*row);
            sq_r.setPosition(OfX+(sq_size+1)*col ,OfY+(sq_size+1)*row);
            win.draw(sq);

            bomb.setPosition(OfX+(sq_size+1)*col+10,OfY+(sq_size+1)*row+10);
            flag.setPosition(OfX+(sq_size+1)*col+10,OfY+(sq_size+1)*row+10);
            n1.setPosition(OfX+(sq_size+1)*col+10,OfY+(sq_size+1)*row);
            n2.setPosition(OfX+(sq_size+1)*col+10,OfY+(sq_size+1)*row);
            n3.setPosition(OfX+(sq_size+1)*col+10,OfY+(sq_size+1)*row);
            n4.setPosition(OfX+(sq_size+1)*col+10,OfY+(sq_size+1)*row);



            if(board.getFieldInfo(row,col)==' '){win.draw(sq_r);}
            if(board.getFieldInfo(row,col)=='X'){win.draw(bomb);}
            if(board.getFieldInfo(row,col)=='F'){win.draw(flag);}
            if(board.getFieldInfo(row,col)=='1'){win.draw(n1);}
            if(board.getFieldInfo(row,col)=='2'){win.draw(n2);}
            if(board.getFieldInfo(row,col)=='3'){win.draw(n3);}
            if(board.getFieldInfo(row,col)=='4'){win.draw(n4);}
        }
    }
    //Bomb/Flag check
   // n1.setPosition(110,110);win.draw(n1);flag.setPosition(150,150);win.draw(flag);

    if(board.getGameState()==RUNNING)win.draw(saper);
   else if(board.getGameState()==FINISHED_WIN){win.draw(won);}
    else if(board.getGameState()==FINISHED_LOSS){win.draw(lost);}
}
