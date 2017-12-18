#include<stdio.h>
#include<string.h>

#define MAX 1005

using namespace std;

char operation[MAX][MAX];
unsigned long long int input[MAX];
char oprtrs[MAX];

void reverse(int start, int end) {
    unsigned long long int temp;
    while(start < end) {
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}

void fillBlock(int index, int start, int end, char oprtr) {
    for( int i = start; i <= end; i++ ) {
        operation[index][i] = oprtr;
    }
}
main() {
    int T;
    int N;
    unsigned long long int A, B, C;
    int i, j;
    scanf("%d", &T);

    while(T--) {
        for(i = 0; i < MAX; i++) for(j = 0; j < MAX; j++) operation[i][j] = 'N';
        scanf("%d", &N);
        for(i = 0; i < N; i++) scanf("%llu", &input[i]);
        scanf("%llu %llu %llu", &A, &B, &C);
        scanf("%s", oprtrs);
        j = 0;
        for(i = 0; i < N; i++) {
            if(oprtrs[i] == 'R') reverse(i, N-1);
            else if(oprtrs[i] == 'A') { fillBlock(j, i, N-1, 'A'); j++; }
            else { fillBlock(j, i, N-1, 'M'); j++; }
        }

        for(i = 0; i < N; i++) {
            for(int k = 0; k < j; k++) {
                if( operation[k][i] == 'A' ) input[i] = ( (input[i]%C) + (A%C) )%C;
                else if( operation[k][i] == 'M' ) input[i] = ( (input[i]%C)*(B%C) )%C;
                printf("\nINPUT VALUE :- %llu\n", input[i]);
            }
            printf( "%llu ", (input[i]%C) );
        }
        printf("\n");
    }
    return 0;
}
