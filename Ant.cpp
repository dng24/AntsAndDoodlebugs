/*
 * Ant.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#include "Ant.h"

/**
 * Constructs an Ant and stores the given row and column.
 * @param r Row to place Ant
 * @param c Column to place Ant
 * @param s true if the Ant should be skipped;
 * 			 false otherwise
 */
Ant::Ant(int r, int c, bool s)
:Organism(r, c, s) {

}

/**
 * Checks if an adjacent Cell is occupied, and if not, randomly selects one and
 * moves to that Cell.
 * @param g The Grid with the Organisms
 * @param n The number of Cells on an edge
 * @return true if Ant moved;
 * 		   false otherwise
 */
bool Ant::move(Grid* g, int n) {
	bool status = true; //keep track of whether the move is successful or not

	moveLocation moveTo = targetCell(g, row, col, n, false); //Get target cell to move to
	origRow = row;
	origCol = col;

	if(moveTo == right || moveTo == down) { //skip Cell that we will visit again
		skip = true;
	} else { //Otherwise it is false
		skip = false;
	}

	switch(moveTo) { //Depending on moveTo, update the position of this Ant
	case stay: //does not move, stays put
		break;
	case up: //moves to the Cell above
		row--;
		break;
	case right: //moves to the Cell to the right
		col++;
		break;
	case down: //move to the Cell below
		row++;
		break;
	case left: //move to the Cell to the left
		col--;
		break;
	}

	if(moveTo != stay) { //unless we didn't move, update the location in the Grid
		g->setCellOccupant(row, col, ant, this); //moves the Ant on the Grid
		g->setCellOccupant(origRow, origCol, empty, nullptr); //sets original Cell to empty
	}
	stepsSinceBreed++; //increment the number of steps since we bred

	return status;
}

/**
 * Gives birth to an Ant in a randomly chosen empty adjacent Cell.
 * Can only give birth after surviving three steps.
 * No birth occurs if all adjacent Cells are occupied.
 * Can give birth on next step if all adjacent Cells are occupied.
 * @param g The Grid with the Organisms
 * @param n The number of Cells on an edge
 * @return true if Ant gave birth;
 * 		   false otherwise
 */
bool Ant::breed(Grid* g, int n) {
	bool status = true; //By default we should be able to breed
	moveLocation breedTo = targetCell(g, row, col, n, false); //target Cell to breed into
	int newRow = -1;
	int newCol = -1;

	//Depending on breedTo, get the row, col values for the new child
	switch(breedTo) {
	case stay: //all adjacent Cells occupied, does not breed
		status = false; //For the cause where we cannot breed
		break;
	case up: //breeds into the Cell above
		newRow = row - 1;
		newCol = col;
		break;
	case right: //breeds into the Cell to the right
		newRow = row;
		newCol = col + 1;
		break;
	case down: //breeds into the Cell below
		newRow = row + 1;
		newCol = col;
		break;
	case left: //breeds into the Cell to the left
		newRow = row;
		newCol = col - 1;
		break;
	}
	if(breedTo != 0) { //As long as we were able to breed
		stepsSinceBreed = 0; //reset the counter
		Ant* a;
		if(newRow < origRow || (newRow == origRow && newCol <= origCol)) {
			a = new Ant(newRow, newCol, false); //doesn't skip Ant if placed before current place in loop
		} else {
			a = new Ant(newRow, newCol, true); //skips Ant if placed after current place in loop
		}
		g->setCellOccupant(newRow, newCol, ant, a);
	}

	return status; //Return whether we were able to breed or not
}

/**
 * Destructs an Ant.
 * Death of Ant occurs when consumed by Doodlebug.
 */
Ant::~Ant() {

}
