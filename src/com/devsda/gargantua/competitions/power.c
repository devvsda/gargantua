#include<stdio.h>

#define MAX 1000

char answer[MAX];

void power(int index) {
    if(index < 0) return "";
    answer[index+1] = '\0';
    while(index) answer[index--] = '0';
    answer[index] = '1';
}

main() {
    power(3);
    printf("%s\n", answer);
    return 0;
}
