#include<stdio.h>

#define MAX 1000

void conversion(int val, char *output) {
    int i = 0;
    do {
        output[i++] = ( ( val % 2 ) + 48 );
        val /= 2;
    }while(val);
}

void reverse(char *output) {
    int sze = strlen(output)-1;
    int i = 0;
    while(i < sze) {
        char temp = output[i];
        output[i] = output[sze];
        output[sze] = temp;
        i++;
        sze--;
    }
}

main() {
    char temp[MAX];
    conversion(10, temp);
    reverse(temp);
    printf("%s\n", temp);
    return 0;
}
