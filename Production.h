/*
 * Production.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include "Grid.h"

class Production {
public:
	Production(int argc, char* argv[]);
	bool runProduction();
	bool oneDoodlebugStep(Grid* g, int r, int c);
	bool oneAntStep(Grid* g, int r, int c);
	virtual ~Production();

private:
	int gridSize; //number of Cells on one edge
	int numDoodlebugs; //initial number of Doodlebugs
	int numAnts; //initial number of Ants
	int numTimeSteps; //Maximum time steps to run program
	int seed; //seed for random number generator
	int pause; //number of before printing Grid
};

#endif /* PRODUCTION_H_ */
