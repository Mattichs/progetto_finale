#ifndef GRID_H
#define GRID_H
#include <iostream>

class grid {
    protected:
        char matrix[12][12];
    public:
         virtual bool fire(coords c);
};
#endif