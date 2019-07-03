#ifndef Z_POLYOMINO_H
#define Z_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class Z_polyomino
    :public Tetrimino
{
    public:
        Z_polyomino();
        virtual ~Z_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // Z_POLYOMINO_H
