#ifndef SUPPORTO_H
#define SUPPORTO_H

#include "ship.h"

/*
*@file supporto.h
*@author Christian Poli (christian.poli.1@studenti.unipd.it)
*
*@brief The interface of the ship "supporto"
*
*@date 17-01-2023 
*
*/

class supporto : public ship {
	public:
		supporto(asset, coords&);
		supporto() {}
};	

#endif