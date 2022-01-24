/*
    E20C4033 Stefan Larsson
    2021-01-22
    infix.c
*/

#include <stdio.h>

#include "stack.h"
#include "infix.h"


//     (1-(2+3))
//     (a+(b*c)/(d-e))
void convert(char *i){

    char c;
    stack *postfix = init();
    stack *operators = init();
    
    while(*i != '\0') {
        switch(*i) {
            case PLUS:
            case MINUS:
            case MULTIPLICATION:
            case PARANTHESIS_OPEN:
                push(operators, *i);
                break;
            case PARANTHESIS_CLOSE:
                c = pop(operators);
                while(c != PARANTHESIS_OPEN) {
                    push(postfix, c);
                    c = pop(operators);
                }
                break;
            default:
                push(postfix, *i);
                break;
        }
        i++;
    }

    char r[postfix->p];
    r[postfix->p] = '\0';
    for(int j = postfix->p - 1; j != -1; j--) {
        r[j] = pop(postfix);
    }
    printf("%s\n", r);
    
    free(operators);
    free(postfix);
}
