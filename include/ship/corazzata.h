#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "ship.h"

/*
*@file corazzata.h
*@author Christian Poli (christian.poli.1@studenti.unipd.it)
*
*@brief The interface of the ship "corazzata"
*
*@date 17-01-2023
*
*/

class corazzata : public ship {
	public:
		corazzata(asset, coords&);
		corazzata() {}
};


#endif