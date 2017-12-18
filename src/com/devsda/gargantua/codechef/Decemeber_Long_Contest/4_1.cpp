//#include<iostream>
#include<limits.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>

#define MAX 100005

using namespace std;

long long int input[MAX];

void findMinKSubArray(int *start, int *end, int n, int k) {
    long long int minm;
    long long int sum = 0;
    for(int i = 1; i <= k; i++) sum += input[i];
    minm = sum;
    *start = 1;
    *end = k-1;
    for(int i = 1; i <= n-k-1; i++) {
        if(sum < minm) {
            *start = i;
            *end = i + k - 1;
            minm = sum;
        }
        sum = sum - input[i] + input[i + k];
    }
}

long long int kadane(int start, int end) {
    long long int maxSoFar = INT_MIN;
    long long int maxNow = 0;

    for(int i = start; i <= end; i++ ) {
        maxNow += input[i];
        if(maxSoFar < maxNow) maxSoFar = maxNow;
        if(maxNow < 0) maxNow = 0;
    }
    return maxSoFar;
}

main() {
    int T;
    int start, end;
    int N, k;

    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &N, &k);
        for(int i = 0; i < N; i++) scanf("%lld", &input[i]);
        //if(k == 0) {
            long long int maxm = INT_MIN;
            long long int temp;
            for(int i = 1; i <= (N-k-1); i++) {
                temp = kadane(0, i-1) + kadane(i+k, N-1);
                maxm = max(maxm, temp);
            }
            printf("%lld\n", maxm);
        /*}
        else {
            findMinKSubArray(input, &start, &end, N, k);
            //cout << start << "  " << end << endl;
            cout << kadane(input, 0, start-1) + kadane(input, end+1, N-1) << endl;
        }*/
    }
    return 0;
}
