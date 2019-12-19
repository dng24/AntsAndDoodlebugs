 /*
 * Production.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Production.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"

/**
 * Constructs a Production.
 * @param argc Number of arguments on the Command Line
 * @param argv Array of arguments on the Command Line
 */
Production::Production(int argc, char* argv[]) {
	char* ptr = 0;
	long arg_l = -1; //an argument on the command line
	int i = 1; //iterator through the command line
	//iterates through the command line arguments, stops after element 6 or
	//until the number of arguments have been reached
	for( ; i < argc && i < 7; i++) {
		arg_l = strtol(argv[i], &ptr, 10); //gets the argument
		switch(i) {
		case 1: //sets grid size
			gridSize = (int) arg_l; //sets grid size to the argument
			if(gridSize < 1) { //arg must be greater than 0
				std::cout << "Grid size must be greater than zero, received " << gridSize << ".\n";
				std::cout << "Defaulting grid size to 20.\n";
				gridSize = 20; //will set grid size to 20 if arg invalid
			}
			break;
		case 2: //sets number of Doodlebugs
			numDoodlebugs = (int) arg_l; //sets number of Doodlebugs to the argument
			if(numDoodlebugs < 1) { //arg must be greater than 0
				std::cout << "Number of doodlebugs must be greater than zero, received " << numDoodlebugs << ".\n";
				std::cout << "Defaulting number of doodlebugs to 5.\n";
				numDoodlebugs = 5; //numb
			}
			break;
		case 3: //Sets the number of Ants
			numAnts = (int) arg_l; //Sets the number of Ants to the given argument
			if(numAnts < 0) { //the value must be greater than zero or else default
				std::cout << "Number of ants must be greater than zero, received " << numAnts << ".\n";
				std::cout << "Defaulting number of ants to 100.\n";
				numAnts = 100;
			}
			break;
		case 4: //Sets the number of time steps
			numTimeSteps = (int) arg_l;  //Sets the time steps to given argument
			if(numTimeSteps < 0) { //Value must be greater than zero else default
				std::cout << "Number of time steps must be greater than -1, received " << numTimeSteps << ".\n";
				std::cout << "Defaulting number of time steps to 1000.\n";
				numTimeSteps = 1000;
			}
			break;
		case 5: //Sets the seed value
			seed = (int) arg_l;
			if(seed == 0) { //if seed is 0, use current time
				seed = time(0);
			}
			break;
		case 6: //Sets the pause value
			pause = (int) arg_l;
			if(pause < 0) { //This value must be greater than zero or else default
				std::cout << "Pause must be zero or greater, received " << pause << ".\n";
				std::cout << "Defaulting pause to 0.\n";
				pause = 0;
			}
			break;
		}
	}

	//Sets default cases to parameters not specified in Command Line
	while(i < 7) {
		switch(i) {
		case 1:
			gridSize = 20;
			break;
		case 2:
			numDoodlebugs = 5;
			break;
		case 3:
			numAnts = 100;
			break;
		case 4:
			numTimeSteps = 1000;
			break;
		case 5:
			seed = 1;
			break;
		case 6:
			pause = 0;
			break;
		}
		i++;
	}

	//sum of Doodlebugs and Ants greater than number of Cells
	if(numAnts + numDoodlebugs > gridSize * gridSize) {
		gridSize = ceil(sqrt(numAnts + numDoodlebugs));
		std::cout << "The sum of the ants and doodlebugs is greater than the number of cells on the grid.\n";
		std::cout << "Increasing grid size to " << gridSize << ".\n"; //increment the grid size to account for them
	}

	//We print out all the values for this board
	std::cout << "\nCommand line arguments:\n";
	std::cout << "\nNumber of cells per side:\t" << gridSize;
	std::cout << "\nInitial number of doodlebugs:\t" << numDoodlebugs;
	std::cout << "\nInitial number of ants:\t\t" << numAnts;
	std::cout << "\nNumber of time steps:\t\t" << numTimeSteps;
	std::cout << "\nSeed number:\t\t\t" << seed;
	std::cout << "\nNumber steps between printings:\t" << pause;
	std::cout << "\n\n\'x\' represents a doodlebug, \'o\' represents an ant.\n\n";

	srand(seed); //sets the random number generator
}

/**
 * Main Production method.
 * @return true if production seemed to work;
 * 		   false otherwise
 */
bool Production::runProduction() {
	bool result = true; //To return at the end if this runs successfully
	Grid* g = new Grid(gridSize); //We create a new Grid
	g->initGrid(gridSize, numAnts, numDoodlebugs); //initialize Grid
	if(pause != 0) { //if user wants intermediate steps, print initial Grid
		std::cout << "Initial Configuration:\n";
		g->printGrid();
		puts("");
	}

	int totalSteps = 0; //total iterations through the board
	int totalAnts = numAnts; //total number Ants simulated; set to initial number of Ants
	int totalDoodlebugs = numDoodlebugs; //total number Doodlebugs simulated; set to initial number of Doodlebugs
	bool allAntsDead = false; //checks if all Ants are dead
	bool allDoodlesDead = false; //checks if all Doodlebugs are dead

	//Loops through until we run out of time steps or either all Ants are dead
	//or all Doodlebugs are dead
	while(totalSteps < numTimeSteps && !allAntsDead && !allDoodlesDead) {
		//This portion deals with the Doodlebugs, since they move first.
		//We iterate through all of the Cells of the Grid and perform all of
		//the Doodlebug movements
		for(int r = 0; r < gridSize; r++) {
			for(int c = 0; c < gridSize; c++) {
				if(g->getCellOccupant(r, c) == doodlebug) {
					//We make sure that we are not trying to move a bug we just
					//moved this iteration
					if(g->getCellOccupantPtr(r, c)->getSkip() == true) {
						g->getCellOccupantPtr(r, c)->setSkip(false);
					} else {
						bool breed = oneDoodlebugStep(g, r, c); //One Doodlebug step

						//If we created another, increment the number of
						//Doodlebugs we have
						if(breed) {
							totalDoodlebugs++;
						}
					}
				}
			}
		}

		//This portion of the code deals with all the Ant related steps, since
		//the Ants move second
		///We iterate through all of the Cells of the Grid and perform all of
		//the Ant movements
		for(int r = 0; r < gridSize; r++) {
			for(int c = 0; c < gridSize; c++) {
				if(g->getCellOccupant(r, c) == ant) {
					//We make sure that we are not trying to move an Ant we
					//just moved this iteration
					if(g->getCellOccupantPtr(r, c)->getSkip() == true) {
						g->getCellOccupantPtr(r, c)->setSkip(false);
					} else {
						bool breed = oneAntStep(g, r, c); //We run one step with all the ants
						//If we created another Ant, we increment the counter
						if(breed) {
							totalAnts++;
						}
					}
				}
			}
		}

		//We increment the steps that we did and check if either all the Ants
		//are dead, all the Doodlebugs are dead, or both
		totalSteps++;
		allAntsDead = true;
		allDoodlesDead = true;
		for(int r = 0; r < gridSize; r++) {
			for(int c = 0; c < gridSize; c++) {
				if(g->getCellOccupant(r, c) == ant) {
					allAntsDead = false;
				} else if(g->getCellOccupant(r, c) == doodlebug) {
					allDoodlesDead = false;
				}
			}
		}

		//If the individual requested a pause in-between iterations,
		//we make sure value is not zero and the total number of steps is a
		//multiple of the pause value
		if(pause != 0 && totalSteps % pause == 0 && totalSteps != numTimeSteps) {
			std::cout << "Step number " << totalSteps << ": \n";
			g->printGrid();
			puts("\nPress enter to continue.");
			getc(stdin);
		}
	} //Finished all iterations of the board

	//We keep a counter of the number of Ants and Doodlebugs remaining in the
	//Grid by checking all the Cells at the end
	int antsRemaining = 0;
	int doodlebugsRemaining = 0;
	for(int r = 0; r < gridSize; r++) {
		for(int c = 0; c < gridSize; c++) {
			if(g->getCellOccupant(r, c) == ant) {
				antsRemaining++;
			} else if(g->getCellOccupant(r, c) == doodlebug) {
				doodlebugsRemaining++;
			}
		}
	}

	//Print the final values for the board
	std::cout << "SIMULATION FINISHED\n\n";
	if(totalSteps == numTimeSteps) { //Max time steps reached
		std::cout << "Maximum time steps reached.\n\n";
	}
	std::cout << "Original arguments:\n";
	std::cout << "\nNumber of cells per side:\t" << gridSize;
	std::cout << "\nInitial number of doodlebugs:\t" << numDoodlebugs;
	std::cout << "\nInitial number of ants:\t\t" << numAnts;
	std::cout << "\nNumber of time steps:\t\t" << numTimeSteps;
	std::cout << "\nSeed number:\t\t\t" << seed;
	std::cout << "\nNumber steps between printings:\t" << pause;

	std::cout << "\n\nTotal number of steps simulated:\t" << totalSteps;
	std::cout << "\nTotal number of ants simulated:\t\t" << totalAnts;
	std::cout << "\nNumber of ants remaining:\t\t" << antsRemaining;
	std::cout << "\nTotal number of doodlebugs simulated:\t" << totalDoodlebugs;
	std::cout << "\nNumber of doodlebugs remaining:\t\t" << doodlebugsRemaining;
	std::cout << "\n\nFinal Configuration (Step " << totalSteps << "):\n";

	g->printGrid(); //Print the grid at the end
	return result;
}

/**
 * Simulates a Doodlebug for one step.
 * @param g Grid that contains the Organisms
 * @param r Row of the Doodlebug
 * @param c Column of the Doodlebug
 * @return true if birth was given;
 * 		   false otherwise;
 */
bool Production::oneDoodlebugStep(Grid* g, int r, int c) {
	bool breed = false; //Initially breed is zero
	Doodlebug* d = (Doodlebug*) g->getCellOccupantPtr(r, c); //Get the Doodlebug and move it
	d->move(g, gridSize);
	int newRow = d->getRow(); //Get the value for its new row and column
	int newCol = d->getCol();

	//If it has not eaten in three timesteps it dies
	if(d->getStepsSinceAte() >= 3) {
		delete d;
		g->setCellOccupant(newRow, newCol, empty, nullptr);
	} else if(d->getStepsSinceBreed() >= 8) { //If it has not bred in eight timesteps, it tries to breed
		breed = d->breed(g, gridSize);
	}
	return breed;
}

/**
 * Simulates an Ant for one step.
 * @param g Grid that contains the organisms
 * @param r Row of the Ant
 * @param c Column of the Ant
 * @return true if birth was given;
 * 		   false otherwise;
 */
bool Production::oneAntStep(Grid* g, int r, int c) {
	bool breed = false; //Initially breed is false
	Ant* a = (Ant*) g->getCellOccupantPtr(r, c); //Get the Ant from the Cell
	a->move(g, gridSize); //Move the ant by one

	//If the ant has not bred within three timesteps, it tries to breed
	if(a->getStepsSinceBreed() >= 3) {
		breed = a->breed(g, gridSize);
	}
	return breed;
}

/**
 * Destructs Production.
 */
Production::~Production() {

}
