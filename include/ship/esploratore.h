#ifndef ESPLORATORE_H
#define ESPLORATORE_H

#include "ship.h"

/**
 * 
 * @file esploratore.h
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief This interface consists in the creation of specific ship esploratore
 * 
 * @date 2023-01-17 
 * 
*/

class esploratore : public ship {
	public:
		esploratore(coords&);
		esploratore() {}
};

#endif