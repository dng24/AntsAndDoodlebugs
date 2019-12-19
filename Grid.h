/*
 * Grid.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"

class Grid {
public:
	Grid(int nSquaresOnASide = 20);
	occupationStatus getCellOccupant(int r, int c);
	void setCellOccupant(int r, int c, occupationStatus g, Organism* o_ptr);
	Organism* getCellOccupantPtr(int r, int c);
	void initGrid(int gridSize, int numAnts, int numDoodlebugs);
	void printGrid();
	virtual ~Grid();

private:
	int n; //number of Cells on an edge of the Grid
	Cell** cellArrPtr; //pointer to arrays of Cells; the Grid
};

#endif /* GRID_H_ */
