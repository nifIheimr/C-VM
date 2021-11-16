#ifndef __REGISTERS_H
#define __REGISTERS_H

// @TODO: Add PC and SP registers to make branching possible.
// @

typedef enum {
	A, // = 0 by default
	B,
	D,
	X,
	Y,
	NUM_OF_REGISTERS //Will automatically be equal to the total number of registers present in our machine
} Registers;


#endif