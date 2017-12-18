#include<stdio.h>

long long getGCD(long long num, long long den) {
    if(den == 0) return num;
    return getGCD(den , num % den);
}



main() {
    //freopen ( "input.txt", "r", stdin );
    long long T;
    long long N;
    long long countNumerator = 0;
    long long countDenominator;
    long long gcd;
    long long i, j;

    scanf("%lld", &T);

    for(i = 0; i < T; i++) {
        scanf("%lld", &N);
        if(N == 1) {
            printf("1/1\n");
            continue;
        }

        countNumerator = 0;
        for(j = 1; j <= sqrt(N); j++) {
            countNumerator += (N/j);
        }
        j--;
        countNumerator = countNumerator*2 - j*j;
        countDenominator = N*N;
        gcd = getGCD(countDenominator, countNumerator);
        printf("%lld/%lld\n", (countNumerator/gcd), (countDenominator/gcd));
    }
    return 0;
}
