#include <iostream>
#include "MineSweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSSFMLView.h"
#include "MSTextController.h"
void MinesweeperBoard::clear_all(){

    for (int row = 0; row < width; row++){
        for (int col = 0; col< height; col++){

            board[row][col]= {0,0,0};
        }
    }
}

MinesweeperBoard::MinesweeperBoard(){
    width = 9;
    height = 9;

    clear_all();
}

MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode){
    width = w;
    height = h;

    int points=width*height;
    if(mode==EASY){FillBoardEasy();}
    if(mode==NORMAL){FillBoardNormal();}
    if(mode==HARD){FillBoardHard();}
    if(mode==DEBUG){FillBoardDebug();}
    this->first_action=true;
//   GameMode::EASY==points*0.1;
//   GameMode::NORMAL==points*0.2;
//   GameMode::HARD==points*0.3;
}
bool MinesweeperBoard::OnBoard(int row, int col)const {
    if (row >= 0 && col >= 0) {
        if (row < height && col < width){
            return true;
        }
        else return false;
    }
    else return false;
}
int MinesweeperBoard::get_width() const{
    return width;
}
int MinesweeperBoard::get_height() const{
    return height;
}
void MinesweeperBoard::FillBoardEasy() {
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++){
            if(rand()%10 == 0){
                this->board[row][col].hasMine = true;
            }
        }
    }
}
void MinesweeperBoard::FillBoardNormal() {
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++){
            if(rand()%5 == 0){
                this->board[row][col].hasMine = true;
            }
        }
    }
}
void MinesweeperBoard::FillBoardHard() {
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++){
            if(rand()%3 == 0){
                this->board[row][col].hasMine = true;
            }
        }
    }
}
void MinesweeperBoard::FillBoardDebug() {
    for (int row = 0; row < width; row++){
        for (int col = 0; col< height; col++){
            if(row==col){board[row][col].hasMine=1;}
            if(row==0){board[row][col].hasMine=1;}
            if((col==0)&(row%2==0)){board[row][col].hasMine=1;}
        }
    }
}

int MinesweeperBoard::getMineCount(int row, int col) const{
    int top, right, bottom, left;
    if(board[row-1][col].hasMine== true && row<height && col<width){
        top=1;
    } else {top=0;}

    if (board[row+1][col].hasMine== true && row<height && col<width){
        bottom=1;
    } else {bottom=0;}

    if (board[row][col-1].hasMine== true && row<height && col<width){
        left=1;
    } else {left=0;}

    if (board[row][col+1].hasMine== true && row<height && col<width){
        right=1;
    } else {right=0;}

    return top+bottom+left+right;
}

int MinesweeperBoard::countMines(int row, int col) const{
    //cout << "Licznik Min: " << endl;
    int counter=0;
    for (int row=0; row<height; row++){
        for(int col=0; col<width; col++){
            if(board[row][col].isRevealed==false) return -1;
            else if((row>height)&&(row<0)&&(col<0)&&(col>width)) return -1;
            else if(board[row][col].hasMine==true) counter++;
//            return counter;
        }
    }
    return counter;
}
bool MinesweeperBoard::hasFlag(int row, int col) const{
    if(OnBoard(row,col!=true))return 0;
    if(board[row][col].hasFlag==true) return 1;
    if((row>height)&&(row<0)&&(col<0)&&(col>width)) return 0;
    if(board[row][col].hasFlag==false) return 0;
    if(board[row][col].isRevealed==true) return 0;
    return  0;
}
void MinesweeperBoard::toggleFlag(int row, int col){

    if(OnBoard(row,col)!=true);
    else if(board[row][col].isRevealed==true);
    else if(this->getGameState()==FINISHED_WIN or this->getGameState()==FINISHED_LOSS);
   else  if(board[row][col].isRevealed==false){board[row][col].hasFlag=true;}


}


bool MinesweeperBoard::isRevealed(int row, int col) const{

    if(board[row][col].isRevealed==true){return true;}
    return false;

}

void MinesweeperBoard::revealField(int row, int col){

    if (OnBoard(row, col)!=true);


        if((board[row][col].isRevealed==false)&&(board[row][col].hasMine==false)){board[row][col].isRevealed=true;}
        if((board[row][col].isRevealed==false)&&(board[row][col].hasMine==true)){
            // 1if ; First choice, mine changes field
            // 2 ; if reveal and finish
            board[row][col].isRevealed=true;getGameState();
        }




}

GameState MinesweeperBoard::getGameState() const {
    int CountS, CountF;
    int row,col;
    for (row=0; row<height; row++){
        for(col=0; col<width; col++){
            if((board[row][col].hasMine==true)&&(board[row][col].isRevealed==true)) return FINISHED_LOSS;

            if((board[row][col].isRevealed== true)&&(board[row][col].hasMine==false)) CountS++;
        }
    }
    if((CountS == countMines(row,col))&&(CountS==width*height-countMines(row,col)))return FINISHED_WIN;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const{
    if (OnBoard(row, col)!=true){return '#';}
    if((board[row][col].isRevealed==false)&&(board[row][col].hasFlag==true)){return 'F';}
    if((board[row][col].isRevealed==false)&&(board[row][col].hasFlag==false)){return ' ';}
    if((board[row][col].isRevealed==true)&&(board[row][col].hasMine==true)){return 'X';}

   // if(board[row][col].isRevealed==true && getMineCount(row, col)==0){return ' ';} // Has zero mines around
    if(board[row][col].isRevealed==true  && getMineCount(row, col) != 0){return getMineCount(row, col)+'0';} // "d" as digit, number of mines around

}
void MinesweeperBoard::debug_display() const{
    std::cout<<"   ";
    for (int n=0; n<width; n++){
        std::cout<<n+1<<"    ";
    }
    std::cout<<std::endl;
    for (int row=0; row<height; row++){
        std::cout<< row+1;
        for(int col=0; col<width; col++){
            std::cout<<"[";
            if ( board[row][col].hasMine==true )
                std::cout<<"M";
            else
                std::cout<<".";

            if ( board[row][col].isRevealed==true )
                std::cout<<"O";
            else
                std::cout<<".";

            if ( board[row][col].hasFlag==true )
                std::cout<<"F";
            else
                std::cout<<".";
            std::cout<<"]";
        }
        std::cout<<std::endl;
    }
}


