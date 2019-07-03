#ifndef J_POLYOMINO_H
#define J_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class J_polyomino
    :public Tetrimino
{
    public:
        J_polyomino();
        virtual ~J_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // J_POLYOMINO_H
