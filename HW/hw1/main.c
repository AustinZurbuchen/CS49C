#include <stdio.h>
int main()
{
    printLine();
    printRow1();
    printLine();
    printRow2();
    printLine();
    printRow3();
    printLine();
}

int printX(){
    printf("  X   ");
}

int printO(){
    printf("  O   ");
}

int printLine(){
    printf("+------+------+------+\n");
}

int printRow1(){
    printf("|");
    printO();
    printf("|");
    printO();
    printf("|");
    printX();
    printf("|\n");
}

int printRow2(){
    printf("|");
    printO();
    printf("|");
    printX();
    printf("|");
    printX();
    printf("|\n");
}

int printRow3(){
    printf("|");
    printX();
    printf("|");
    printO();
    printf("|");
    printO();
    printf("|\n");
}

/*
 * +------+-----+------+
 * |  X   |  O  |  X   |
 * +------+-----+------+
 * |  O   |  X  |  O   |
 * +------+-----+------+
 * |  O   |  X  |  O   |
 * +------+-----+------+
*/
