#include<iostream>
#include<limits.h>

using namespace std;

void findMinKSubArray(long long int *input, int *start, int *end, int n, int k) {
    long long int minm;
    long long int sum = 0;
    for(int i = 1; i <= k; i++) sum += input[i];
    minm = sum;
    *start = 1;
    *end = k;
    for(int i = 1; i <= n-k-1; i++) {
        if(sum < minm) {
            *start = i;
            *end = i + k - 1;
            minm = sum;
        }
        sum = sum - input[i] + input[i + k];
    }
}

long long int kadane(long long int *input, int start, int end) {
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

    cin >> T;

    while(T--) {
        cin >> N >> k;
        long long int input[N];
        for(int i = 0; i < N; i++) cin >> input[i];
        /*if(k <= 10) {
            long long int maxm = INT_MIN;
            long long int temp;
            for(int i = 1; i <= (N-k-1); i++) {
                temp = kadane(input, 0, i-1) + kadane(input, i+k, N-1);
                maxm = max(maxm, temp);
            }
            cout << maxm <<endl;
        }
        else {*/
            findMinKSubArray(input, &start, &end, N, k);
            //cout << start << "  " << end << endl;
            long long int maxm = kadane(input, 0, start-1) + kadane(input, end+1, N-1);
            cout << maxm << endl;
        //}
    }
    return 0;
}
