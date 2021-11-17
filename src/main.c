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

//********
//*MACROS*
//********
#define SP (REGISTERS[SP])
#define PC (REGISTERS[PC])

//***********
//*FUNCTIONS*
//***********

int fetch();
void eval(int inst);

//***********
//*VARIABLES*
//***********

static int STACK[STACK_SIZE];
static int REGISTERS[REG_SIZE]; //Set register: REGISTER[A] = value;

int *instructions;
int inst_size = 4;

bool running = true;

int main() {
	SP = -1; //Init stack pointer

	instructions = malloc(sizeof(*instructions) * inst_size);

	while(running) { //Machine execution loop
		eval(fetch()); //Automatically evaluates (decodes) each fetched instruction
		PC++; //Increments Program Counter
	}

	return 0;
}

//Funtion declaration

int fetch() {
	return instructions[PC];
}

void eval(int inst) {
	switch(inst) {
		case HLT: { //Halts program
			running = false;
			printf("HALTING EXECUTION\n");
			break;
		}
		case PSH: { //Pushes data to stack, increments SP
			STACK[++SP] = instructions[++PC];
			break;
		}
		case POP: { //Decrements SP as it removes data from STACK
			int popped = STACK[SP--]; //Decrements after popping
			printf("-> POP: %d\n", popped);
			break;
		}
		case ADD: { //Adds the two topmost values stored on the stack and stores the value again
			REGISTERS[A] = STACK[SP--]; //Pops topmost value to a
			REGISTERS[B] = STACK[SP]; //Pops next topmost value to b
			STACK[SP] = REGISTERS[B] + REGISTERS[A];
			break;
		}
		case SUB: {
			REGISTERS[A] = STACK[SP--];
			REGISTERS[B] = STACK[SP];

			STACK[SP] = REGISTERS[B] - REGISTERS[A];
			break;
		}
		case MUL: {
			REGISTERS[A] = STACK[SP--];
			REGISTERS[B] = STACK[SP];

			STACK[SP] = REGISTERS[B] * REGISTERS[A];
			break;
		}
		case DIV: {
			REGISTERS[A] = STACK[SP--];
			REGISTERS[B] = STACK[SP];

			STACK[SP] = REGISTERS[B] / REGISTERS[A];
		}
		default: {
			printf("Unknown Instruction %d\n", inst);
			break;
		}
	}
}
