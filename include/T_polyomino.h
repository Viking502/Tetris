#ifndef T_POLYOMINO_H
#define T_POLYOMINO_H
#include "Tetrimino.h"
#include <iostream>

class T_polyomino
    :public Tetrimino
{
    public:
        T_polyomino();
        virtual ~T_polyomino();

        bool rotation(Blocks_net &blocks_net,std::string direction);    //virtual

    protected:

    private:
};

#endif // T_POLYOMINO_H
