#ifndef	__INSTRUCTIONS_H
#define __INSTRUCTIONS_H

//Define instructions for our instruction set
// @TODO: Implement branching instructons such as JMP
// @TODO: Implement conditional instructions such as CMP
//		-- Flag register is requierd for this to work
// @TODO: Implement conditional branching such as BRa

typedef enum {
	PSH, 	//Push value to stack
	ADD, 	//Pops two values from the top of the stack, adds them together and stores the value in the stack again
	POP, 	//Pops the topmost value from the stack and prints it out
	SET, 	//Sets specified register to zero
	HLT		//Halts proram
} InstSet;

#endif