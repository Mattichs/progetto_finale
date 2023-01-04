//@FedericoCognolatto
#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "movement.h"

class grid {
    protected:
        char matrix[12][12];
    public:
        grid();
        virtual ~grid();
        virtual bool fire(coords c);
};
#endif