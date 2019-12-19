/*
 * Ant.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"

class Ant: public Organism {
public:
	Ant(int r = 0, int c = 0, bool s = false);
	bool move(Grid* g, int n);
	bool breed(Grid* g, int n);
	virtual ~Ant();
};

#endif /* ANT_H_ */
