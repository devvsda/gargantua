#include<stdio.h>
#include<string.h>

#define MAX 1000

char answer[MAX];

void power(int index, char *output) {
    if(index < 0) return "";
    output[index+1] = '\0';
    while(index) output[index--] = '0';
    output[index] = '1';
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

void convertInt2Binary(int val, char *output) {
    int i = 0;
    do {
        output[i++] = ( ( val % 2 ) + 48 );
        val /= 2;
    }while(val);
    output[i] = '\0';
    reverse(output);
}

main() {
    char input[MAX];
    char output[MAX];
    char temp1[MAX];
    char temp2[MAX];
    int sze, i;
    scanf("%s", input);
    sze = strlen(input);

    // Handle bits from 1 to (N-1), and store in output.
    power( (sze-1), temp1 );
    convertInt2Binary( (sze-1),  temp2 );
    subtract(temp1, temp2, output);

    // Now move to exactly (N) bits.
    for(i = 1; i < sze; i++){
        if(inputp[i] == '1') {
            power( (sze-i+1), temp1 );
            power( (sze-i-1), temp2 );
            subtract(temp1, temp2, temp1);
            add2Binary(output, temp1, output);
        }
    }

    printf("\n%s\n%s\n", temp1, temp2);
    return 0;
}
