#ifndef CPP_MSBOARDTEXTVIEW_H
#define CPP_MSBOARDTEXTVIEW_H
#include "MineSweeperBoard.h"
class MSBoardTextView{
    MinesweeperBoard &board;
public:
    MSBoardTextView(MinesweeperBoard &board);
    void display() const;
};
#endif
