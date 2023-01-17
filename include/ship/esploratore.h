#ifndef ESPLORATORE_H
#define ESPLORATORE_H

#include "ship.h"

/*
*@file esploratore.h
*@author Christian Poli (christian.poli.1@studenti.unipd.it)
*
*@brief The interface of the ship "esploratore"
*
*@date 17-01-2023 
*
*/

class esploratore : public ship {
	public:
		esploratore(coords&);
		esploratore() {}
};

#endif