/*
    E20C4033 Stefan Larsson
    2021-01-22
    stack.c
*/

#include "stack.h"

//debug
#include <stdio.h>
////////

stack *init(){
    stack *s = (stack *) malloc(1 * sizeof(stack));
    s->p = 0;

    return s;
}

/*
 * Function:  push 
 * --------------------
 *   stackにcharを追加
 */
void push(stack *s, char c){
    s->data[s->p] = c;
    s->p++;
}
/*
 * Function:  pop 
 * --------------------
 *   積み重なった一番上のcharと取る
 *
 *   returns: 一番上のchar
 */
char pop(stack *s){ //TODO: maybe make better
    if(s->p == 0)
        return '\0';
    
    s->p--;
    return s->data[s->p];
}
