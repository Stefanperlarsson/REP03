/*
    E20C4033 Stefan Larsson
    2021-01-22
    stack.h
*/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>

#define STACK_MAX 128 //stackのサイズ

struct stack{
	char data[STACK_MAX]; //stackのデータ
	int p; //stackの位置
};
typedef struct stack stack;

stack *init(); //stack作成
void push(stack *, char); //stackに追加
char pop(stack *); //stackから読み取る

#endif
