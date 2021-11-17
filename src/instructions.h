#ifndef	__INSTRUCTIONS_H
#define __INSTRUCTIONS_H

//Define instructions for our instruction set
// @TODO: Implement branching instructons such as JMP
// @TODO: Implement conditional instructions such as CMP
//		- Flag register is required for this to work
// @TODO: Implement conditional branching such as BRa

typedef enum {
	PSH, 	//Push value to stack
	ADD, 	//Add
	SUB, 	//Subtract
	MUL, 	//Multiply
	DIV,	//Divide
	POP, 	//Pop value from stack
	SET, 	//Sets specified register to zero
	HLT	//Halts proram
} InstSet;

#endif
