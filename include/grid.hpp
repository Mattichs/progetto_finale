#ifndef GRID.H
#define GRID.H
#include <iostream>

class grid{
    protected:
        char matrix[12][12];
    public:
         virtual bool fire(coords c);
};
#endif