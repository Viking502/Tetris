#ifndef O_POLYOMINO_H
#define O_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class O_polyomino
    :public Tetrimino
{
    public:
        O_polyomino();
        virtual ~O_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // O_POLYOMINO_H
