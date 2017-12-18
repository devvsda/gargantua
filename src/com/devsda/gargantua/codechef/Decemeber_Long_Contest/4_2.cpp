#include<iostream>
#include<map>
#include<limits.h>
#include<algorithm>

#define MAX 100005

using namespace std;

long long int input[MAX];
long long int leftMax[MAX];
long long int rightMax[MAX];

void calculateLeftMaxSubArray(int N) {
    long long int maxSoFar = input[0];
    long long int maxNow = input[0];
    int i = 1;

    leftMax[0] = maxSoFar;

    for(; i < N; i++) {
        maxNow = max(input[i], input[i] + maxNow);
        if(maxSoFar < maxNow) maxSoFar = maxNow;
        leftMax[i] = maxSoFar;
    }
}

void calculateRightMAxSubArray(int N) {
    long long int maxSoFar = input[N-1];
    long long int maxCur = input[N-1];
    int i = N-2;

    rightMax[N-1] = maxSoFar;

    for(; i >= 0; i--) {
        maxCur = max( input[i], maxCur + input[i] );
        if( maxCur > maxSoFar ) maxSoFar = maxCur;
        rightMax[i] = maxSoFar;
    }
}

main() {
    int N;
    int k;
    int T;

    cin >> T;

    while(T--) {
        long long int answer = INT_MIN, temp;
        map<long long int, long long int> m;
        map<long long int, long long int> :: iterator it;
        cin >> N >> k;
        for(int i = 0; i < N; i++) cin >> input[i];
        calculateLeftMaxSubArray(N);
        calculateRightMAxSubArray(N);

        for(int i = k+1; i < N; i++) {
            if(!m.count(rightMax[i])) m.insert(pair<long long int, long long int>(rightMax[i], 1));
            else m.find(rightMax[i])->second++;
        }

        for(int i = 0; i < (N-k-1); i++) {
            it = m.end();
            --it;
            temp = leftMax[i] + (it->first);
            if(answer < temp) answer = temp;
            if( it->second == 1 ) m.erase(it);
            else (it->second)--;
        }

        cout << answer << endl;
    }

    return 0;
}
