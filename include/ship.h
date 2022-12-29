#ifndef SHIP_H
#define SHIP_H

#include "movement.h"
#include <utility>
#include <vector>

class ship{
		protected:
			asset way = asset::Horizontal;
			char alias {' '};
			std::vector<short> hp;
			short length;
			coords center; //Userei il primo numero per la riga e il secondo per la colonna			
			
		public: 
			ship(asset way, coords& center);
			
			char get_alias() const;
			asset get_way() const;
			std::vector<short> get_hp() const;
			short get_length() const;
			void get_hit(coords&);	
			bool is_dead();	
			void heal();
			char print(coords&);
};
#endif