#ifndef CPP_MSTEXTCONTROLLER_H
#define CPP_MSTEXTCONTROLLER_H
#include "MineSweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController:  public MinesweeperBoard{
    MinesweeperBoard &board;
    MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
    MSTextController();
    void play();
};

#endif //CPP_MSTEXTCONTROLLER_H
