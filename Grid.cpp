/*
 * Grid.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"

/**
 * Grid Constructor.
 * @param nSquaresOnASide Number of squares on a side of the Grid
 */
Grid::Grid(int nSquaresOnASide) {
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	cellArrPtr = new Cell* [n](); //first allocate array of row pointers

	for(int i = 0; i < n; i++) {
		cellArrPtr[i] = new Cell[n](); //allocate memory for columns in each row
	}
}

/**
 * Gets the occupant type in a Cell on the Grid.
 * @param r The row of the occupant
 * @param c The column of the occupant
 * @return The occupant type
 */
occupationStatus Grid::getCellOccupant(int r, int c) {
	//Returns the type of being within a certain Cell of the Grid
	return cellArrPtr[r][c].getOccupant();
}

/**
 * Sets an occupant in a Cell of the Grid.
 * @param r Row to set occupant
 * @param c Column to set occupant
 * @param g The occupant of the Cell
 * @param o_ptr The pointer to an Organism
 */
void Grid::setCellOccupant(int r, int c, occupationStatus g, Organism* o_ptr) {
	//Sets the type of being within a certain Cell in a Grid
	cellArrPtr[r][c].setOccupant(g, o_ptr);
}

/**
 * Gets the occupant pointer in a Cell on the Grid.
 * @param r The row of the occupant
 * @param c The column of the occupant
 * @return The pointer to the occupant
 */
Organism* Grid::getCellOccupantPtr(int r, int c) {
	//Gets the pointer to a being at a certain Cell in the Grid
	return cellArrPtr[r][c].getOccupantPtr();
}

/**
 * Initializes the Grid with a random configuration of Ants and Doodlebugs.
 * @param gridSize Number of Cells on each side of the Grid
 * @param numAnts Number of Ants to place on the Grid
 * @param numDoodlebugs Number of Doodlebugs to place on the Grid
 */
void Grid::initGrid(int gridSize, int numAnts, int numDoodlebugs) {
	int currentAnts = 0; //number of Ants already in the Grid
	int currentDbugs = 0; //number of Doodlebugs already in the Grid
	int randRow = -1; //random row to place an Organism
	int randCol = -1; //random column to place an Organism

	//While number of Ants less than specified amount
	while(currentAnts < numAnts) {
		randRow = rand() % gridSize; //Randomly generate row and column values
		randCol = rand() % gridSize;

		//random Cell is empty
		if(cellArrPtr[randRow][randCol].getOccupant() == empty) {
			Ant* a = new Ant(randRow, randCol, false); //creates new Ant
			cellArrPtr[randRow][randCol].setOccupant(ant, a); //places Ant in Cell
			currentAnts++;
		}
	}

	//While number of Doodlebugs less than specified amount
	while(currentDbugs < numDoodlebugs) {
		randRow = rand() % gridSize; //Get random values for row and col
		randCol = rand() % gridSize;

		//random Cell is empty
		if(cellArrPtr[randRow][randCol].getOccupant() == empty) {
			Doodlebug* d = new Doodlebug(randRow, randCol, false); //creates new Doodlebug
			cellArrPtr[randRow][randCol].setOccupant(doodlebug, d); //places Doodlebug in Cell
			currentDbugs++;
		}
	}
}

/**
 * Prints the Grid.
 */
void Grid::printGrid() {
	for(int r = 0; r < n; r++) { //Loop through all the cells in the grid
		for(int c = 0; c < n; c++) {
			if(cellArrPtr[r][c].getOccupant() == empty) { //print blank if empty
				std::cout << " ";
			} else if(cellArrPtr[r][c].getOccupant() == ant) { //print 'o' if Ant
				std::cout << "o";
			} else { //print 'x' if Doodlebug
				std::cout << "x";
			}
		}
		std::cout << std::endl;
	}
}

/**
 * Destructs a Grid.
 */
Grid::~Grid() {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			cellArrPtr[r][c].~Cell(); //free memory for columns in each row
		}
	}
}
