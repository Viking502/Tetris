#ifndef L_POLYOMINO_H
#define L_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class L_polyomino
    :public Tetrimino
{
    public:
        L_polyomino();
        virtual ~L_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // L_POLYOMINO_H
