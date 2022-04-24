#ifndef CPP_MSMOUSEBUTTONPRESSED_H
#define CPP_MSMOUSEBUTTONPRESSED_H

namespace sf{
    class Event;
}

class MinesweeperBoard;
class MSSFMLView;

class MSMouseButtonPressed {
    MinesweeperBoard &board;
    MSSFMLView &view;

public:
    MSMouseButtonPressed(MinesweeperBoard &board, MSSFMLView &view);
    void Events(sf::Event &event);
};




#endif //CPP_MSMOUSEBUTTONPRESSED_H
