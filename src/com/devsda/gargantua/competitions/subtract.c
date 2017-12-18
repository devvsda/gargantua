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

void add2Binary(char *a, char *b) {
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
    //return (answer[0] == '1' ? answer : answer+1);
}

char *subtract(char *a, char *b) {
    // Make b as equal to a (size)
    int diff = strlen(a) - strlen(b);
    char newB[strlen(a)+1];
    int i = 0;
    int j = 0;
    while(diff--) newB[i++] = '0';
    while(j < strlen(b)) newB[i++] = b[j++];
    newB[i] = '\0';
    //printf("\nnewB : %s\n", newB);

    // 2's complement of newB
    i = 0;
    while(newB[i] != '\0') {
        if(newB[i] == '1') newB[i] = '0';
        else newB[i] = '1';
        i++;
    }
    i--;
    while(newB[i] == '1') {
        newB[i] = '0';
        i--;
    }
    newB[i] = '1';

    //printf("2 Complement : %s\n", newB);

    // addition of a and newB
    add2Binary(a, newB);

    //printf("\nAnswer : %s\n", answer);

    i = 1;
    while(answer[i] == '0') {i++;}
    return (answer+i);
}

main() {
    char *ans = subtract("1100", "1000");
    printf("%s\n", ans);
    return 0;
}
