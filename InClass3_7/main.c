#include <stdio.h>
#include <stdlib.h>

#define STATE_TAGOPEN_BEGIN 1
#define STATE_TAGOPEN_MID 2
#define STATE_TAGOPEN_END 3
#define STATE_TAGCLOSE_BEGIN 11
#define STATE_TAGCLOSE_SLASH 12
#define STATE_TAGCLOSE_END 13
#define STATE_VALUE 21
#define STATE_UNKNOWN 22

#define XML_OPEN '<'
#define XML_CLOSE '>'
#define XML_SLASH '/'

int main()
{
    fileCopy("in.txt", "out1.txt", "a");
    //charCopy();
}

void charCopy(){
    char ch;
    while((ch = getchar()) != EOF){
        putchar(ch);
    }
}

void fileCopy(const char* inFile, const char* outFile, const char* mode){
    FILE * fp1 = fopen(inFile, "r");
    FILE * fp2 = fopen(outFile, mode);
    int ch;
    while((ch = fgetc(fp1)) != EOF){
        fputc(ch, fp2);
    }
}

void xml2Json(const char* inFile, const char* outFile, const char* mode){
    FILE * fp1 = fopen(inFile, "r");
    //FILE * fp2 = fopen(outFile, mode);
    int ch, state, keyLen, valLen, valLenConfirm, valCount;
    char val[200], key;
    while((ch = fgetc(fp1)) != EOF){
        if(state == STATE_UNKNOWN && ch == XML_OPEN){
            state = STATE_TAGOPEN_BEGIN;
            keyLen = 0;
            valLen = 0;
            continue;
        }
        if(state == STATE_TAGOPEN_END || state == STATE_VALUE){
            if(ch != XML_OPEN){
                state = STATE_VALUE;
                val[valLen++] = ch;
                continue;
            } else {
                state = STATE_TAGCLOSE_BEGIN;
                val[valLen] = 0;
                valLenConfirm = valLen;
                valLen = 0;
                if(valCount++ > 0){
                    putchar(',');
                }
                printf("\"%s\":\"%s\"", key, val);
                continue;
            }
        }
    }
}
