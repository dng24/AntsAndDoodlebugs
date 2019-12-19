/*
 * Tests2.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef TESTS2_H_
#define TESTS2_H_

class Tests2 {
public:
	Tests2();
	bool doTests();

	//Production functions
	bool runProductionTest();
	bool oneDoodlebugStepTest();
	bool oneAntStepTest();

	//Grid functions
	bool gridTest();
	bool getCellOccupantTest();
	bool setCellOccupantTest();
	bool getCellOccupantPtrTest();
	bool initGridTest();
	bool printGrid();

	//Cell functions
	bool getOccupantTest();
	bool setOccupantTest();
	bool getOccupantPtrTest();

	//Organism functions
	bool getRowTest();
	bool getColTest();
	bool getSkipTest();
	bool setSkipTest();
	bool getStepsSinceBreedTest();
	bool targetCellTest();

	//Ant functions
	bool makeAntsTest();
	bool antsMoveTest();
	bool antsBreedTest();

	//Doodlebug functions
	bool makeDoodlesTest();
	bool doodleMoveTest();
	bool doodleBreedTest();
	bool doodleEatTest();
	bool getStepsSinceAteTest();

	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
