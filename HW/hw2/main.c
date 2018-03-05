#include <stdio.h>

#define H 176
#define TL 245
#define TR 198
#define V 15
#define S '.'
#define BL 30
#define BR 125

void printBox() {
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H,H,BR,BL,H,H,H);
    printf( "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S,S,V,V,S,S,S);
}

int main()
{
    printBox();
}
