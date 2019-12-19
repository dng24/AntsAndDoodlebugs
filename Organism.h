/*
 * Organism.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include "Grid.h"

enum moveLocation {stay, up, right, down, left}; //direction that Organism moves or breeds to

class Organism {
public:
	Organism(int r = 0, int c = 0, bool s = false);
	int getRow();
	int getCol();
	bool getSkip();
	void setSkip(bool s);
	int getStepsSinceBreed();
	virtual bool move(Grid* g, int n) = 0;
	virtual bool breed(Grid* g, int n) = 0;
	moveLocation targetCell(Grid* g, int r, int c, int n, bool dMove);
	virtual ~Organism();

protected:
	int row; //current row of an Organism in the Grid
	int col; //current column of an Organism in the Grid
	int stepsSinceBreed; //number of time steps since an Organism has breed
	bool skip; //true if an Organism should be skipped, false otherwise
	int origRow; //row of an Organism before moving
	int origCol; //column of an Organism before moving
};

#endif /* ORGANISM_H_ */
