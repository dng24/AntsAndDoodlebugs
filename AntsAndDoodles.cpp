//============================================================================
// Name        : AntsAndDoodles.cpp
// Author      : Derek Ng and Vishnu Penubarthi building on Therese building on Ciaraldi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tests2.h"
#include "Production.h"
class Tests;
class Production;

/**
 * Main method on which the other files are run from
 * @param argc Number of arguments on the Command Line
 * @param argv The array of arguments on the Command Line
 * @return 0 if the program runs successfully;
 * 		   -1 if the program terminates with an error
 */
int main(int argc, char* argv[]) { //gridSize #doodlebugs #ants #time_steps seed pause
	std::cout << "!!!Hello classmates, it's time for fun with C++!!!\n";
    Tests2 ts = Tests2();//see page 291
    if(ts.doTests()) {
		Production ps = Production(argc, argv);
		bool ok = ps.runProduction();
		if(ok) {
			puts("Production worked.");
		} else {
			puts("Production did not work.");
		}
		ps.~Production(); //done with production
	} else {
		puts("Some tests failed.");
	}
    ts.~Tests2(); //done with tests

	return 0; //The program will return a zero if it exits correctly
}
