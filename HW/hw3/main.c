#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char ADD = '+';
const char SUB = '-';
const char MUL = '*';
const char DIV = '/';

int numbers[50];
int result[3];
char opCodes[10];
int numbersLength;
int opCodesLength;
bool error = false;

//3/2 + 1/4 - 1_4/5 + 3_0/1

int isOperator(char ch){
    if(ch == ADD || ch == SUB || ch == MUL || ch == DIV)
        return 1;
    return 0;
}

int isUnderscore(char ch){
    if(ch == "_")
        return 1;
    return 0;
}

void loadEquation(char* equation){
    int num = 0, numerator = 0, den = 0;
    int numbersCount = 0, opCodeCount = 0;
    bool underscore = false, afterFrac = false, space = false;

    for(int i = 0; i <= strlen(equation); i++){
        if(i == strlen(equation)){
            space = true;
            //printf("%d\n", i);
            underscore = false;
            afterFrac = false;
            numbers[numbersCount] = num;
            numbersCount++;
            numbers[numbersCount] = numerator;
            numbersCount++;
            numbers[numbersCount] = den;
            numbersCount++;
            num = 0;
            numerator = 0;
            den = 0;
        } else {
            char curChar = equation[i];
            //printf("%c\n", curChar);
            if(isdigit(curChar)){
                if(!afterFrac){
                    int digit = curChar - '0';
                    numerator = (numerator * 10) + digit;
                    //printf("%d\n", numerator);
                } else {
                    int digit = curChar - '0';
                    den = (den * 10) + digit;
                    //printf("%d\n", den);
                    if(den == 0){
                        error = true;
                        i = strlen(equation);
                    }
                }
            } else if(isOperator(curChar)){
                if(curChar == DIV && !afterFrac){
                    afterFrac = true;
                } else {
                    opCodes[opCodeCount] = curChar;
                    opCodeCount++;
                }
            } else if(isUnderscore(curChar)){
                num = numerator;
                numerator = 0;
                underscore = true;
            } else {
                //printf("Setting Numbers\n");
                if(space){
                    space = false;
                } else {
                    space = true;
                    //printf("%d\n", i);
                    underscore = false;
                    afterFrac = false;
                    numbers[numbersCount] = num;
                    numbersCount++;
                    numbers[numbersCount] = numerator;
                    numbersCount++;
                    numbers[numbersCount] = den;
                    numbersCount++;
                    num = 0;
                    numerator = 0;
                    den = 0;
                }
            }
        }
    }
    if(error){
        printf("ERROR DIVIDED BY 0");
    } else {
        numbersLength = numbersCount;
        opCodesLength = opCodeCount;
    }
}

void calculateFraction(){
    //int index = 0;
    //while(index < numbersLength){
        int leftNum, leftNumerator, leftDen, rightNum, rightNumerator, rightDen, opCodeCount = 0, numbersCount = 0;
        char opCode;
        bool afterFirst = false;
        for(numbersCount = 0; numbersCount < numbersLength; numbersCount++){
            if(!afterFirst){
                leftNum = numbers[numbersCount];
                numbersCount++;
                leftNumerator = numbers[numbersCount];
                numbersCount++;
                leftDen = numbers[numbersCount];
                numbersCount++;
                afterFirst = true;
            }
            rightNum = numbers[numbersCount];
            numbersCount++;
            rightNumerator = numbers[numbersCount];
            numbersCount++;
            rightDen = numbers[numbersCount];

            if(opCodeCount < opCodesLength){
                printf("%d opcodecount\n", opCodeCount);
                printf("%d opcodelength\n", opCodesLength);
                opCode = opCodes[opCodeCount];
                opCodeCount++;
            }


            printf("%c is the opcode\n", opCode);

            if(opCode == '+'){
                leftNumerator = (leftNumerator * rightDen) + (rightNumerator * leftDen);
                leftDen = leftDen * rightDen;
                leftNum = leftNum + rightNum;
            } else if(opCode == '-'){
                leftNumerator = (leftNumerator * rightDen) - (rightNumerator * leftDen);
                leftDen = leftDen * rightDen;
                leftNum = leftNum - rightNum;
            } else if(opCode == '*'){
                leftDen = leftDen * rightDen;
                leftNumerator = leftNumerator * rightNumerator;
                leftNum = leftNum * rightNum;
            } else if(opCode == '/'){
                int temp = leftNumerator + (leftDen * leftNum);
                leftNumerator = leftDen;
                leftDen = temp;
                leftNum = 0;
                leftNumerator = (leftNumerator * rightDen) - (rightNumerator * leftDen);
                leftDen = leftDen * rightDen;
                leftNum = leftNum - rightNum;
            } else {
                printf("%c IS NOT A CORRECT OPCODE!\n", opCode);
                break;
            }
        }
        result[0] = leftNum;
        result[1] = leftNumerator;
        result[2] = leftDen;
        //index++;
    //}
}

void reduceFrac(){
    int num, numerator, den;
    num = result[0];
    numerator = result[1];
    den = result[2];
    if(numerator > den){
        int tempNumerator = numerator;
        numerator = numerator % den;
        num = tempNumerator / den;
    }
    result[0] = num;
    result[1] = numerator;
    result[2] = den;
}

//ISSUE WITH LOADING THE EQUATION!!!!!!!
int main()
{
    char equation[200];
    printf("Enter equation: ");
    gets(equation);
    loadEquation(equation);
    if(!error){
        calculateFraction();
        reduceFrac();
    }
    for(int i = 0; i < numbersLength; i++){
        printf("%d\n", numbers[i]);
    }
    printf("OpCodes\n");
    for(int i = 0; i < opCodesLength; i++){
        printf("%c\n", opCodes[i]);
    }
    printf("%d_%d/%d\n", result[0], result[1], result[2]);
    return 0;
}
