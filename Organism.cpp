/*
 * Organism.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#include <cstdlib>
#include "Organism.h"

/**
 * Constructs an Organism.
 * @param r The row of the Organism
 * @param c The column of the Organism
 * @param s true if the Organism should be skipped;
 * 			false otherwise
 */
Organism::Organism(int r, int c, bool s) {
	row = r;
	col = c;
	skip = s;
	stepsSinceBreed = 0;
	origRow = r;
	origCol = c;
}

/**
 * Gets the row of an Organism.
 * @return Row of an Organism
 */
int Organism::getRow() {
	return row;
}

/**
 * Gets the column of an Organism.
 * @return Column of an Organism
 */
int Organism::getCol() {
	return col;
}

/**
 * Gets whether an Organism should be skipped in the loop.
 * @return true if Organism should be skipped;
 * 		   false otherwise
 */
bool Organism::getSkip() {
	return skip;
}

/**
 * Sets whether an Organism should be skipped in the loop.
 * @param s true if an Organism should be skipped;
 * 			false otherwise
 */
void Organism::setSkip(bool s) {
	skip = s;
}

/**
 * Gets number of steps since an Organism breed.
 * @return number of steps since an Organism breed
 */
int Organism::getStepsSinceBreed() {
	return stepsSinceBreed;
}

/**
 * Determines the spot that an Organism should move to or breed in.
 * Determines if the Cell above, below, right, and left are occupied, and out
 * of the empty Cells, randomly determines the Cell to move to or breed in. If
 * the Organism is a Doodlebug attempting to move, it will randomly move to an
 * adjacent Cell with an Ant in it before moving to an empty Cell. The Organism
 * does not move if all adjacent Cells are filled (unless the Organism is a
 * Doodlebug, and an Ant occupies an adjacent Cell).
 * @param g The grid with the Organisms
 * @param r The row of the Organism
 * @param c The column of the Organism
 * @param n The number of Cells on an edge
 * @param dMove true if the Organism is a Doodlebug trying to move;
 * 				false otherwise
 * @return stay if Organism cannot move or breed;
 * 		   up if Organism moves or breeds in Cell above;
 * 		   right if Organism moves or breeds in Cell to the right;
 * 		   down if Organism moves or breeds in Cell below;
 * 		   left if Organism moves or breeds in Cell to the left
 */
moveLocation Organism::targetCell(Grid* g, int r, int c, int n, bool dMove) {
	moveLocation result = stay; //direction that an Organism will move or breed
	moveLocation possibleCells[4] = {stay, stay, stay, stay}; //possible Cells that Organism may move or breed to
	int cellsOpen = 0; //We also want to keep track of the number of open Cells

	if(dMove) { //if this is a Doodlebug moving
		//Cell above (if exists) contains an Ant
		if(r - 1 > -1 && g->getCellOccupant(r - 1, c) == ant) {
			possibleCells[cellsOpen] = up;
			cellsOpen++;
		}
		//Cell to the right (if exists) contains an Ant
		if(c + 1 < n && g->getCellOccupant(r, c + 1) == ant) {
			possibleCells[cellsOpen] = right;
			cellsOpen++;
		}
		//Cell below (if exists) contains an Ant
		if(r + 1 < n && g->getCellOccupant(r + 1, c) == ant) {
			possibleCells[cellsOpen] = down;
			cellsOpen++;
		}
		//Cell to the left (if exists) contains an Ant
		if(c - 1 > -1 && g->getCellOccupant(r, c - 1) == ant) {
			possibleCells[cellsOpen] = left;
			cellsOpen++;
		}
	}
	//Doodlebug found no Ants, Ant moving, or Organism breeding
	if(cellsOpen == 0) {
		//Cell above (if exists) is empty
		if(r - 1 > -1 && g->getCellOccupant(r - 1, c) == empty) {
			possibleCells[cellsOpen] = up;
			cellsOpen++;
		}
		//Cell to the right (if exists) is empty
		if(c + 1 < n && g->getCellOccupant(r, c + 1) == empty) {
			possibleCells[cellsOpen] = right;
			cellsOpen++;
		}
		//Cell below (if exists) is empty
		if(r + 1 < n && g->getCellOccupant(r + 1, c) == empty) {
			possibleCells[cellsOpen] = down;
			cellsOpen++;
		}
		//Cell to the left (if exists) is empty
		if(c - 1 > -1 && g->getCellOccupant(r, c - 1) == empty) {
			possibleCells[cellsOpen] = left;
			cellsOpen++;
		}
	}

	//If there were not Cells open at the end we cannot move, so result == stay
	if(cellsOpen == 0) {
		result = stay;
	} else if(cellsOpen == 1){ //If there is only one option we move there
		result = possibleCells[0];
	} else { //Otherwise pick a random adjacent Cell that is open and move there
		result = possibleCells[rand() % (cellsOpen - 1)];
	}

	return result;
}

/**
 * Destructs an Organism.
 */
Organism::~Organism() {

}

