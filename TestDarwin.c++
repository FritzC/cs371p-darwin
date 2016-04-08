#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <vector>
#include <assert.h>

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

/**
 * Check to see ensure Darwins' turns are exclusive
 */
TEST(DarwinFixture, initDarwin1) {
	Darwin d(1, 1);
	d.step();
	Darwin d2(1, 1);
	assert(d2.turn == 0);
}

/**
 * Check to see ensure Darwins' width is being set correctly
 */
TEST(DarwinFixture, initDarwin2) {
	Darwin d(122, 1);
	assert(d.width == 122);
}

/**
 * Check to see ensure Darwins' width is being set correctly
 */
TEST(DarwinFixture, initDarwin3) {
	Darwin d(1, 1444);
	assert(d.height == 1444);
}

/**
 * Check to see ensure Darwin can handle creating a grid of size 0
 */
TEST(DarwinFixture, initDarwin4) {
	Darwin d(0, 0);
}

/**
 * Check to see if begin() is working correctly
 */
TEST(DarwinFixture, begin1) {
	Darwin d(1, 1);
	assert(d.begin() == &d.grid[0]);
}

/**
 * Check to see if begin() is working correctly
 */
TEST(DarwinFixture, begin2) {
	 Darwin d(12, 144);
	 assert(d.begin() == &d.grid[0]);
}

/**
 * Check to see if begin() is working correctly
 */
TEST(DarwinFixture, begin3) {
	Darwin d(152, 0);
	assert(d.begin() == d.grid.data());
}

/**
 * Check to see if end() is working correctly
 */
TEST(DarwinFixture, end1) {
	Darwin d(1, 1);
	assert(d.end() == d.grid.data() + 1);
}

/**
 * Check to see if end() is working correctly
 */
TEST(DarwinFixture, end2) {
	Darwin d(12, 144);
	assert(d.end() == d.grid.data() + (12 * 144));
}

/**
 * Check to see if end() is working correctly for size 0
 */
TEST(DarwinFixture, end3) {
	Darwin d(152, 0);
	assert(d.end() == d.grid.data());
}

/**
 * Check interaction between begin() and end()
 */
TEST(DarwinFixture, end4) {
	Darwin d(152, 0);
	assert(d.end() == d.begin());
}

/**
 * Check if at works
 */
TEST(DarwinFixture, at1) {
	Species food('f');
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	assert(*d.begin() == d.at(0));
}

/**
 * Check vs direct access
 */
TEST(DarwinFixture, at2) {
	Species food('f');
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	assert(d.grid[0] == d.at(0));
}

/**
 * Check for negative access
 */
TEST(DarwinFixture, at3) {
	Darwin d(5, 5);	
	try {
		d.at(-1);
		assert(false);
	} catch(invalid_argument& e) {}
}

/**
 * Check for out of bounds access
 */
TEST(DarwinFixture, at4) {
	Darwin d(5, 5);	
	try {
		d.at(100);
		assert(false);
	} catch(invalid_argument& e) {}
}

/**
 * Test creature insertion
 */
TEST(DarwinFixture, insertCreature1) {
	Species food('f');
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	assert(&c == d.grid[0]);
}

/**
 * Test creature insertion at another location
 */
TEST(DarwinFixture, insertCreature2) {
	Species food('f');
	Creature c(food, 1);

	Darwin d(6, 6);	
	d.insertCreature(c, pair<int, int>(5, 0));
	assert(&c == d.grid[5]);
}

/**
 * Check location for empty space
 */
TEST(DarwinFixture, checkLocation1) {
	Darwin d(5, 5);	
	assert(d.getLocationType(nullptr, pair<int, int>(0, 0)) == Creature::EMPTY);
}

/**
 * Check for out of bounds access
 */
TEST(DarwinFixture, checkLocation2) {
	Darwin d(5, 5);	
	assert(d.getLocationType(nullptr, pair<int, int>(-10, 0)) == Creature::INVALID);
}

/**
 * Check location if occupied
 */
TEST(DarwinFixture, checkLocation3) {
	Species food('f');
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	assert(d.getLocationType(nullptr, pair<int, int>(0, 0)) == Creature::OCCUPIED);
}

/**
 * Check location if occupied with a Creature nearby
 */
TEST(DarwinFixture, checkLocation4) {
	Species food('f');
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	assert(d.getLocationType(nullptr, pair<int, int>(1, 0)) == Creature::EMPTY);
}

/**
 * Check if step works
 */
TEST(DarwinFixture, step1) {
	Species food('f');
	food.addInstruction("left");
	food.addInstruction("go 0");
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	d.step();
	assert(c.face == 0);
}

/**
 * Check multiple steps
 */
TEST(DarwinFixture, step2) {
	Species food('f');
	food.addInstruction("left");
	food.addInstruction("go 0");
	Creature c(food, 1);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	d.step();
	d.step();
	assert(c.face == 3);
}

/**
 * Check if Creature is skipped when already moved that turn
 */
TEST(DarwinFixture, step3) {
	Species food('f');
	food.addInstruction("hop");
	food.addInstruction("go 0");
	Creature c(food, 3);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	d.step();
	assert(d.at(5) == &c);
}

/**
 * Check if getCreatureAt() gets the creature
 */
TEST(DarwinFixture, creatureAt1) {
	Species food('f');
	Creature c(food, 0);

	Darwin d(5, 5);	
	d.insertCreature(c, pair<int, int>(0, 0));
	assert(d.getCreatureAt(pair<int, int>(0, 0)) == &c);
}

/**
 * Check if getCreatureAt() handles bad arguments
 */
TEST(DarwinFixture, creatureAt2) {
		Darwin d(5, 5);	
	try {
		d.getCreatureAt(pair<int, int>(-1, 0));
		assert(false);
	} catch(invalid_argument& e) {}
}

/**
 * Check case if there is no creature
 */
TEST(DarwinFixture, creatureAt3) {
	Darwin d(5, 5);	
	assert(d.getCreatureAt(pair<int, int>(0, 0)) == nullptr);
}

/**
 * Tests basic creature initialization
 */
TEST(DarwinFixture, initCreature1) {
	Species f('f');
	Creature c(f, 3);
	assert(c.species->identifier == 'f');
}

/**
 * Tests basic creature initialization
 */
TEST(DarwinFixture, initCreature2) {
	Species f('f');
	Creature c(f, 0);
	assert(c.face == 0);
}

/**
 * Tests basic creature initialization
 */
TEST(DarwinFixture, initCreature3) {
	Species f('f');
	Creature c(f, 0);
	assert(c.currentStep == 0);
}

/**
 * Tests if getAction() works as expected
 */
TEST(DarwinFixture, getAction1) {
	Species f('f');
	f.addInstruction("hop");
	f.addInstruction("go 0");
	Creature c(f, 0);
	assert(c.getAction(Creature::EMPTY) == Creature::MOVE);
}

/**
 * Tests if getAction() prevents moving into wall
 */
TEST(DarwinFixture, getAction2) {
	Species f('f');
	f.addInstruction("hop");
	f.addInstruction("go 0");
	Creature c(f, 0);
	assert(c.getAction(Creature::INVALID) == Creature::NONE);
}

/** 
 * Tests if getAction() prevents moving into wall case 2
 */
TEST(DarwinFixture, getAction3) {
	Species f('f');
	f.addInstruction("hop");
	f.addInstruction("go 0");
	Creature c(f, 0);
	assert(c.getAction(Creature::ENEMY) == Creature::NONE);
}

/** 
 * Tests if getAction() infection works
 */
TEST(DarwinFixture, getAction4) {
	Species f('f');
	f.addInstruction("infect");
	f.addInstruction("go 0");
	Creature c(f, 0);
	assert(c.getAction(Creature::EMPTY) == Creature::NONE);
}

/** 
 * Tests if getAction() infection works
 */
TEST(DarwinFixture, getAction5) {
	Species f('f');
	f.addInstruction("infect");
	f.addInstruction("go 0");
	Creature c(f, 0);
	assert(c.getAction(Creature::ENEMY) == Creature::NONE);
}

/** 
 * Checks the program counter after a creature steps
 */
TEST(DarwinFixture, getAction6) {
	Species f('f');
	f.addInstruction("go 1");
	f.addInstruction("hop");
	f.addInstruction("go 0");
	Creature c(f, 0);
	c.getAction(Creature::EMPTY);
	assert(c.currentStep == 2);
}

/** 
 * Tests if getAction() handles bad programs
 */
TEST(DarwinFixture, getAction7) {
	Species f('f');
	f.addInstruction("hop");
	f.addInstruction("go 10");
	Creature c(f, 0);
	c.getAction(Creature::EMPTY);
	c.getAction(Creature::EMPTY);
	assert(c.currentStep == 1);
}

/** 
 * Tests infecting a creature
 */
TEST(DarwinFixture, infect1) {
	Species f('f');
	Species a('a');
	Creature c(f, 0);
	Creature c2(a, 0);
	c.infect(&c2);
	assert(c2.species == &f);
}

/** 
 * Tests infecting a creature
 */
TEST(DarwinFixture, infect2) {
	Species f('s');
	Species a('a');
	Creature c(f, 0);
	Creature c2(a, 0);
	c.infect(&c2);
	assert(c2.species == &f);
}

/** 
 * Tests checkIfEnemy() if different Species
 */
TEST(DarwinFixture, checkEnemy1) {
	Species f('s');
	Species a('a');
	Creature c(f, 0);
	Creature c2(a, 0);
	assert(!c.checkIfEnemy(&c2));
}

/** 
 * Tests checkIfEnemy() if same species
 */
TEST(DarwinFixture, checkEnemy2) {
	Species f('s');
	Creature c(f, 0);
	Creature c2(f, 0);
	assert(c.checkIfEnemy(&c2));
}

/** 
 * Tests if resetTurn() resets the creature's turn flag 
 * after an action is fetched
 */
TEST(DarwinFixture, resetTurn1) {
	Species f('s');
	f.addInstruction("hop");
	Creature c(f, 0);
	c.getAction(Creature::INVALID);
	c.resetTurn();
	assert(!c.moved);
}

/** 
 * Tests if resetTurn() resets the creature's turn flag 
 * without an action being fetched
 */
TEST(DarwinFixture, resetTurn2) {
	Species f('s');
	f.addInstruction("hop");
	Creature c(f, 0);
	c.resetTurn();
	assert(!c.moved);
}

/** 
 * Tests if the correct location is being fetched for different
 * directions
 */
TEST(DarwinFixture, locationFaced1) {
	Species f('s');
	Creature c(f, 0);
	bool out = c.getLocationFaced(pair<int, int>(1, 1)) == pair<int, int>(0, 1);
	assert(out);
}

/** 
 * Tests if the correct location is being fetched for different
 * directions
 */
TEST(DarwinFixture, locationFaced2) {
	Species f('s');
	Creature c(f, 1);
	bool out = c.getLocationFaced(pair<int, int>(1, 1)) == pair<int, int>(1, 0);
	assert(out);
}

/** 
 * Tests if the correct location is being fetched for different
 * directions
 */
TEST(DarwinFixture, locationFaced3) {
	Species f('s');
	Creature c(f, 2);
	bool out = c.getLocationFaced(pair<int, int>(1, 1)) == pair<int, int>(2, 1);
	assert(out);
}

/** 
 * Tests if the correct location is being fetched for different
 * directions
 */
TEST(DarwinFixture, locationFaced4) {
	Species f('s');
	Creature c(f, 3);
	bool out = c.getLocationFaced(pair<int, int>(1, 1)) == pair<int, int>(1, 2);
	assert(out);
}

/** 
 * Tests initializing a Species
 */
TEST(DarwinFixture, initSpecies1) {
	Species f('s');
	assert(f.identifier == 's');
}

/** 
 * Tests initializing a Species
 */
TEST(DarwinFixture, initSpecies2) {
	Species f('f');
	assert(f.identifier == 'f');
}

/** 
 * Tests adding instructions to the Species
 */
TEST(DarwinFixture, addInstruction1) {
	Species f('f');
	f.addInstruction("go 0");
	assert(f.instructionSet[0] == "go 0");
}

/** 
 * Tests adding instructions to the Species
 */
TEST(DarwinFixture, addInstruction2) {
	Species f('f');
	f.addInstruction("go 0");
	f.addInstruction("go 2");
	f.addInstruction("go 10");
	assert(f.instructionSet[2] == "go 10");
}

/** 
 * Tests adding instructions to the Species and using getInstruction() to
 * fetch
 */
TEST(DarwinFixture, addInstruction3) {
	Species f('f');
	f.addInstruction("go 0");
	assert(f.getInstruction(0) == "go 0");
}

/** 
 * Tests adding instructions to the Species and using getInstruction() to
 * fetch
 */
TEST(DarwinFixture, addInstruction4) {
	Species f('f');
	f.addInstruction("go 0");
	f.addInstruction("go 2");
	f.addInstruction("go 10");
	assert(f.getInstruction(1) == "go 2");
}