#ifndef GRID.H
#define GRID.H


class grid{
    protected:
        char grid[12][12];
    public:
         virtual bool fire(coords c);

};
#endif