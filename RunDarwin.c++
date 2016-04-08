// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----
    // food
    // ----
	
	Species food('f');

    /*
     0: left
     1: go 0
    */
	
	food.addInstruction("left");
	food.addInstruction("go 0");

    // ------
    // hopper
    // ------
	
	Species hopper('h');

    /*
     0: hop
     1: go 0
    */
	
	hopper.addInstruction("hop");
	hopper.addInstruction("go 0");

    // -----
    // rover
    // -----
	
	Species rover('r');

    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: left
     4: go 0
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */
	
	rover.addInstruction("if_enemy 9");
	rover.addInstruction("if_empty 7");
	rover.addInstruction("if_random 5");
	rover.addInstruction("left");
	rover.addInstruction("go 0");
	rover.addInstruction("right");
	rover.addInstruction("go 0");
	rover.addInstruction("hop");
	rover.addInstruction("go 0");
	rover.addInstruction("infect");
	rover.addInstruction("go 0");

    // ----
    // trap
    // ----
	
	Species trap('t');

    /*
     0: if_enemy 3
     1: left
     2: go 0
     3: infect
     4: go 0
    */
	
	trap.addInstruction("if_enemy 3");
	trap.addInstruction("left");
	trap.addInstruction("go 0");
	trap.addInstruction("infect");
	trap.addInstruction("go 0");

    // ----------
    // darwin 8x8
    // ----------

    cout << "*** Darwin 8x8 ***" << endl;
    /*
    8x8 Darwin
    Food,   facing east,  at (0, 0)
    Hopper, facing north, at (3, 3)
    Hopper, facing east,  at (3, 4)
    Hopper, facing south, at (4, 4)
    Hopper, facing west,  at (4, 3)
    Food,   facing north, at (7, 7)
    Simulate 5 moves.
    Print every grid.
    */
	
	Darwin darwin8x8(8, 8);
	
	Creature f1(food, 2);
	Creature h1(hopper, 1);
	Creature h2(hopper, 2);
	Creature h3(hopper, 3);
	Creature h4(hopper, 0);
	Creature f2(food, 1);
	
	darwin8x8.insertCreature(&f1, pair<int, int>(0, 0));
	darwin8x8.insertCreature(&h1, pair<int, int>(3, 3));
	darwin8x8.insertCreature(&h2, pair<int, int>(3, 4));
	darwin8x8.insertCreature(&h3, pair<int, int>(4, 4));
	darwin8x8.insertCreature(&h4, pair<int, int>(4, 3));
	darwin8x8.insertCreature(&f2, pair<int, int>(7, 7));
	
	darwin8x8.print();
	for (int i = 0; i < 5; i++) {
		darwin8x8.step();
		darwin8x8.print();
	}

    // ----------
    // darwin 7x9
    // ----------

    cout << "*** Darwin 7x9 ***" << endl;
    srand(0);
    /*
    7x9 Darwin
    Trap,   facing south, at (0, 0)
    Hopper, facing east,  at (3, 2)
    Rover,  facing north, at (5, 4)
    Trap,   facing west,  at (6, 8)
    Simulate 5 moves.
    Print every grid.
    */

    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
    the ordering: west, north, east, south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    Simulate 1000 moves.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */

    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
    the ordering: 0:west, 1:north, 2:east, 3:south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    10 Best
    Simulate 1000 moves.
    Best MUST outnumber ALL other species for the bonus pts.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */

    return 0;}
