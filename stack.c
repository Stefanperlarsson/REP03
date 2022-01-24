/*
    E20C4033 Stefan Larsson
    2021-01-22
    stack.c
*/

#include "stack.h"

/*
 * Function:  init 
 * --------------------
 *   stackを作成
 *
 *   returns: 作成されたstack
 */
stack *init(){
    stack *s = (stack *) malloc(1 * sizeof(stack));
    s->p = 0;

    return s;
}

/*
 * Function:  push 
 * --------------------
 *   stackにcharを追加
 *
 *  stack *s: stackのポインター
 *  char c: 追加したいデータ
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
 *   stack *s: stackのポインター
 *
 *   returns: 一番上のchar
 */
char pop(stack *s){
    if(s->p == 0)
        return '\0';
    
    s->p--;
    return s->data[s->p];
}
