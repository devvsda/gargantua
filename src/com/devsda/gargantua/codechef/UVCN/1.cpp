#include<stdio.h>

using namespace std;

int workingArray[2001];

void fillArray() {
    workingArray[1] = 1;
    for(int i = 2; i <= 2001; i++) {
        workingArray[i] = workingArray[i-1] + i;
    }
}

int binarySearch(int val, int start, int end) {
    if(start > end ) return 0;
    int mid = start + (end - start)/2;
    if(workingArray[mid] == val) return 1;
    if(val > workingArray[mid]) return binarySearch(val, mid + 1, end);
    else return binarySearch(val, start, mid-1);
}

main() {
    int T;
    int N;
    int B;
    scanf("%d", &T);
    fillArray();

    while(T--) {
        scanf("%d %d", &N, &B );
        if( binarySearch(B, 1, 2001) ) {
            printf("%d\n", (N*(N+1))/2 - 1 );
        }
        else printf("%d\n", (N*(N+1))/2 );
    }
    return 0;
}
