#include <iostream>
#include "MineSweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSMouseButtonPressed.h"
#include "SFML/Graphics.hpp"
using namespace std;

void intro(){
  cout << "Alicja Jagoda, XXXX96" << endl;
}
int main() {
// intro();
//  MinesweeperBoard board_size(2, 2, GameMode::DEBUG);
//  MSBoardTextView view(board_size);
//  MSTextController ctrl(board_size, view);
//  board_size.debug_display() ;
//  ctrl.play();
//  board_size.debug_display() ;

// //////////////////////////////////////////////////////////////////////////
        int w =10;//Max size is 20/20
        int h=10;
        int sq_size=40;
        sf::RenderWindow window(sf::VideoMode(w*sq_size*1.3, h*sq_size*1.3), "Grafika w C++/SFML");
        window.setVerticalSyncEnabled(false);
        window.setFramerateLimit(30);

        MinesweeperBoard board(w, h, EASY);
        MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora
        MSMouseButtonPressed ctrl(board,view);
        // symulujemy rozgrywkę
//        board.toggleFlag(0,0);
//        board.revealField(2,3);

        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
                continue;
            }
            ctrl.Events(event);
            window.clear();
            view.draw(window);
            window.display();
        }

// /////////////////////////////////////////////////////////////////////////
        return 0;

}