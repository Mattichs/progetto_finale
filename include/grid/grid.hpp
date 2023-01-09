//@FedericoCognolatto
#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "../ship/movement.h"

class grid {
    protected:
        char matrix[12][12];
    public:
        grid();
        virtual ~grid();
<<<<<<< HEAD
        virtual bool fire(coords c);
=======
        virtual bool fire(coords& c);
>>>>>>> 4b8640c57311ef8cb9696297caa21ed7d520d284
};
#endif