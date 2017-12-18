#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

#define MAX 1001

long long int input[MAX];
char oprtrs[MAX];
int indx[MAX];

void finalInput() {
    int sze = strlen(oprtrs);
    int minm = 0;
    int maxm = sze-1;
    int i = 0;
    while(i < sze) {
        while( (i < sze) && (oprtrs[i] != 'R') ) { indx[i++] = minm++; }
        if(i < sze) indx[i++] = maxm--;
        while( (i < sze) && (oprtrs[i] != 'R') ) { indx[i++] = maxm--; }
        if( i < sze ) indx[i++] = minm++;
    }
}

main() {
    int T;
    int N;
    long long int A, B, C;
    int i, j;
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        for(i = 0; i < N; i++) scanf("%lld", &input[i]);
        scanf("%lld %lld %lld", &A, &B, &C);
        scanf("%s", oprtrs);
        finalInput();
        j = 0;
        for(i = 0; i < N; i++) {
            for(int k = 0; k <= i; k++) {
                if( oprtrs[k] == 'A' ) input[ indx[i] ] = ( (input[ indx[i] ]%C) + (A%C) )%C;
                else if( oprtrs[k] == 'M' ) {
                    if(C <= 1000000000L ) input[ indx[i] ] = ( (input[ indx[i] ]%C)*(B%C) )%C;
                    else if( input[ indx[i] ] > 1000000000L && B > 1000000000L ) {
                        if(C >= B) input[ indx[i] ] = ( ((C - input[ indx[i] ])%C) *((C-B)%C))%C;
                        else input[ indx[i] ] = ( ((C - input[ indx[i] ])%C)*(B%C) )%C;
                    }
                    else if(input[ indx[i] ] > 1000000000L) {
                        input[ indx[i] ] = (((C - input[ indx[i] ])%C)*(B%C) )%C;
                    }
                    else if( B > 1000000000L ){
                        if(C >= B) input[ indx[i] ] = ( (input[ indx[i] ]%C)*((C-B)%C) )%C;
                        else input[ indx[i] ] = ( (input[ indx[i] ]%C)*(B%C) )%C;
                    }
                    else input[ indx[i] ] = ( (input[ indx[i] ]%C)*(B%C) )%C;
                }
            }
            printf( "%lld ", (input[ indx[i] ]%C) );
        }
        printf("\n");
    }
    return 0;
}
