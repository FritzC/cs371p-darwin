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
	
	darwin8x8.insertCreature(f1, pair<int, int>(0, 0));
	darwin8x8.insertCreature(h1, pair<int, int>(3, 3));
	darwin8x8.insertCreature(h2, pair<int, int>(4, 3));
	darwin8x8.insertCreature(h3, pair<int, int>(4, 4));
	darwin8x8.insertCreature(h4, pair<int, int>(3, 4));
	darwin8x8.insertCreature(f2, pair<int, int>(7, 7));
	
	darwin8x8.print();
    cout << endl;
	for (int i = 0; i < 5; i++) {
		darwin8x8.step();
		darwin8x8.print();
        cout << endl;
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

    Creature t1(trap, 3);
    Creature h5(hopper, 2);
    Creature r1(rover, 1);
    Creature t2(trap, 0);
    
    Darwin darwin7x9(9, 7);

    darwin7x9.insertCreature(t1, pair<int, int>(0, 0));
    darwin7x9.insertCreature(h5, pair<int, int>(2, 3));
    darwin7x9.insertCreature(r1, pair<int, int>(4, 5));
    darwin7x9.insertCreature(t2, pair<int, int>(8, 6));

    darwin7x9.print();
    cout << endl;
    for (int i = 0; i < 5; i++) {
        darwin7x9.step();
        darwin7x9.print();
        cout << endl;
    }

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

    Creature foods[10];
    Creature hoppers[10];
    Creature rovers[10];
    Creature traps[10];
    pair<int, int> locs[40];
    int face[40];

    Darwin darwin72x72(72, 72);

    for (int i = 0; i < 40; i++) {
        int locIdx = rand();
        locs[i] = pair<int, int>(locIdx % 5184 % 72, locIdx % 5184 / 72);
        face[i] = rand() % 4;
    }
    for (int i = 0; i < 10; i++) {
        foods[i] = Creature(food, face[i]);
        darwin72x72.insertCreature(foods[i], locs[i]);
    }
    for (int i = 0; i < 10; i++) {
        hoppers[i] = Creature(hopper, face[i + 10]);
        darwin72x72.insertCreature(hoppers[i], locs[i + 10]);
    }
    for (int i = 0; i < 10; i++) {
        rovers[i] = Creature(rover, face[i + 20]);
        darwin72x72.insertCreature(rovers[i], locs[i + 20]);
    }
    for (int i = 0; i < 10; i++) {
        traps[i] = Creature(trap, face[i + 30]);
        darwin72x72.insertCreature(traps[i], locs[i + 30]);
    } 

    darwin72x72.print();
    cout << endl;
    for (int i = 0; i < 9; i++) {
        darwin72x72.step();
        darwin72x72.print();
        cout << endl;
    }

    for (int i = 9; i < 1000; i++) {
        darwin72x72.step();
        if ((i + 1) % 100 == 0) {
            darwin72x72.print();
            cout << endl;
        }
    }

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

    Creature foods2[10];
    Creature hoppers2[10];
    Creature rovers2[10];
    Creature traps2[10];
    Creature best2[10];
    pair<int, int> locs2[50];
    int face2[50];

    Darwin darwin72x72b(72, 72);

    for (int i = 0; i < 50; i++) {
        int locIdx = rand();
        locs2[i] = pair<int, int>(locIdx % 5184 % 72, locIdx % 5184 / 72);
        face2[i] = rand() % 4;
    }
    for (int i = 0; i < 10; i++) {
        foods2[i] = Creature(food, face2[i]);
        darwin72x72b.insertCreature(foods2[i], locs2[i]);
    }
    for (int i = 0; i < 10; i++) {
        hoppers2[i] = Creature(hopper, face2[i + 10]);
        darwin72x72b.insertCreature(hoppers2[i], locs2[i + 10]);
    }
    for (int i = 0; i < 10; i++) {
        rovers2[i] = Creature(rover, face2[i + 20]);
        darwin72x72b.insertCreature(rovers2[i], locs2[i + 20]);
    }
    for (int i = 0; i < 10; i++) {
        traps2[i] = Creature(trap, face2[i + 30]);
        darwin72x72b.insertCreature(traps2[i], locs2[i + 30]);
    }
    Species best('b');
    best.addInstruction("if_enemy 4");
    best.addInstruction("if_empty 6");
    best.addInstruction("left");
    best.addInstruction("go 0");
    best.addInstruction("infect");
    best.addInstruction("go 0");
    best.addInstruction("hop");
    best.addInstruction("go 0");

    for (int i = 0; i < 10; i++) {
        best2[i] = Creature(best, face2[i + 40]);
        darwin72x72b.insertCreature(best2[i], locs2[i + 40]);
    } 

    darwin72x72b.print();
    cout << endl;
    for (int i = 0; i < 9; i++) {
        darwin72x72b.step();
        darwin72x72b.print();
    }

    for (int i = 9; i < 1000; i++) {
        darwin72x72b.step();
        if ((i + 1) % 100 == 0) {
            cout << endl;
            darwin72x72b.print();
        }
    }

    return 0;}
