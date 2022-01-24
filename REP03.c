/*
    E20C4033 Stefan Larsson
    2022-01-22
    REP03.c
*/

#include <stdio.h>
#include <ctype.h>

#include "stack.h"

#define PLUS '+'
#define MINUS '-'
#define MULTIPLICATION '*'

void main(){

    char expression[STACK_MAX];
    char *e = expression;

    printf("逆ポーランド式を入力：");
    scanf("%s", e);

    while(*e != '\0') {
        switch (*e){
            case PLUS:

                break;
            case MINUS:

                break;
            case MULTIPLICATION:

                break;
        default:
            if (isdigit(*e) != 0) {
                //push to stack etc
            } else {
                fprintf(stderr, "エラー\n");
                return ;
            }
            break;
        }
        e++;
    }
}