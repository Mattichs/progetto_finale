#ifndef CORAZZATA_H
#define CORAZZATA_H

#include "ship.h"

/**
 * 
 * @file corazzata.h
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief This interface consists in the creation of specific ship corazzata
 * 
 * @date 2023-01-17 
 * 
*/

class corazzata : public ship {
	public:
		corazzata(asset, coords&);
		corazzata() {}
};


#endif