#ifndef SHIP_H
#define SHIP_H

#include "movement.h"

/**
 * 
 * @file ship.h
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief This interface consists in the creation of generic ship class
 * 
 * @date 2023-01-17 
 * 
*/

class ship {
		protected:
			asset way = asset::Horizontal;
			char alias {' '}; //Char that represent the type of ship (C | S | E) and hp (lowercase | UPPERCASE) in grid output
			std::vector<short> hp; //vector used to change alias in lowercase if ship get hit and to check if the ship is destroyed
			short length; //Length of the ship
			coords center; //Represent the center of the ship in a (short,short) coordinate			
			
		public: 
			ship() {}
			ship(asset way, coords& center);
			
			//Get alias for each ship (C | E | S)
			char get_alias() const;

			//Get the way (Horizzontal | Vertical) of the ship
			asset get_way() const;

			//Get a vector of short representing the state of each "piece" of the ship (as many pieces as the ship is long)
			//0 --> hit, 1 --> not hit
			std::vector<short> get_hp() const;

			//Get the length of the ship
			short get_length() const;
			
			//Get the center of the ship	
			coords get_center() const;

			//Change the hp assigned to the "piece" of the ship to 0
			void get_hit(coords&);
			
			// Set center of the ship
			void set_center(coords& c);

			//Check the vector hp, if all shorts are 0 the ship is "dead" and the method return true
			bool is_dead();	

			//"Restore" hp assigning 1 to all shorts
			void heal();

			//Return the alias of the ship (lowercase --> hit | UPPERCASE --> not hit)
			char print(coords&, coords&);
};
#endif