#ifndef GRID.H
#define GRID.H
#include <iostream>

class grid{
    protected:
        char matrix[12][12];
    public:
        grid();
         virtual bool fire(coords c);
         friend std::ostream operator <<(const std::ostream& os,const grid&);
}
std::ostream operator <<(const std::ostream& os,const grid&);
#endif