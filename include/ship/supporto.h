#ifndef SUPPORTO_H
#define SUPPORTO_H

#include "ship.h"

/**
 * 
 * @file supporto.h
 * @author Christian Poli (christian.poli.1@studenti.unipd.it)
 * 
 * @brief This interface consists in the creation of specific ship supporto
 * 
 * @date 2023-01-17
*/

class supporto : public ship {
	public:
		supporto(asset, coords&);
		supporto() {}
};	

#endif