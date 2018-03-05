#include <stdio.h>
int main(void)
{
    prime();
    return 0;
}

void prime(void)
{
    int n, i, m = 0, flag = 0;
    printf("Enter the number:");
    scanf("%d", &n);
    printf("All prime numbers less than %d:\n", n);
    m = n / 2;
    for(int j = n; j > 0; j--){
        for(i = 2; i <= m; i++)
        {
            if(j % i==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("%d\n");
    }
}

void asciiCodes(){
    char ch, chars[200];
    int ascii, count = 0;
    printf("Enter characters: ");
    scanf("%c", &ch);
    while(ch != '#'){
        chars[count] = ch;
        printf("thanks");
        scanf("%c", &ch);
    }
    for(int i = 0; i < count; i++){
        printf("in for loop");
        if((i + 1) % 8 != 0){
            ascii = chars[i];
            printf("%c ascii code is %d", chars[i], ascii);
        } else {
            printf("\n");
            ascii = chars[i];
            printf("%c ascii code is %d", chars[i], ascii);
        }
    }
}
