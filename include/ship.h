#ifndef SHIP_H
#define SHIP_H

#include "movement.h"
#include <utility>
#include <vector>

class ship{
		protected:
			asset way = asset::Horizontal;
			char alias {' '}; //Char that represent the type of ship (C | S | E) and hp (lowercase | UPPERCASE) in grid output
			std::vector<short> hp; //vector used to change alias in lowercase if ship get hit and to check if the ship is destroyed
			short length; //Length of the ship
			coords center; //Represent the center of the ship in a (short,short) coordinate			
			
		public: 
			ship(asset way, coords& center);
			
			//Get alias for each piece
			char get_alias() const;

			//Get the way (Horizzontal | Vertical) of the ship
			asset get_way() const;

			//Get a vector of short representing the state of each "piece" of the ship
			//0 --> hit, 1 --> not hit
			std::vector<short> get_hp() const;

			//Get the length of the ship
			short get_length() const;
			
			//Change the hp assigned to the "piece" of the ship to 0
			void get_hit(coords&);

			//Get the center of the ship	
			coords get_center() const;

			//Check the vector hp, if all shorts are 0 the ship is "dead"
			bool is_dead();	

			//"Restore" hp assigning 1 to all shorts
			void heal();

			//Return the alias of the ship (lowercase --> hit | UPPERCASE --> not hit)
			char print(coords&);
};
#endif