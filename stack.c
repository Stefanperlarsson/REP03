/*
    E20C4033 Stefan Larsson
    2021-01-22
    stack.c
*/

#include "stack.h"

char stack[STACK_MAX];
int c = -1;

/*
 * Function:  push 
 * --------------------
 *   stackにcharを追加
 */
void push(char c){
    stack[c++] = c;
}
/*
 * Function:  pop 
 * --------------------
 *   積み重なった一番上のcharと取る
 *
 *   returns: 一番上のchar
 */
char pop(){ //TODO: maybe make easier
    return c == -1 ? -1 : stack[c--];
}
