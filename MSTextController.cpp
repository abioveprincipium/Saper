#include <iostream>
#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MineSweeperBoard.h"
#include "MSSFMLView.h"
using namespace std;
MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):board(board), view(view) {
}
void MSTextController::play() {
    int row, col = 0, op;
    do{
       view.display();
       cout<< "Choose: \n 0 to put the flag \n 1 to revealed the field " << endl;
       cin >> op;
       cout<< "\n Write position of the field. \n In row: " << endl;
       cin >> row;
       cout<< "\n In column: " << endl;
       cin >> col;
       if(op==0){
           board.toggleFlag(row, col);
       }
       else  if(op==1){
           board.revealField(row, col);
       }
       else cout << "Chosen option does not match action" << endl;
    }while(board.getGameState()== RUNNING);
    board.debug_display();
    if(board.getGameState()== FINISHED_WIN) cout << "Congrats. You won! " << endl;
    else if (board.getGameState()== FINISHED_LOSS) cout << "Oh no! Try again. " << endl;
}