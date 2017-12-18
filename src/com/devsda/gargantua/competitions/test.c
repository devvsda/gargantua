#include<stdio.h>
#include<string.h>
#include<time.h>

char *third(char *input) {
    return input;
}

char *second(char *input) {
    return third(input);
}

char *first(char *input) {
    return second(input);
}

main() {
    char input[100];
    clock_t begin, end;
    scanf("%s", input);
    begin = clock();
    printf( "%s", first(input));
    end = clock();
    printf("\nTime consumed is : %g\n", (double)(end-begin)/CLOCKS_PER_SEC);
    return 0;
}
