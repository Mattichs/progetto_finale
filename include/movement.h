#ifndef MOVEMENT.H
#define MOVEMENT.H

#include "ship.h"

#include <utility>
#include <vector>

enum class asset {Vertical, Horizontal};
typedef std::pair<short, short> coords; //Userei il primo numero per la riga e il secondo per la colonna
typedef std::pair<char,short> input;

class movement : public ship{
    protected:
            asset way = asset::Horizontal;
            coords center;
            //coords position;
            input totranslate;

    public:
            asset get_way() const;

            coords coords_translation(input){}
            std::vector<coords> get_position(coords center, short length, asset way){}

};

#endif