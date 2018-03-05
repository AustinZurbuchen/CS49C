#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char ADD = '+';
const char SUB = '-';
const char MUL = '*';
const char DIV = '/';
const char MOD = '%';

int main()
{
    char equation[200];
    printf("Enter equation: ");
    gets(equation);
    //printf(equation);
    int result = fractionalCalculator(equation);
    printf(result);
    return 0;
}

int gcd(int a, int b){
    int temp;
    while(b > 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int isOperator(char ch){
    if(ch == ADD || ch == SUB || ch == MUL || ch == DIV || ch == MOD)
        return 1;
    return 0;
}

int calculate(int a, char opCode, int b){
    if(opCode == ADD){
        return a + b;
    } else if(opCode == SUB){
        return a - b;
    } else if(opCode == MUL){
        return a * b;
    } else if(opCode == DIV){
        return a / b;
    } else {
        return a % b;
    }
}

int fractionalCalculator(char* equation){
    printf(equation);
    int eqLen = strlen(equation);
    int curIndex = 0;
    bool afterOp = false;
    bool afterSpace = false;
    int leftNum, rightNum, curNum;
    char opCode;
    while(curIndex < eqLen){
        char curChar = equation[curIndex++];
        //everything else
        if(isdigit(curChar)){
            curNum = curNum * 10 + (curChar - '0');
        }
        if(isOperator(curChar)){
            opCode = curChar;
            afterOp = true;
        }
        if(isspace(curChar)){
            if(afterOp && afterSpace){
                rightNum = curNum;
                curNum = 0;
                leftNum = calculate(leftNum, opCode, rightNum);
                rightNum = 0;
                afterOp = false;
                afterSpace = false;
            }
            if(afterOp){
                afterSpace = true;
            } else {
                if(curNum != 0){
                    leftNum = curNum;
                    curNum = 0;
                }
            }
        }
    }
    return leftNum;
}
