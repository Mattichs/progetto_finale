//@FedericoCognolatto
#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "../ship/movement.h"

class grid {
    protected:
        char matrix[12][12];
    public:
        /// @brief default constructor 
        grid();

        /// @brief default destructor
        virtual ~grid();
        virtual bool fire(coords& c);
};
#endif