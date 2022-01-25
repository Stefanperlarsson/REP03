/*
    E20C4033 Stefan Larsson
    2022-01-22
    REP03.c
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "stack.h"
#include "infix.h"

void main(){

    char c[STACK_MAX];
    int a, b, j = 0;
    stack *s = init();
    
    printf("Ｃ言語実習２ REP03 E20C4033 ラーション・ステファン\n");
    printf("Infixを入力（例：「(1-(2+3))」）：");
    fgets(c, STACK_MAX, stdin);
    c[strcspn(c, "\n")] = 0;

    printf("Infix: %s\n", c);
    convert(c);
    printf("Postfix(逆ポーランド記法): %s\n", c);

    while(c[j] != '\0') {
        switch (c[j]){
            case PLUS:
            case MINUS:
            case MULTIPLICATION:
                a = pop(s), b = pop(s);
                if(c[j] == PLUS) {
                    push(s, b + a);
                } else if(c[j] == MINUS) {
                    push(s, b - a);
                } else if(c[j] == MULTIPLICATION) {
                    push(s, b * a);
                }
            break;
        default:
            if (isdigit(c[j]) != 0) {
                push(s, (int) c[j] - '0');
            } else {
                fprintf(stderr, "エラー\n");
                return ;
            }
            break;
        }
        j++;
    }
    printf("答え:%d\n", pop(s));

    free(s);
}