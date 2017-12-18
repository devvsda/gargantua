#include<stdio.h>

#define MAX 1000

char answer[MAX];

void swapChar(char *a, char *b) {
    char *temp = a;
    a = b;
    b = temp;
}

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

char *add2Binary(char *a, char *b) {
    int sizeA = strlen(a)-1;
    int sizeB = strlen(b)-1;
    int i;
    int carry = 0;
    if(sizeA < sizeB) {
        swapChar(a, b);
        swapInt(&sizeA, &sizeB);
    }
    i = sizeA+1;
    while(sizeB >= 0) {
        answer[i] = (char)(( (a[sizeA] - 48)^(b[sizeB] - 48)^(carry) ) + 48);
        carry = ( (a[sizeA] - 48) & (b[sizeB] - 48) )|(  (b[sizeB]-48) & (carry) )|( (carry) & (a[sizeA]-48) );
        i--;
        sizeA--;
        sizeB--;
    }

    while(sizeA >= 0) {
        answer[i] =  (char)(( (a[sizeA] - 48)^(carry) ) + 48);
        carry =  ( (carry) & (a[sizeA]-48) );
        i--;
        sizeA--;
        if(!carry) break;
    }

    while(sizeA >= 0) {
        answer[i] = a[sizeA];
        i--;
        sizeA--;
    }

    if(carry) answer[0] = '1';
    else answer[0] = '0';
    answer[strlen(a)+1] = '\0';
    return (answer[0] == '1' ? answer : answer+1);
}

main() {
    printf("%s\n", add2Binary("111", "10"));
    return 0;
}
