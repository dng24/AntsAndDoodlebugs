/*
 * Doodlebug.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Grid.h"

class Doodlebug: public Organism {
public:
	Doodlebug(int r = 0, int c = 0, bool s = false);
	int getStepsSinceAte();
	bool move(Grid* g, int n);
	bool breed(Grid* g, int n);
	bool eat(Grid* g);
	virtual ~Doodlebug();

private:
	int stepsSinceAte; //number of time steps since the Doodlebug ate
};

#endif /* DOODLEBUG_H_ */
