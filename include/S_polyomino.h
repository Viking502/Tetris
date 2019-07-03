#ifndef S_POLYOMINO_H
#define S_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class S_polyomino
    :public Tetrimino
{
    public:
        S_polyomino();
        virtual ~S_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // S_POLYOMINO_H
