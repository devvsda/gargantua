#include<stdio.h>

int preprocessing[999999999];

int getGCD(int num, int den) {
    if(den == 0) return num;
    return getGCD(den , num % den);
}


main() {
    int T;
    int N;
    int countNumerator = 0;
    int countDenominator;
    int gcd;
    int i, j;

    scanf("%d", &T);

    for(i = 0; i < T; i++) {
        scanf("%d", &N);
        if(N == 1) {
            printf("1/1\n");
            continue;
        }

        countNumerator = N;
        for(j = 1; j <= (N/2); j++) {
            countNumerator += ((N/j)-1);
        }
        countDenominator = N*N;
        gcd = getGCD(countDenominator, countNumerator);
        printf("%d/%d\n", (countNumerator/gcd), (countDenominator/gcd));// (countNumerator/gcd) << "/" << (countDenominator/gcd) << endl;
    }
    return 0;
}
