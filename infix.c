/*
    E20C4033 Stefan Larsson
    2021-01-22
    infix.c
*/

#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "infix.h"

/*
 * Function:  convert 
 * --------------------
 *   InfixからPostfixに変更
 *
 *   char *i: infix記法
 */
void convert(char *i){

    int j = 0;
    char c;
    stack *postfix = init();
    stack *operators = init();
    
    while(i[j] != '\0') {
        switch(i[j]) {
            case PLUS:
            case MINUS:
            case MULTIPLICATION:
            case PARANTHESIS_OPEN:
                push(operators, i[j]);
                break;
            case PARANTHESIS_CLOSE:
                c = pop(operators);
                while(c != PARANTHESIS_OPEN) {
                    push(postfix, c);
                    c = pop(operators);
                }
                break;
            default:
                push(postfix, i[j]);
                break;
        }
        j++;
    }

    i[postfix->p] = '\0';
    c = pop(postfix);
    while(c != '\0'){
        i[postfix->p] = c;
        c = pop(postfix);
    }        

    free(operators);
    free(postfix);
}
