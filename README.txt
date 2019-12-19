Ant and Doodlebug Readme

Created by Derek Ng & Vishnu Penubarthi
WPI username: djng & vspenubarthi
CS 2303

This program is a simulation of ants and doodlebugs and their interactions with
one another. The simulation consists of a grid in which each cell contains an
ant, a doodlebug, or is empty. The simulation begins with a random
configuration of ants and doodlebugs. Time is simulated using time steps. The 
order in which the organisms move in a time step is from top to bottom, left to
right. However, doodlebugs move before ants. A new time step begins when the
program is processing the upper left cell, and the time step ends after
processing the bottom right cell. If eligible, each organism can perform the 
following actions in each time step:

Doodlebug Actions:

  Move
  - If none of the the adjacent cells (up, right, down, left) contain another
    doodlebug, the doodlebug can move there. If all adjacent cells contain
    doodlebugs, the doodlebug stays in its current cell.
   
  Eat
  - A doodlebug can eat an ant if the cell that it is moving to contains an
    ant. When consuming the ant, the ant is deleted from the program and the
    doodlebug take its spot in the cell. Doodlebugs will choose to move to a
    cell containing an ant over moving to an empty cell. If a doodlebug does
    not consume an ant within three consecutive time steps, the doodlebug dies
    at the end of the third step and is deleted from the program.
    
  Breed
  - A doodlebug breeds after it survives for eight time steps. At the end of
    the eighth time step, the doodlebug spawns a new doodlebug in an adjacent
    and empty cell. If there are no open cells, no breeding occurs, but the
    doodlebug is free to breed the next time step, assuming that there are open
    cells. Once a doodlebug breeds, it must wait eight additional time steps
    before it may breed again. A newborn doodlebug is not eligible to perform
    actions until the next time step.
    
Ant Actions:

  Move
  - If none of the adjacent cells (up, right, down, left) contain another
    organism, the ant can move there. If all adjacent cells contain another
    organism, the ant stays in its current cell.
    
  Breed
  - An ant breeds after it survives for three time steps. At the end of the
    third time step, the ant spawns a new ant in an adjacent and empty cell.
    If there are no open cells, no breeding occurs, but the ant is free to
    breed during the next time step, assuming that there are open cells. Once
    an ant breeds, it must wait three additional time steps before it may
    breed again. A newborn ant is not eligible to perform actions until the
    next time step.
 
The program ends when there are either no more ants or doodlebugs on the grid
or if the specified number of time steps have been reached.

To begin the simulation, the program takes in the following arguments from the
command line:

  - grid size: a positive integer that represents the number of cells along an
    edge of the grid. If the argument is invalid, the program will default grid
    size to twenty. If the sum of the doodlebug and ant arguments are greater
    than the number of cells in the grid, the grid size will increase to the
    minimum value needed to hold all the doodlebugs and ants.

  - number of doodlebugs: a positive integer indicating the initial number of
    doodlebugs. If the argument is invalid, the program will default the number
    of doodlebugs to five.

  - number of ants: a positive integer indicating the initial number of ants.
    If the argument is invalid, the program will default the number of ants to
    one hundred.

  - number of time steps: a positive integer representing the maximum number of
    time steps that the program will run for. If the argument is invalid, the
    program will default the number of time steps to one thousand.

  - seed: an integer used to determine the seed for random number generating.
    Input an argument of zero (0) if the seed used should be the current time.
    If the argument is invalid, the program will default seed to one.

  - pause: a non-negative integer representing the number of time steps that 
    should pass before printing out the current grid. After the grid has been
    printed, press the enter key to continue the simulation. If the argument is
    zero (0), only the final configuration will be printed. If the argument is
    invalid, the program will default pause to zero.
    
If less than six arguments are provided, the program will fill in the remaining
parameters with the default values. If more than six arguments are provided,
only the first six arguments will be considered. An parameter cannot be
specified without specifying the one before it.
    
Principal Classes and Methods

  - Ant Class
    - bool move(Grid* g, int n);
      The move() function moves an ant, if possible.
      
    - bool breed(Grid* g, int n);
      The breed() function allows an ant to breed, if possible, spawning a new
      ant in an empty, adjacent cell.
      
  - Doodlebug Class
    - bool move(Grid* g, int n);
      The move() function moves a doodlebug, if possible, to a cell containing
      an ant or is empty.
      
    - bool breed(Grid* g, int n);
      The breed() function allows a doodlebug to breed, if possible, spawning
      a new doodlebug in an empty, adjacent cell.
      
    - bool eat(Grid* g);
      The eat() function allows a doodlebug to eat an ant. The program deletes
      the ant when the function is invoked.
      
  - Grid Class
    - void initGrid(int gridSize, int numAnts, int numDoodlebugs);
      The initGrid() function creates the grid and populates it randomly with
      the specified number of ants and doodlebugs.
      
    - void printGrid();
      The printGrid() function prints the grid in its current state.
      
  - Organism Class
    - moveLocation targetCell(Grid* g, int r, int c, int n, bool dMove);
      The targetCell() function determines the cell that an ant or doodlebug
      should move to or breed into.
      
  - Production Class
    - bool runProduction();
      The runProduction() function runs the simulation after the command line
      arguments have been inputed.
      
    - bool oneDoodlebugStep(Grid* g, int r, int c);
      The oneDoodlebugStep() function simulates one time step for a single
      doodlebug.
      
    - bool oneAntStep(Grid* g, int r, int c);
      The oneAntStep() function simulates one time step for a single ant.