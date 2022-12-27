#ifndef SHIP_H
#define SHIP_H

#include "movement.h"
#include <utility>
#include <vector>

/*enum class asset {Vertical, Horizontal};
typedef std::pair<int, int> coords;*/

class ship{
		protected:
			//asset way = asset::Horizontal;
			char alias {' '};
			std::vector<short> hp; //
			short length;
			//coords center; //Userei il primo numero per la riga e il secondo per la colonna

			//Si potrebbe anche non dichiararle in realtà
			void place();
			bool action(ship s, coords target);
			bool valid_box(coords target);
			
		public: 
			char get_alias() const;
			//asset get_way() const;
			std::vector<short> get_hp() const;
			short get_length() const;
};
#endif