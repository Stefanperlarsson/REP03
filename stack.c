/*
    E20C4033 Stefan Larsson
    2021-01-22
    stack.c
*/

#include "stack.h"

static int stack[STACK_MAX];
static int i = 0;

/*
 * Function:  push 
 * --------------------
 *   stackにintを追加
 */
void push(int c){
    stack[i] = c;
    i++;
}
/*
 * Function:  pop 
 * --------------------
 *   積み重なった一番上のintと取る
 *
 *   returns: 一番上のint
 */
int pop(){ //TODO: maybe make better
    if(i == 0)
        return 0;
    
    i--;
    return stack[i];
}
