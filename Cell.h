/*
 * Cell.h
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#ifndef CELL_H_
#define CELL_H_

class Organism;

enum occupationStatus {empty, ant, doodlebug}; //type occupying a Cell

class Cell {
public:
	Cell();
	occupationStatus getOccupant();
	void setOccupant(occupationStatus g, Organism* o_ptr);
	Organism* getOccupantPtr();
	virtual ~Cell();

private:
	Organism* org; //pointer to an Organism
	occupationStatus guest; //the type of Organism occupying the Cell, empty if no Organism
};

#endif /* CELL_H_ */
