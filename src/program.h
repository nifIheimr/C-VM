#ifndef __PROGRAM_H
#define __PROGRAM_H

#include "instructions.h"

const int program[] = {
	PSH, 5,
	PSH, 5,
	ADD,
	POP,
	SET,
	PSH, 10,
	PSH, 10,
	ADD,
	POP,
	HLT
};

#endif 