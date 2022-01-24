/*
    E20C4033 Stefan Larsson
    2021-01-22
    stack.h
*/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>

#define STACK_MAX 128

struct stack{
	char data[STACK_MAX];
	int p;
};
typedef struct stack stack;

stack *init();
void push(stack *, char); //comment
char pop(stack *); //comment
void reverse(stack *, char *r); //comment

#endif
