#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int values[MAX], vtop = -1;
char ops[MAX], otop = -1;

void pushValue(int x) { values[++vtop] = x; }
int popValue() { return values[vtop--]; }

void pushOp(char x) { ops[++otop] = x; }
char popOp() { return ops[otop--]; }

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 1;
    return 0;  
}


    return 0;
}


















