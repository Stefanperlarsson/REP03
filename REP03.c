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
    int a, b = 0;

    printf("逆ポーランド式を入力：");
    scanf("%s", e);

    while(*e != '\0') {
        switch (*e){
            case PLUS:
            case MINUS:
            case MULTIPLICATION:
                a = pop(), b = pop();
                if(*e == PLUS) {
                    printf("%d+%d\n", b, a);
                    push(b + a);
                } else if(*e == MINUS) {
                    printf("%d-%d\n", b, a);
                    push(b - a);
                } else if(*e == MULTIPLICATION) {
                    printf("%d*%d\n", b, a);
                    push(b * a);
                }
            break;
        default:
            if (isdigit(*e) != 0) {
                push((int) *e - '0');
            } else {
                fprintf(stderr, "エラー\n");
                return ;
            }
            break;
        }
        e++;
    }

    printf("答え:%d\n", pop());
}