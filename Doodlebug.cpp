/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng
 */

#include "Doodlebug.h"

/**
 * Doodlebug Constructor.
 * @param r Row to initialize Doodlebug
 * @param c Column to initialize Doodlebug
 * @param s true if the Doodlebug should be skipped;
 * 			 false otherwise
 */
Doodlebug::Doodlebug(int r, int c, bool s)
:Organism(r, c, s) {
	stepsSinceAte = 0; //Keep track how many time steps since a Doodlebug ate
}

/**
 * Gets number of steps since the Doodlebug ate.
 * @return number of steps since the Doodlebug ate
 */
int Doodlebug::getStepsSinceAte() {
	return stepsSinceAte;
}

/**
 * Moves the Doodlebug to an adjacent Cell.
 * Does not move if other Doodlebugs are occupying adjacent Cells.
 * @param g The Grid containing the Organisms
 * @param n The number of Cells along an edge of the Grid
 * @return true if moved;
 * 		   false otherwise
 */
bool Doodlebug::move(Grid* g, int n) {
	bool status = true; //Returns true if the Doodlebug was able to move

	origRow = row;
	origCol = col;
	moveLocation moveTo = targetCell(g, row, col, n, true); //target cell to move to

	if(moveTo == right || moveTo == down) { //skip Cell that we will visit again
		skip = true;
	} else { //Otherwise no reason to skip again
		skip = false;
	}

	switch(moveTo) { //Depending on moveTo, update the position of this Doodlebug
	case stay: //does not move, stays put
		status = false; //Doodlebug not able to move
		break;
	case up: //moves into the Cell above
		row--;
		break;
	case right: //moves into the Cell to the right
		col++;
		break;
	case down: //moves into the Cell below
		row++;
		break;
	case left: //moves into the Cell to the left
		col--;
		break;
	}

	stepsSinceBreed++; //Increment both counters for breeding and eating
	stepsSinceAte++;

	if(moveTo != stay) { //As long as we actually moved
		if(g->getCellOccupant(row, col) == ant) {
			eat(g); //Eat the ant that was in the cell that we are moving to
		}
		g->setCellOccupant(row, col, doodlebug, this); //Move to this Cell on the Grid
		g->setCellOccupant(origRow, origCol, empty, nullptr); //Changes original cell to empty
	}

 	return status;
}

/**
 * Gives birth to a Doodlebug in an adjacent Cell.
 * Can only give birth after surviving for eight steps.
 * Doesn't give birth if adjacent Cells occupied.
 * Can give birth on next step if all adjacent Cells are occupied.
 * @param g The Grid containing the Organisms
 * @param n The number of Cells along an edge of the Grid
 * @return true if birth given;
 * 		   false otherwise
 */
bool Doodlebug::breed(Grid* g, int n) {
	bool status = false; //Variable to return whether we breed
	moveLocation breedTo = targetCell(g, row, col, n, false); //target Cell to breed into
	int newRow = -1; //Variables to store the new coordinates we can breed to
	int newCol = -1;

	//Depending on breedTo, get the row, col values for the new child
	switch(breedTo) {
	case stay: //all adjacent Cells occupied, no breeding occurs
		status = false; //cannot breed
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

	if(breedTo != stay) { //As long as we can breed
		stepsSinceBreed = 0; //Reset the breed counter
		Doodlebug* d;
		if(newRow < origRow || (newRow == origRow && newCol <= origCol)) {
			d = new Doodlebug(newRow, newCol, false); //doesn't skip Doodlebug if placed before current place in loop
		} else {
			d = new Doodlebug(newRow, newCol, true); //skips Doodlebug if placed after current place in loop
		}
		g->setCellOccupant(newRow, newCol, doodlebug, d); //Places the new Doodlebug in the Grid
		status = true; //Return that we did breed
	}

	return status;
}

/**
 * Eats an Ant in an adjacent Cell.
 * @return true if Ant eaten;
 * 		   false otherwise
 */
bool Doodlebug::eat(Grid* g) {
	bool status = false; //by default we did not eat the Ant
	delete g->getCellOccupantPtr(row, col); //remove the occupant of the Cell
	if(g->getCellOccupant(row, col) == empty) { //Ant successfully eaten
		status = true;
	}
	stepsSinceAte = 0; //We reset the counter
	return status;
}

/**
 * Doodlebug destructor.
 * Death of Doodlebug occurs when Ant not consumed in three steps.
 */
Doodlebug::~Doodlebug() {

}
