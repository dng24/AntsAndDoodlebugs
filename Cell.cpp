/*
 * Cell.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: Derek Ng and Vishnu Penubarthi
 */

#include "Cell.h"
#include <typeinfo>

/**
 * Constructs a Cell.
 */
Cell::Cell() {
	guest = empty;
	org = nullptr;
}

/**
 * Gets whether the Cell is occupied by an Ant or Doodlebug, or if it's empty.
 * @return The Ant or Doodlebug in a Cell. If not occupied, returns empty
 */
occupationStatus Cell::getOccupant() {
	return guest;
}

/**
 * Sets the occupant of a Cell.
 * @param g ant, doodlebug, or empty
 * @param o_ptr The pointer to an Organism or nullptr if empty
 */
void Cell::setOccupant(occupationStatus g, Organism* o_ptr) {
	guest = g; //Set the guest type and the pointer
	org = o_ptr;
}

/**
 * Gets the pointer in the Cell.
 * @return The pointer to the Cell
 */
Organism* Cell::getOccupantPtr() {
	return org;
}

/**
 * Destructs a Cell.
 */
Cell::~Cell() {

}
