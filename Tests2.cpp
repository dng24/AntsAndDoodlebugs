/*
 * Tests2.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Production.h"
#include <iostream>

/**
 * Constructs a Test.
 */
Tests2::Tests2() {

}

/**
 * Performs the tests.
 * @return true if all tests passes;
 * 		   false otherwise
 */
bool Tests2::doTests() {
	bool results;
	std::cout << "\nDOING TESTS\n\n";

	std::cout << "Production Tests:\n";
	//runs Production
	bool okP1 = runProductionTest();
	if(okP1) {
		std::cout << "Run production ok.\n";
	} else {
		std::cout << "Run production FAILED.\n";
	}
	//performs one time step for a Doodlebug
	bool okP2 = oneDoodlebugStepTest();
	if(okP2) {
		std::cout << "One Doodlebug step ok.\n";
	} else {
		std::cout << "One Doodlebug FAILED.\n";
	}
	//performs one time step for an Ant
	bool okP3 = oneAntStepTest();
	if(okP3) {
		std::cout << "One Ant step ok.\n";
	} else {
		std::cout << "One Ant step FAILED.\n";
	}
	bool okP = okP1 && okP2 && okP3;

	std::cout << "\nGrid tests:\n";
	//establish a grid
	bool okG1 = gridTest();
	if(okG1) {
		std::cout << "Make grid ok.\n";
	} else {
		std::cout << "Make grid FAILED.\n";
	}
	//gets the occupant in a cell
	bool okG2 = getCellOccupantTest();
	if(okG2) {
		std::cout << "Cell occupant getter ok.\n";
	} else {
		std::cout << "Cell occupant getter FAILED.\n";
	}
	//sets the occupant in a cell
	bool okG3 = setCellOccupantTest();
	if(okG3) {
		std::cout << "Cell occupant setter ok.\n";
	} else {
		std::cout << "Cell occupant setter FAILED.\n";
	}
	//gets the pointer to an occupant in a cell
	bool okG4 = getCellOccupantPtrTest();
	if(okG4) {
		std::cout << "Cell occupant pointer getter ok.\n";
	} else {
		std::cout << "Cell occupant pointer getter FAILED.\n";
	}
	//initializes the grid
	bool okG5 = initGridTest();
	if(okG5) {
		std::cout << "Grid initialization ok.\n";
	} else {
		std::cout << "Grid initialization FAILED.\n";
	}
	//prints the grid
	bool okG6 = printGrid();
	if(okG6) {
		std::cout << "Grid printed ok.\n";
	} else {
		std::cout << "Grid printed FAILED.\n";
	}
	bool okG = okG1 && okG2 && okG3 && okG4 && okG5 && okG6;

	std::cout << "\nCell tests:\n";
	//gets an occupant in a cell
	bool okC1 = getOccupantTest();
	if(okC1) {
		std::cout << "Occupant setter ok.\n";
	} else {
		std::cout << "Occupant setter FAILED.\n";
	}
	//sets an occupant in a cell
	bool okC2 = setOccupantTest();
	if(okC2) {
		std::cout << "Occupant getter ok.\n";
	} else {
		std::cout << "Occupant getter FAILED.\n";
	}
	//gets the pointer to an occupant in a cell
	bool okC3 = getOccupantPtrTest();
	if(okC3) {
		std::cout << "Occupant pointer getter ok.\n";
	} else {
		std::cout << "Occupant pointer getter FAILED.\n";
	}
	bool okC = okC1 && okC2 && okC3;

	std::cout << "\nOrganism tests:\n";
	//gets the row of a cell
	bool okO1 = getRowTest();
	if(okO1) {
		std::cout << "Row getter ok.\n";
	} else {
		std::cout << "Row getter FAILED.\n";
	}
	//gets the column of a cell
	bool okO2 = getColTest();
	if(okO2) {
		std::cout << "Column getter ok.\n";
	} else {
		std::cout << "Column getter FAILED.\n";
	}
	//gets whether a cell should be skipped in the loop
	bool okO3 = getSkipTest();
	if(okO3) {
		std::cout << "Skip getter ok.\n";
	} else {
		std::cout << "Skip getter FAILED.\n";
	}
	//sets whether a cell should be skipped in the loop
	bool okO4 = setSkipTest();
	if(okO4) {
		std::cout << "Skip setter ok.\n";
	} else {
		std::cout << "Skip setter FAILED.\n";
	}
	//gets the number of steps since an Organism breed
	bool okO5 = getStepsSinceBreedTest();
	if(okO5) {
		std::cout << "Steps since Organism breed getter ok.\n";
	} else {
		std::cout << "Steps since Organism breed getter FAILED.\n";
	}
	//gets the random cell that an Organism should move to
	bool okO6 = targetCellTest();
	if(okO6) {
		std::cout << "Target cell ok.\n";
	} else {
		std::cout << "Target cell FAILED.\n";
	}
	bool okO = okO1 && okO2 && okO3 && okO4 && okO5 && okO6;

	std::cout << "\nAnt tests:\n";
	//populate it with ants
	bool okA1 = makeAntsTest();
	if(okA1) {
		std::cout << "Make ants ok.\n";
	} else {
		std::cout << "Make ants FAILED.\n";
	}
	//see whether they move
	bool okA2 = antsMoveTest();
	if(okA2) {
		std::cout << "Move ants ok.\n";
	} else {
		std::cout << "Move ants FAILED.\n";
	}
	//see whether they breed
	bool okA3 = antsBreedTest();
	if(okA3) {
		std::cout << "Breed ants ok.\n";
	} else {
		std::cout << "Breed ants FAILED.\n";
	}
	bool okA = okA1 && okA2 && okA3;

	std::cout << "\nDoodlebug tests:\n";
	//populate with doodlebugs
	bool okD1 = makeDoodlesTest();
	if(okD1) {
		std::cout << "Make doodles ok.\n";
	} else {
		std::cout << "Make doodles FAILED.\n";
	}
	//see whether they move
	bool okD2 = doodleMoveTest();
	if(okD2) {
		std::cout << "Move doodles ok.\n";
	} else {
		std::cout << "Move doodles FAILED.\n";
	}
	//see whether they breed
	bool okD3 = doodleBreedTest();
	if(okD3) {
		std::cout << "Breed doodles ok.\n";
	} else {
		std::cout << "Breed doodles FAILED.\n";
	}
	//see whether they eat ants
	bool okD4 = doodleEatTest();
	if(okD4) {
		std::cout << "Doodles eating ok.\n";
	} else {
		std::cout << "Doodles eating FAILED.\n";
	}
	//gets the number of steps since a Doodlebug ate
	bool okD5 = getStepsSinceAteTest();
	if(okD5) {
		std::cout << "Steps since Doodlebug ate getter ok.\n";
	} else {
		std::cout << "Steps since Doodlebug ate getter FAILED.\n";
	}
	bool okD = okD1 && okD2 && okD3 && okD4 && okD5;

	results = okP && okG && okC && okO && okA && okD;

	std::cout << "\nEND OF TESTING\n";
	if(results) { //Indicates if all tests passed
		std::cout << "\nALL TESTS PASSED\n";
	}
	std::cout << "***************************************************\n";
	return results;
}

/**
 * Tests that the main production method functions properly.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::runProductionTest() {

	bool result = true;
	std::cout << "Running runProductionTest()\n";

	//To test this function we will just run the production method and make
	//sure that the default values can run without fault since we have tested
	//its individual units already
	char* argv[] = {nullptr}; //Create fake argv[] and a Production with it

	Production* p = new Production(0, argv);

	p->runProduction(); //As long as it does not fail, the test passes

	p->~Production();
	return result;
}

/**
 * Tests that one time step for a Doodlebug can properly be executed.
 *
 * The board that will be tested (but has grid size of 20):
 *
 * 		-x-
 * 		--x
 * 		xo-
 *
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::oneDoodlebugStepTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running oneDoodlebugStepTest()\n";

	//We will have a board of Doodlebugs and some Ants, and as long as some
	//Doodlebugs move and Ants do not the test passes
	Grid* grid = new Grid(20);

	//Create the Doodlebugs and the Ants
	Doodlebug* bug1 = new Doodlebug(0, 1, false);
	grid->setCellOccupant(0, 1, doodlebug, bug1);

	Doodlebug* bug2 = new Doodlebug(2, 0, false);
	grid->setCellOccupant(2, 0, doodlebug, bug2);

	Doodlebug* bug3 = new Doodlebug(1, 2, false);
	grid->setCellOccupant(1, 2, doodlebug, bug3);

	Ant* aAn = new Ant(2, 1, false);
	grid->setCellOccupant(2, 1, ant, aAn);

	char* argv[] = {nullptr}; //Create a fake argv[] and a Production with it

	Production* p = new Production(0, argv);

	p->oneDoodlebugStep(grid, 0, 1); //We will move one Doodlebug on the grid

	//If it is not where it started and the other three spots surrounding it,
	//at least one has the Doodlebug, then this test passed
	if(grid->getCellOccupant(0, 1) == empty
			&& (grid->getCellOccupant(0, 0) == doodlebug
					|| grid->getCellOccupant(1, 1) == doodlebug
					|| grid->getCellOccupant(0, 2) == doodlebug)) {
		ok1 = true;
	}

	//If the Ant is still there we passed
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) { //Loop through row and columns
			if(grid->getCellOccupant(r, c) == ant) { //If any Ants we failed
				ok2 = true;
			}
		}
	}

	delete bug1;
	delete bug2;
	delete aAn;
	grid->~Grid();
	p->~Production();

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that one time step for an Ant can properly be executed.
 *
 * The board that will be tested:
 *
 * 		-x-
 * 		--x
 * 		xo-
 *
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::oneAntStepTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running oneAntStepTest()\n";

	//We will have a board of Doodlebugs and some Ants, and as long as some
	//Doodlebugs move and Ants do not the test passes
	Grid* gridforTest = new Grid(20);

	//Create the Doodlebugs and the Ants
	Doodlebug* bug1 = new Doodlebug(0, 1, false);
	gridforTest->setCellOccupant(0, 1, doodlebug, bug1);

	Doodlebug* bug2 = new Doodlebug(2, 0, false);
	gridforTest->setCellOccupant(2, 0, doodlebug, bug2);

	Doodlebug* bug3 = new Doodlebug(1, 2, false);
	gridforTest->setCellOccupant(1, 2, doodlebug, bug3);

	Ant* aAn = new Ant(2, 1, false);
	gridforTest->setCellOccupant(2, 1, ant, aAn);

	char* argv[] = {nullptr}; //Create a fake argv[] and a production with it

	Production* prod = new Production(0, argv);
	gridforTest->printGrid();

	//We will move one ant and make sure that it did not get eaten
	prod->oneAntStep(gridforTest, 2, 1);
	printf("\n");
	gridforTest->printGrid();

	//If it is not where it started and the other three spots surrounding it,
	//at least one has the Ant, then this test passed
	if(gridforTest->getCellOccupant(2, 1) == empty
			&& (gridforTest->getCellOccupant(2, 2) == ant
					|| gridforTest->getCellOccupant(1, 1) == ant)) {
		ok1 = true;
	}

	//If the Ant is still there we passed
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) { //Loop through row and columns
			if(gridforTest->getCellOccupant(r, c) == ant) { //passed iff Ant is still there
				ok2 = true;
			}
		}
	}

	delete bug1;
	delete bug2;
	delete aAn;
	gridforTest->~Grid();
	prod->~Production();

	result = ok1 && ok2;
	return result;
}

/**
 * Tests Grid initialization and adding Organisms.
 * @return true if test passes;
 * 		   false otherwise
 */
bool Tests2::gridTest() {
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;

	std::cout << "Running gridTest()\n";

	Grid myGrid = Grid(8); //creates a grid
	if(myGrid.getCellOccupant(2, 3) != empty) { //cell should be empty
		std::cout << "Cell not initially empty\n";
		ok1 = false;
	}

	Ant* a = new Ant(2, 3, false);
	myGrid.setCellOccupant(2, 3, ant, a);
	if(myGrid.getCellOccupant(2, 3) != ant) { //ant should be occupying [2][3]
		std::cout << "Cell not set to ant\n";
		ok2 = false;
	}
	Doodlebug* d = new Doodlebug(5, 7, false);
	myGrid.setCellOccupant(5, 7, doodlebug, d);
	if(myGrid.getCellOccupant(5, 7) != doodlebug) { //ant should be occupying [2][3]
		std::cout << "Cell not set to doodlebug\n";
		ok3 = false;
	}

	delete a;
	delete d;
	myGrid.~Grid();

	result = ok1 && ok2 && ok3;
	return result;
}

/**
 * Tests that the function correctly gets the Cell occupant type.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getCellOccupantTest() {
	bool result = true;
	bool ok1 = true; //We will have three sub-tests
	bool ok2 = true;
	bool ok3 = true;

	std::cout << "Running getCellOccupantTest()\n";

	Grid* grid = new Grid(8); //First we create a new Grid

	//We will set different Cell occupants in the Grid and see if we can get them
	//Getting an ant
	Ant* anty = new Ant(3, 3, false);
	grid->setCellOccupant(3, 3, ant, anty); //We create and set an ant

	occupationStatus antAnother = grid->getCellOccupant(3, 3); //The type should be ant
	if(antAnother != ant) { //If not ant set the value to false
		ok1 = false;
	}
	//Now we will run a test with a doodlebug
	Doodlebug* buggy = new Doodlebug(4, 4, false);
	grid->setCellOccupant(4, 4, doodlebug, buggy); //We create and set a new Doodlebug

	occupationStatus anotherBug = grid->getCellOccupant(4, 4); //Should be doodlebug
	if(anotherBug != doodlebug) {//If not we set value to false
		ok2 = false;
	}

	//Now we will test how this works with an empty cell
	//We will just get the occupant from cell and make sure that it is empty
	occupationStatus shouldBEmpty = grid->getCellOccupant(3, 4);
	if(shouldBEmpty != empty) { //If its not empty, then we set value to false
		ok3 = false;
	}

	delete anty;
	delete buggy;
	grid->~Grid();

	result = ok1 && ok2 && ok3;
	return result;
}

/**
 * Tests that the function correctly sets the Cell occupant type.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::setCellOccupantTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running setCellOccupantTest()\n";

	//We will create two Cells and set occupants
	Cell* aCell = new Cell();
	Doodlebug* bug = new Doodlebug(5, 3, false);
	aCell->setOccupant(doodlebug, bug);

	if(aCell->getOccupant() == doodlebug) { //There should be a Doodlebug here
		ok1 = true;
	}

	Cell* bCell = new Cell();
	Ant* anty = new Ant(2, 3, false);
	bCell->setOccupant(ant, anty);

	if(bCell->getOccupant() == ant) { //There should be an Ant here
		ok2 = true;
	}

	delete anty;
	delete bug;
	aCell->~Cell();
	bCell->~Cell();

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that the function correctly gets the pointer to a Cell.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getCellOccupantPtrTest() {
	bool result = true;
	bool ok1 = true; //We will have three sub-tests
	bool ok2 = true;
	bool ok3 = true;

	std::cout << "Running getCellOccupantPtrTest()\n";

	Grid* grid = new Grid(8); //First we create a new Grid

	//We will set different Cell occupants in the Grid and see if we can get them
	//Getting an Ant
	Ant* anty = new Ant(3, 3, false);
	grid->setCellOccupant(3, 3, ant, anty); //We create and set an ant

	Organism* antAnother = grid->getCellOccupantPtr(3, 3); //The pointer should be an Ant

	//If the pointer does not correctly get information from the Ant object it
	//is broken
	if(antAnother->getCol() != 3) {
		ok1 = false;
	}
	//Now we will run a test with a Doodlebug
	Doodlebug* buggy = new Doodlebug(4, 4, false);
	grid->setCellOccupant(4, 4, doodlebug, buggy); //We create and set a new Doodlebug

	Organism* anotherBug = grid->getCellOccupantPtr(4, 4); //Should be Doodlebug

	//If the pointer does not correctly get information from the bug it is broken
	if(anotherBug->getRow() != 4) {
		ok2 = false;
	}

	//Now we will test how this works with an empty cell
	//We will just get the occupant from cell and make sure that it is empty
	Organism* shouldBEmpty = grid->getCellOccupantPtr(3, 4);
	if(shouldBEmpty != nullptr) { //If the pointer is not a null pointer, it failed
		ok3 = false;
	}

	delete anty;
	delete buggy;
	grid->~Grid(); //Get rid of the grid

	result = ok1 && ok2 && ok3;
	return result;
}

/**
 * Tests that the Grid is correctly initialized.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::initGridTest() {
	bool result = true;

	std::cout << "Running initGridTest()\n";

	//We will create a Grid and then run through it to ensure that each Cell
	//meets the correctly initial cell requirements
	//i.e. occupationStatus == empty, pointer == nullPtr
	int size = 5; //We will create a five by five grid

	//Loop through Grid and make sure that each element was correctly created
	Grid* grid = new Grid(size);

	for(int r = 0; r < size; r++) {
		for(int c = 0; c < size; c++) { //Loop through each row and column
			//Get the status and pointer of each cell
			occupationStatus status = grid->getCellOccupant(r, c);
			Organism* orgPtr = grid->getCellOccupantPtr(r, c);

			//If both these conditions do not hold true then we do not pass test
			if(status != empty || orgPtr != nullptr) {
				result = false;
			}
		}
	}

	grid->~Grid();

	return result;
}

/**
 * Tests that the Grid can be correctly printed.
 *
 * The Grid created will look like this:
 *
 * 		--xo
 * 		-x-x
 * 		oxox
 * 		o--o
 * 	Where an 'x' is a doodlebug and an 'o' is an ant and '-' is a space
 *
 *
 * @return true if tests passes (must be inspected manually)
 * 		   false otherwise
 */
bool Tests2::printGrid() {
	bool result = true;

	std::cout << "Running printGrid()\n";

	//We create and print the first grid
	Grid* gridA = new Grid(4);

	//Make Doodlebugs
	Doodlebug* DA02 = new Doodlebug(0, 2, false);
	gridA->setCellOccupant(0, 2, doodlebug, DA02);

	Doodlebug* DA11 = new Doodlebug(1, 1, false);
	gridA->setCellOccupant(1, 1, doodlebug, DA11);

	Doodlebug* DA13 = new Doodlebug(1, 3, false);
	gridA->setCellOccupant(1, 3, doodlebug, DA13);

	Doodlebug* DA21 = new Doodlebug(2, 1, false);
	gridA->setCellOccupant(2, 1, doodlebug, DA21);

	Doodlebug* DA23 = new Doodlebug(2, 3, false);
	gridA->setCellOccupant(2, 3, doodlebug, DA23);

	//Make Ants
	Ant* AA03 = new Ant(0, 3, false);
	gridA->setCellOccupant(0, 3, ant, AA03);

	Ant* AA20 = new Ant(2, 0, false);
	gridA->setCellOccupant(2, 0, ant, AA20);

	Ant* AA22 = new Ant(2, 2, false);
	gridA->setCellOccupant(2, 2, ant, AA22);

	Ant* AA30 = new Ant(3, 0, false);
	gridA->setCellOccupant(3, 0, ant, AA30);

	Ant* AA33 = new Ant(3, 3, false);
	gridA->setCellOccupant(3, 3, ant, AA33);

	//Now we print the grid and make sure that it is the same as described in the header
	std::cout << "\n";
	gridA->printGrid();
	std::cout << "\n";

	//Destroy all the things we created
	delete DA02;
	delete DA11;
	delete DA13;
	delete DA21;
	delete DA23;
	delete AA03;
	delete AA20;
	delete AA22;
	delete AA30;
	delete AA33;
	gridA->~Grid();

	return result;
}

/**
 * Tests that the function correctly gets the Organism type of a Cell.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getOccupantTest() {
	bool result = true;
	bool ok1 = true; //We will have three sub-tests
	bool ok2 = true;
	bool ok3 = true;

	std::cout << "Running getOccupantTest()";

	//We will create three different cells and test if it correctly gets the
	//occupant from each one
	Cell* aCell = new Cell();

	//We will set different cell occupants in the Grid and see if we can get them
	//Getting an Ant
	Ant* anty = new Ant(3, 3, false);
	aCell->setOccupant(ant, anty); //We will create and set an Ant

	occupationStatus antAnother = aCell->getOccupant(); //The type should be Ant
	if(antAnother != ant) { //If not Ant, set the value to false
		ok1 = false;
	}

	//We will create another cell
	Cell* bCell = new Cell();

	//Now we will run a test with a Doodlebug
	Doodlebug* buggy = new Doodlebug(4, 4, false);
	bCell->setOccupant(doodlebug, buggy); //We create and set a new Doodlebug

	occupationStatus anotherBug = bCell->getOccupant(); //Should be Doodlebug
	if(anotherBug != doodlebug) { //If not we set value to false
		ok2 = false;
	}

	//Now we will test how this works with an empty cell
	//We will just get the occupant from cell and make sure that it is empty
	Cell* cCell = new Cell();
	occupationStatus shouldBEmpty = cCell->getOccupant();
	if(shouldBEmpty != empty) { //If its not empty, then we set value to false
		ok3 = false;
	}

	delete anty;
	delete buggy;
	delete aCell;
	delete bCell;
	delete cCell;

	result = ok1 && ok2 && ok3;

	return result;
}

/**
 * Tests that the function correctly sets the Organism type of a Cell.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::setOccupantTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running setOccupantTest()\n";

	//Create an Ant, put it in a Cell, and make sure that the type is Ant
	Cell* aCell = new Cell();
	Ant* anty = new Ant(3, 2, false);
	aCell->setOccupant(ant, anty);
	if(aCell->getOccupant() == ant) { //if we correctly set the type of the Cell
		ok1 = true;
	}

	//Repeat for Doodlebug
	//Create an Doodlebug, put it in a Cell, and make sure that the type is Doodlebug
	Cell* bCell = new Cell();
	Doodlebug* dood = new Doodlebug(3, 2, false);
	bCell->setOccupant(doodlebug, dood);
	if(bCell->getOccupant()==doodlebug) { //if we correctly set the type of the Cell
		ok2 = true;
	}

	delete anty;
	delete dood;
	aCell->~Cell();
	bCell->~Cell();

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that the function returns the correct pointer to an Organism.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getOccupantPtrTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running getOccupantPtrTest()\n";

	//Create an Ant, put it in a Cell, and make sure that the type is Ant
	Cell* aCell = new Cell();
	Ant* anty = new Ant(3, 2, false);
	aCell->setOccupant(ant, anty);

	//if we correctly get a pointer and coordinate
	if(aCell->getOccupantPtr()->getRow() == 3) {
		ok1 = true;
	}

	//Repeat for Doodlebug
	//Create an Doodlebug, put it in a Cell, and make sure that the type is Doodlebug
	Cell* bCell = new Cell();
	Doodlebug* dood = new Doodlebug(3, 2, false);
	bCell->setOccupant(doodlebug, dood);

	//If we correctly get the pointer and coordinate
	if(bCell->getOccupantPtr()->getCol() == 2) {
		ok2 = true;
	}

	delete anty;
	delete dood;
	aCell->~Cell();
	bCell->~Cell();

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that the function returns the correct row number that the Organism is
 * occupying.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getRowTest() {
	bool result = true;

	std::cout << "Running getRowTest()\n";

	//We will create an Ant and a Doodlebug and see if we can retrieve the row
	Ant* anty = new Ant(3, 8, false);
	if(anty->getRow() != 3) {
		result = false;
	}

	Doodlebug* buggy = new Doodlebug(5, 2, false);
	if(buggy->getRow() != 5) {
		result = false;
	}

	delete anty;
	delete buggy;

	return result;
}

/**
 * Tests that the function returns the correct column number that an Organism
 * is occupying.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getColTest() {
	bool result = true;

	std::cout << "Running getColTest()\n";

	//We will create an Ant and a Doodlebug and see if we can retrieve the column
	Ant* anty = new Ant(3, 8, false);
	if(anty->getCol() != 8) {
		result = false;
	}

	Doodlebug* buggy = new Doodlebug(5, 2, false);
	if(buggy->getCol() != 2) {
		result = false;
	}

	delete anty;
	delete buggy;

	return result;
}

/**
 * Tests that the skip variable returns the correct value.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getSkipTest() {
	bool result = true;

	std::cout << "Running getSkipTest()\n";

	//We will set an Organism as skip and as long as it correctly gets that it
	//is false, we pass the test
	Ant* anty = new Ant(3, 3, false);
	anty->setSkip(true);

	if(!anty->getSkip()) { //If skip is false we failed
		result = false;
	}

	delete anty;

	return result;
}

/**
 * Tests that the skip variable can be set correctly.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::setSkipTest() {
	bool result = false;

	std::cout << "Running setSkipTest()\n";

	//We will set an Organism as skip and as long as it correctly gets that it
	//is false, we pass the test
	Ant* anty = new Ant(3, 3, true);
	anty->setSkip(false);

	if(!anty->getSkip()) { //If skip is false we passed
		result = true;
	}

	delete anty;

	return result;
}

/**
 * Tests that the number of steps since an Organism breed is correct.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getStepsSinceBreedTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running getStepsSinceBreedTest()\n";

	//We will create an ant and the steps since breed should be zero
	Grid* griddy = new Grid(20);
	Ant* antt = new Ant(3, 2, false);
	griddy->setCellOccupant(3, 2, ant, antt);
	if(antt->getStepsSinceBreed() == 0) {
		ok1 = true;
	}
	char* argv[] = {nullptr}; //Create a fake argv[] and a production with it

	Production* prod = new Production(0, argv);

	prod->oneAntStep(griddy, 3, 2);
	if(antt->getStepsSinceBreed() == 1) {
		ok2 = true;
	}

	delete antt;
	griddy->~Grid();
	prod->~Production();

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that the function returns the space an Organism should move to.
 * Doodlebugs move to a Cell with an Ant before moving to an empty Cell. Ants
 * move to any random Cell. If no empty Cells, the function returns 0.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::targetCellTest() {
	bool result = true;

	std::cout << "Running targetCellTest()\n";

	Grid* griddy = new Grid(3); //Make Grid and add Ant and Doodlebug
	Ant* anty = new Ant(2, 0, false);
	Doodlebug* buggy = new Doodlebug(2,1, false);
	griddy->setCellOccupant(2, 0, ant, anty);
	griddy->setCellOccupant(2, 1, doodlebug, buggy);

	//This should be left since Doodlebug will want to move to Ant
	moveLocation move = buggy->targetCell(griddy, 2, 1, 3, true);
	if(move != left) {
		result = false;
	}

	//Now test that the Ant wants to move up one
	moveLocation moveAnt = anty->targetCell(griddy, 2, 0, 3, false);
	if(moveAnt != up) {
		result = false;
	}

	delete buggy;
	delete anty;
	griddy->~Grid();

	return result;
}

/**
 * Tests that an Ant can be created.
 * @return true if the test passes;
 * 		   false otherwise
 */
bool Tests2::makeAntsTest() {
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;

	std::cout << "Running makeAntsTest()\n";

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2) != empty) { //cells should be empty
		std::cout << "Cell 1,2 not initially empty\n";
	}

	Ant* a = new Ant(1, 2, false);
	myGrid_p->setCellOccupant(1, 2, ant, a);
	if(myGrid_p->getCellOccupant(1, 2) != ant) { //ant at [1][2]
		std::cout << "Cell not set to ant\n";
		ok1 = false;
	}

	Ant* a1 = new Ant(3, 4, false);
	if(myGrid_p->getCellOccupant(3, 4) != ant) { //ant at [3][4]
		std::cout << "Cell not set to ant\n";
	}

	Doodlebug* d = new Doodlebug(3, 4, false);
	myGrid_p->setCellOccupant(3, 4, doodlebug, d);
	if(myGrid_p->getCellOccupant(3, 4) != doodlebug) { //changes [3][4] to Doodlebug
		std::cout << "Cell not set to doodlebug\n";
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty, nullptr);

	delete a;
	delete a1;
	delete d;
	delete myGrid_p;

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that an Ant can move to an adjacent spot
 * @return true if the test passes;
 * 		   false otherwise
 *
 * 		   Initial Grid:
 * 		     0123456789
 * 		   0 ---------- 0
 * 		   1 -AA-D----- 1  A = Ant
 * 		   2 --A------- 2  D = Doodlebug
 * 		   3 ---------- 3  - = empty
 * 		   4 -------A-- 4
 * 		   5 ------AAA- 5
 * 		   6 -------A-- 6
 * 		   7 ----A----- 7
 * 		   8 ---------- 8
 * 		   9 ---------A 9
 * 		     0123456789
 */
bool Tests2::antsMoveTest() {
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;

	std::cout << "Running antsMoveTest()\n";

	//creates Grid, Ants, and Doodlebugs
	Grid* myGrid_p = new Grid(10);
	Ant* a11 = new Ant(1, 1, false);
	Ant* a12 = new Ant(1, 2, false);
	Ant* a22 = new Ant(2, 2, false);
	Doodlebug* d14 = new Doodlebug(1, 4, false);
	Ant* a47 = new Ant(4, 7, false);
	Ant* a56 = new Ant(5, 6, false);
	Ant* a57 = new Ant(5, 7, false);
	Ant* a58 = new Ant(5, 8, false);
	Ant* a67 = new Ant(6, 7, false);
	Ant* a74 = new Ant(7, 4, false);
	Ant* a99 = new Ant(9, 9, false);

	//adding the Ants and Doodlebugs to the Grid
	myGrid_p->setCellOccupant(1, 1, ant, a11);
	myGrid_p->setCellOccupant(1, 2, ant, a12);
	myGrid_p->setCellOccupant(2, 2, ant, a22);
	myGrid_p->setCellOccupant(1, 4, doodlebug, d14);
	myGrid_p->setCellOccupant(4, 7, ant, a47);
	myGrid_p->setCellOccupant(5, 6, ant, a56);
	myGrid_p->setCellOccupant(5, 7, ant, a57);
	myGrid_p->setCellOccupant(5, 8, ant, a58);
	myGrid_p->setCellOccupant(6, 7, ant, a67);
	myGrid_p->setCellOccupant(7, 4, ant, a74);
	myGrid_p->setCellOccupant(9, 9, ant, a99);

	//has a few options for moving
	a12->move(myGrid_p, 10);
	if((a12->getRow() == 1 && a12->getCol() == 3)
			|| (a12->getRow() == 0 && a12->getCol() == 2)) {
		ok1 = true;
	}

	//cannot move
	a57->move(myGrid_p, 10);
	if(a57->getRow() == 5 && a57->getCol() == 7) {
		ok2 = true;
	}

	//can move to any spot
	a74->move(myGrid_p, 10);
	if((a74->getRow() == 7 && a74->getCol() == 3)
			|| (a74->getRow() == 7 && a74->getCol() == 5)
			|| (a74->getRow() == 6 && a74->getCol() == 4)
			|| (a74->getRow() == 8 && a74->getCol() == 4)) {
		ok3 = true;
	}

	//can move, but is in a corner
	a99->move(myGrid_p, 10);
	if((a99->getRow() == 8 && a99->getCol() == 9)
			|| (a99->getRow() == 9 && a99->getCol() == 8)) {
		ok4 = true;
	}

	delete a11;
	delete a12;
	delete a22;
	delete d14;
	delete a47;
	delete a56;
	delete a57;
	delete a58;
	delete a67;
	delete a74;
	delete a99;
	delete myGrid_p;

	result = ok1 && ok2 && ok3 && ok4;
	return result;
}

/**
 * Tests that an Ant can breed and produce a new Ant in an adjacent Cell.
 * @return true if the test passes;
 * 		   false otherwise
 *
 * 		   Initial Grid:
 * 		     0123456789
 * 		   0 ---------- 0
 * 		   1 -AA-A----- 1  A = Ant
 * 		   2 --A------- 2  D = Doodlebug
 * 		   3 ---------- 3  - = empty
 * 		   4 -------AD- 4
 * 		   5 ------AAA- 5
 * 		   6 -------A-- 6
 * 		   7 ----A----- 7
 * 		   8 ---------- 8
 * 		   9 ---------A 9
 * 		     0123456789
 */
bool Tests2::antsBreedTest() {
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;

	std::cout << "Running antsBreedTest()\n";

	//creates Grid, Ants, and Doodlebugs
	Grid* myGrid_p = new Grid(10);
	Ant* a11 = new Ant(1, 1, false);
	Ant* a12 = new Ant(1, 2, false);
	Ant* a22 = new Ant(2, 2, false);
	Ant* a14 = new Ant(1, 4, false);
	Ant* a47 = new Ant(4, 7, false);
	Doodlebug* d48 = new Doodlebug(4, 8, false);
	Ant* a56 = new Ant(5, 6, false);
	Ant* a57 = new Ant(5, 7, false);
	Ant* a58 = new Ant(5, 8, false);
	Ant* a67 = new Ant(6, 7, false);
	Ant* a74 = new Ant(7, 4, false);
	Ant* a99 = new Ant(9, 9, false);

	//adds the Ants and Doodlebugs to the Grid
	myGrid_p->setCellOccupant(1, 1, ant, a11);
	myGrid_p->setCellOccupant(1, 2, ant, a12);
	myGrid_p->setCellOccupant(2, 2, ant, a22);
	myGrid_p->setCellOccupant(1, 4, ant, a14);
	myGrid_p->setCellOccupant(4, 7, ant, a47);
	myGrid_p->setCellOccupant(4, 8, doodlebug, d48);
	myGrid_p->setCellOccupant(5, 6, ant, a56);
	myGrid_p->setCellOccupant(5, 7, ant, a57);
	myGrid_p->setCellOccupant(5, 8, ant, a58);
	myGrid_p->setCellOccupant(6, 7, ant, a67);
	myGrid_p->setCellOccupant(7, 4, ant, a74);
	myGrid_p->setCellOccupant(9, 9, ant, a99);

	//all adjacent Cells empty
	bool breed = a14->breed(myGrid_p, 10);
	if(breed && ((myGrid_p->getCellOccupant(0, 4) == ant)
			|| (myGrid_p->getCellOccupant(2, 4) == ant)
			|| (myGrid_p->getCellOccupant(1, 3) == ant)
			|| (myGrid_p->getCellOccupant(1, 5) == ant))) {
		ok1 = true;
	}

	//no open adjacent Cells
	breed = a57->breed(myGrid_p, 10);
	if(!breed) {
		ok2 = true;
	}

	//only two adjacent Cells open
	breed = a58->breed(myGrid_p, 10);
	if(breed && ((myGrid_p->getCellOccupant(5, 9) == ant)
			|| (myGrid_p->getCellOccupant(6, 8) == ant))) {
		ok3 = true;
	}

	//Ant in a corner Cell
	breed = a99->breed(myGrid_p, 10);
	if(breed && ((myGrid_p->getCellOccupant(8, 9) == ant)
			|| (myGrid_p->getCellOccupant(9, 8) == ant))) {
		ok4 = true;
	}

	delete a11;
	delete a12;
	delete a22;
	delete a14;
	delete a47;
	delete d48;
	delete a56;
	delete a57;
	delete a58;
	delete a67;
	delete a74;
	delete a99;
	delete myGrid_p;

	result = ok1 && ok2 && ok3 && ok4;
	return result;
}

/**
 * Tests that a Doodlebug is correctly created.
 * @return true if the test passes;
 * 		   false otherwise
 */
bool Tests2::makeDoodlesTest() {
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running makeDoodlesTest()\n";

	Grid* myGrid_p = new Grid(9); //creates grid
	if(myGrid_p->getCellOccupant(1, 2) != empty) { //cell should be empty
		std::cout << "Cell 1,2 not initially empty]n";
	}

	Doodlebug* d = new Doodlebug(1, 2, false);
	myGrid_p->setCellOccupant(1, 2, doodlebug, d);
	if(myGrid_p->getCellOccupant(1, 2) != doodlebug) { //Doodlebug at [1][2]
		std::cout << "Cell not set to doodlebug\n";
		ok1 = false;
	}

	Doodlebug* d1 = new Doodlebug(3, 4, false);
	myGrid_p->setCellOccupant(3, 4, doodlebug, d1);
	if(myGrid_p->getCellOccupant(3, 4) != doodlebug) { //Doodlebug at [3][4]
		std::cout << "Cell not set to doodlebug\n";
		ok1 = false;
	}

	Ant* a = new Ant(3, 4, false);
	myGrid_p->setCellOccupant(3, 4, ant, a);
	if(myGrid_p->getCellOccupant(3, 4) != ant) { //Ant replaces Doodlebug at [3][4]
		std::cout << "Cell not set to ant\n";
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty, nullptr);

	delete d;
	delete d1;
	delete a;
	delete myGrid_p;

	result = ok1 && ok2;
	return result;
}

/**
 * Tests that a Doodlebug can correctly move to an adjacent Dell.
 * @return true if the test passes;
 * 		   false otherwise
 *
 * 		   Initial Grid:
 * 		     0123456789
 * 		   0 ---------- 0
 * 		   1 -AA-D----- 1  A = Ant
 * 		   2 --A------- 2  D = Doodlebug
 * 		   3 ---------- 3  - = empty
 * 		   4 -------AD- 4
 * 		   5 ------ADD- 5
 * 		   6 -------A-- 6
 * 		   7 ----A----- 7
 * 		   8 ---------- 8
 * 		   9 ---------D 9
 * 		     0123456789
 */
bool Tests2::doodleMoveTest() {
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;

	std::cout << "Running doodleMoveTest()\n";

	//creates Grid, Ants, and Doodlebugs
	Grid* myGrid_p = new Grid(10);
	Ant* a11 = new Ant(1, 1, false);
	Ant* a12 = new Ant(1, 2, false);
	Ant* a22 = new Ant(2, 2, false);
	Doodlebug* d14 = new Doodlebug(1, 4, false);
	Ant* a47 = new Ant(4, 7, false);
	Doodlebug* d48 = new Doodlebug(4, 8, false);
	Ant* a56 = new Ant(5, 6, false);
	Doodlebug* d57 = new Doodlebug(5, 7, false);
	Doodlebug* d58 = new Doodlebug(5, 8, false);
	Ant* a67 = new Ant(6, 7, false);
	Ant* a74 = new Ant(7, 4, false);
	Doodlebug* d99 = new Doodlebug(9, 9, false);

	//adds Ants and Doodlebugs to Grid
	myGrid_p->setCellOccupant(1, 1, ant, a11);
	myGrid_p->setCellOccupant(1, 2, ant, a12);
	myGrid_p->setCellOccupant(2, 2, ant, a22);
	myGrid_p->setCellOccupant(1, 4, doodlebug, d14);
	myGrid_p->setCellOccupant(4, 7, ant, a47);
	myGrid_p->setCellOccupant(4, 8, doodlebug, d48);
	myGrid_p->setCellOccupant(5, 6, ant, a56);
	myGrid_p->setCellOccupant(5, 7, doodlebug, d57);
	myGrid_p->setCellOccupant(5, 8, doodlebug, d58);
	myGrid_p->setCellOccupant(6, 7, ant, a67);
	myGrid_p->setCellOccupant(7, 4, ant, a74);
	myGrid_p->setCellOccupant(9, 9, doodlebug, d99);

	//all adjacent Cells empty
	bool move = d14->move(myGrid_p, 10);
	if(move && ((myGrid_p->getCellOccupant(0, 4) == doodlebug)
			|| (myGrid_p->getCellOccupant(2, 4) == doodlebug)
			|| (myGrid_p->getCellOccupant(1, 3) == doodlebug)
			|| (myGrid_p->getCellOccupant(1, 5) == doodlebug))) {
		ok1 = true;
	}

	//three Ants adjacent
	move = d57->move(myGrid_p, 10);
	if(move && ((myGrid_p->getCellOccupant(5, 6) == doodlebug)
			|| (myGrid_p->getCellOccupant(4, 7) == doodlebug)
			|| (myGrid_p->getCellOccupant(6, 7) == doodlebug))) {
		ok2 = true;
	}

	//one Ant adjacent & one empty adjacent; supposed to move to Ant Cell
	move = d48->move(myGrid_p, 10);
	if(move && (myGrid_p->getCellOccupant(4, 7) == doodlebug)) {
		ok3 = true;
	}

	//Doodlebug in a corner Cell
	move = d99->move(myGrid_p, 10);
	if(move && ((myGrid_p->getCellOccupant(8, 9) == doodlebug)
			|| (myGrid_p->getCellOccupant(9, 8) == doodlebug))) {
		ok4 = true;
	}

	delete a11;
	delete a12;
	delete a22;
	delete d14;
	//delete a47; -- Doodlebug can eat Ant here, Ant freed in move method
	delete d48;
	//delete a56; -- Doodlebug can eat Ant here, Ant freed in move method
	delete d57;
	delete d58;
	//delete a67; -- Doodlebug can eat Ant here, Ant freed in move method
	delete a74;
	delete d99;
	delete myGrid_p;

	result = ok1 && ok2 && ok3 && ok4;
	return result;
}

/**
 * Tests that a Doodlebug gives birth to a new Doodlebug in an adjacent Cell.
 * @return true if the test passes;
 * 		   false otherwise
 *
 * 		   Initial Grid:
 * 		     0123456789
 * 		   0 ---------- 0
 * 		   1 -AA-D----- 1  A = Ant
 * 		   2 --A------- 2  D = Doodlebug
 * 		   3 ---------- 3  - = empty
 * 		   4 -------AD- 4
 * 		   5 ------ADD- 5
 * 		   6 -------A-- 6
 * 		   7 ----A----- 7
 * 		   8 ---------- 8
 * 		   9 ---------D 9
 * 		     0123456789
 */
bool Tests2::doodleBreedTest() {
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;

	std::cout << "Running doodleBreedTest()\n";

	//creates Grid, Ants, and Doodlebugs
	Grid* myGrid_p = new Grid(10);
	Ant* a11 = new Ant(1, 1, false);
	Ant* a12 = new Ant(1, 2, false);
	Ant* a22 = new Ant(2, 2, false);
	Doodlebug* d14 = new Doodlebug(1, 4, false);
	Ant* a47 = new Ant(4, 7, false);
	Doodlebug* d48 = new Doodlebug(4, 8, false);
	Ant* a56 = new Ant(5, 6, false);
	Doodlebug* d57 = new Doodlebug(5, 7, false);
	Doodlebug* d58 = new Doodlebug(5, 8, false);
	Ant* a67 = new Ant(6, 7, false);
	Ant* a74 = new Ant(7, 4, false);
	Doodlebug* d99 = new Doodlebug(9, 9, false);

	//adds Ants and Doodlebugs to Grid
	myGrid_p->setCellOccupant(1, 1, ant, a11);
	myGrid_p->setCellOccupant(1, 2, ant, a12);
	myGrid_p->setCellOccupant(2, 2, ant, a22);
	myGrid_p->setCellOccupant(1, 4, doodlebug, d14);
	myGrid_p->setCellOccupant(4, 7, ant, a47);
	myGrid_p->setCellOccupant(4, 8, doodlebug, d48);
	myGrid_p->setCellOccupant(5, 6, ant, a56);
	myGrid_p->setCellOccupant(5, 7, doodlebug, d57);
	myGrid_p->setCellOccupant(5, 8, doodlebug, d58);
	myGrid_p->setCellOccupant(6, 7, ant, a67);
	myGrid_p->setCellOccupant(7, 4, ant, a74);
	myGrid_p->setCellOccupant(9, 9, doodlebug, d99);

	//Can give births to all adjacent Cells
	bool breed = d14->breed(myGrid_p, 10);
	if(breed && ((myGrid_p->getCellOccupant(0, 4) == doodlebug)
			|| (myGrid_p->getCellOccupant(2, 4) == doodlebug)
			|| (myGrid_p->getCellOccupant(1, 3) == doodlebug)
			|| (myGrid_p->getCellOccupant(1, 5) == doodlebug))) {
		ok1 = true;
	}

	//no adjacent Cells available
	breed = d57->breed(myGrid_p, 10);
	if(!breed) {
		ok2 = true;
	}

	//only a couple adjacent Cells available for birth
	breed = d58->breed(myGrid_p, 10);
	if(breed && ((myGrid_p->getCellOccupant(5, 9) == doodlebug)
			|| (myGrid_p->getCellOccupant(6, 8) == doodlebug))) {
		ok3 = true;
	}

	//Doodlebug is in a corner Cell
	breed = d99->breed(myGrid_p, 10);
	if(breed && ((myGrid_p->getCellOccupant(8, 9) == doodlebug)
			|| (myGrid_p->getCellOccupant(9, 8) == doodlebug))) {
		ok4 = true;
	}

	delete a11;
	delete a12;
	delete a22;
	delete d14;
	delete a47;
	delete d48;
	delete a56;
	delete d57;
	delete d58;
	delete a67;
	delete a74;
	delete d99;
	delete myGrid_p;

	result = ok1 && ok2 && ok3 && ok4;
	return result;
}

/**
 * Tests that a Doodlebug properly eats.
 * @return true if the test passes;
 * 		   false otherwise
 */
bool Tests2::doodleEatTest() {
	bool result = true;

	std::cout << "Running doodleEatTest()\n";

	Grid* griddy = new Grid(20); //Make Grid and add Ant and Doodlebug
	Ant* anty = new Ant(2, 0, false);
	Doodlebug* buggy = new Doodlebug(2, 1, false);
	griddy->setCellOccupant(2, 0, ant, anty);
	griddy->setCellOccupant(2, 1, doodlebug, buggy);

	char* argv[] = {nullptr}; //Create a fake argv[] and a production with it

	Production* p = new Production(0, argv);

	p->oneDoodlebugStep(griddy, 2, 1); //Ant should be eaten and gone after this

	for(int r = 0; r < 20; r++) {
		for(int c = 0; c < 20; c++) {
			if(griddy->getCellOccupant(r, c) == ant) {
				result = false;
			}
		}
	}

	delete buggy;
	griddy->~Grid();

	return result;
}

/**
 * Tests that the number of steps since a Doodlebug ate is correct.
 * @return true if tests passes;
 * 		   false otherwise
 */
bool Tests2::getStepsSinceAteTest() {
	bool result = true;
	bool ok1 = false;
	bool ok2 = false;

	std::cout << "Running getStepsSinceAte()\n";

	//We will create an ant and the steps since ate should be zero
	Grid* griddy = new Grid(20);
	Doodlebug* bugg = new Doodlebug(3, 2, false);
	griddy->setCellOccupant(3, 2, doodlebug, bugg);
	if(bugg->getStepsSinceAte() == 0) {
		ok1 = true;
	}
	char* argv[] = {nullptr}; //Create a fake argv[] and a production with it

	Production* prod = new Production(0, argv);

	prod->oneDoodlebugStep(griddy, 3, 2);
	if(bugg->getStepsSinceAte() == 1) {
		ok2 = true;
	}

	delete bugg;
	griddy->~Grid();
	prod->~Production();

	result = ok1 && ok2;
	return result;
}

/**
 * Destructs a Test.
 */
Tests2::~Tests2() {

}
