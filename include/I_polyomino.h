#ifndef I_POLYOMINO_H
#define I_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class I_polyomino
    :public Tetrimino
{
    public:
        I_polyomino();
        virtual ~I_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // I_POLYOMINO_H
