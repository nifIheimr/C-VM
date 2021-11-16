#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "program.h"
#include "instructions.h"
#include "registers.h"

//We'll implement a machinefg with the following set of registers: A, B, D, X and Y;
//all of them being general purpose registers (subject to change, may speciallize X and Y for address storing and D as a sum of A and B)

//Any programs will be a read-only sequence of assembly instructions. We'll create a stack based virtual machine

/*
	To create a virtual machine we must simulate the instruction cycle:
	- Fetch
	- Decode
	- Execute
*/

//***********
//*CONSTANTS*
//***********

#define STACK_SIZE 256

//***********
//*FUNCTIONS*
//***********

int fetch();
void eval(int inst);

//***********
//*VARIABLES*
//***********

//We'll use an index instead of an actual pointer
int PC = 0; //Program counter
int SP = -1; //Stack pointer

int STACK[STACK_SIZE];
int REGISTER[NUM_OF_REGISTERS]; //Set register: REGISTER[A] = value;

bool running = true;

int main() {

	while(running) { //Machine execution loop
		eval(fetch());
		PC++; //Increments Program Counter
	}

	return 0;
}

//Funtion declaration

int fetch() {
	return program[PC];
}

void eval(int inst) {
	switch(inst) {
		case HLT: { //Halts program
			running = false;
			break;
		}
		case PSH: { //Pushes data to stack, increments SP
			SP++;
			STACK[SP] = program[++PC];
			break;
		}
		case POP: { //Decrements SP as it removes data from STACK
			int popped = STACK[SP--]; //Decrements after popping
			printf("-> POP: %d\n", popped);
			break;
		}
		case ADD: { //Adds the two topmost values stored on the stack and stores the value again
			int A = STACK[SP--]; //Pops topmost value to a
			int B = STACK[SP--]; //Pops next topmost value to b

			SP++;
			STACK[SP] = A + B;
		}
	}
}