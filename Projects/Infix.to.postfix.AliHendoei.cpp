//Ali Hendoei 4011406159
#include <iostream>
#include <string>
#include <conio.h>
#define m 21
#define n 10

using namespace std;

struct stack {
    int top;
    char items[m];
    float items_1[m];
};

void push(stack* s, char);
void pop(stack* s, char*);
int empty(stack* s);
void convert(char[], char[]);
int pred(char, char);
float evaluate(char[]);
void push1(stack* s, float);
void pop1(stack* s, float*);

int main() {
    char infix[m], postfix[m];
    int i;
    cout << "Enter an infix expression : ";
    cin >> infix;
    convert(infix, postfix);
    cout << "postfix expression is : ";
    for (i = 0; postfix[i] != '\0'; i++) {
        cout << postfix[i];
    }
    cout << "\nEvaluation of expression is : " << evaluate(postfix);
    return 0;
}

void convert(char infix[], char postfix[]) {
    char symbol, topsymbol;
    int underflow, i, j = 0;
    stack s;
    s.top = -1;
    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        if (isalpha(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(&s, symbol);
        }
        else if (symbol == ')') {
            pop(&s, &topsymbol);
            while (topsymbol != '(') {
                postfix[j++] = topsymbol;
                pop(&s, &topsymbol);
            }
        }
        else {
            while (!empty(&s) && pred(s.items[s.top], symbol)) {
                pop(&s, &topsymbol);
                postfix[j++] = topsymbol;
            }
            push(&s, symbol);
        }
    }
    while (!empty(&s)) {
        pop(&s, &topsymbol);
        postfix[j++] = topsymbol;
    }
    postfix[j] = '\0';
}

int pred(char op1, char op2) {
    if (op1 == '(' || op2 == '(') {
        return 0;
    }
    if ((op2 == '*' || op2 == '/') && (op1 == '+' || op1 == '-')) {
        return 0;
    }
    else {
        return 1;
    }
}

float evaluate(char postfix[]) {
    float value, operand_1, operand_2;
    stack s;
    s.top = -1;
    for (int i = 0; postfix[i]; i++) {
        if (isalpha(postfix[i])) {
            cout << "Enter value for operand " << postfix[i] << " : ";
            cin >> value;
            push1(&s, value);
        }
        else {
            pop1(&s, &operand_2);
            pop1(&s, &operand_1);
            switch (postfix[i]) {
            case '+':
                value = operand_1 + operand_2;
                break;
            case '-':
                value = operand_1 - operand_2;
                break;
            case '*':
                value = operand_1 * operand_2;
                break;
            case '/':
                value = operand_1 / operand_2;
                break;
            }
            push1(&s, value);
        }
    }
    pop1(&s, &value);
    return value;
}

void push(stack* s, char x) {
    s->items[++(s->top)] = x;
}

void pop(stack* s, char* x) {
    *x = s->items[(s->top)--];
}

int empty(stack* s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push1(stack* s, float x) {
    s->items_1[++(s->top)] = x;
}

void pop1(stack* s, float* x) {
    *x = s->items_1[(s->top)--];
}