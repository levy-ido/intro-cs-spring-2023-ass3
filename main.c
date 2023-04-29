#include <stdio.h>

int compute(int leftOperand, char operator, int rightOperand) {
    switch (operator) {
        case '*':
            return leftOperand * rightOperand;
        case '+':
            return leftOperand + rightOperand;
        case '-':
            return leftOperand - rightOperand;
        case '/':
            return leftOperand / rightOperand;
        default:
            return 0;
    }
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int parseDigit(char c) {
    return c - '0';
}

int isOperator(char c) {
    return c == '*' || c == '+' || c == '-' || c == '/';
}

int evaluate_expression() {
    char c;
    scanf("%c", &c);
    int leftOperand = 0;
    char operator = '+';
    while (c != ')' && c != '\n') {
        if (c == '(') {
            int rightOperand = evaluate_expression();
            leftOperand = compute(leftOperand, operator, rightOperand);
        }
        if (isDigit(c)) {
            int rightOperand = parseDigit(c);
            leftOperand = compute(leftOperand, operator, rightOperand);
        }
        if (isOperator(c)) {
            operator = c;
        }
        scanf("%c", &c);
    }
    return leftOperand;
}

int main() {
    printf("Enter an expression:\n");
    printf("The value is: %d", evaluate_expression());
    return 0;
}
