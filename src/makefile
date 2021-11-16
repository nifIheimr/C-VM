SRC_FILES = main.c  
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = clang


all: main.o

main.o: main.c
	${CC} ${SRC_FILES} ${CC_FLAGS} -o c-vm

cleanup:
	rm *.o
