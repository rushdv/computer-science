#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int values[MAX], vtop = -1;
char ops[MAX], otop = -1;

void pushValue(int x) { values[++vtop] = x; }
int popValue() { return values[vtop--]; }

void pushOp(char x) { ops[++otop] = x; }
char popOp() { return ops[otop--]; }

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
    }
    return 0;
}

int evaluate(char *tokens) {
    int i;
    for (i = 0; tokens[i] != '\0'; i++) {
        if (tokens[i] == ' ')
            continue;
        if (tokens[i] == '(') {
            pushOp(tokens[i]);
        } else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < (int)strlen(tokens) && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            pushValue(val);
            i--;
        } else if (tokens[i] == ')') {
            while (otop != -1 && ops[otop] != '(') {
                int val2 = popValue();
                int val1 = popValue();
                char op = popOp();
                pushValue(applyOp(val1, val2, op));
            }
            if (otop != -1) popOp();
        } else {
            while (otop != -1 && precedence(ops[otop]) >= precedence(tokens[i])) {
                int val2 = popValue();
                int val1 = popValue();
                char op = popOp();
                pushValue(applyOp(val1, val2, op));
            }
            pushOp(tokens[i]);
        }
    }
    while (otop != -1) {
        int val2 = popValue();
        int val1 = popValue();
        char op = popOp();
        pushValue(applyOp(val1, val2, op));
    }
    return popValue();
}

int main() {
    char exp[MAX];
    printf("Enter infix expression: ");
    if (scanf("%99s", exp) == 1) {
        printf("Result = %d\n", evaluate(exp));
    }
    return 0;
}



















