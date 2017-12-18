#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int arr[1000000];
vector< vector<int> > v(1000001);

main() {
    int N, K;
    int minTime = INT_MAX;
    int anotherApple;
    int sze;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        v[arr[i]].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        if( (K - arr[i]) <= 0 ) continue;
        anotherApple = K - arr[i];
        if(arr[i] == anotherApple) continue;
        sze = v[anotherApple].size();
        if( sze == 0) continue;
        if(sze == 1) {
            minTime = min( minTime, max( min(i+1, N-i), min( v[anotherApple][0] + 1, N - v[anotherApple][0] ) ) );
        }
        else {
            minTime = min( minTime, max( min(i+1, N-i), min( v[anotherApple][0] + 1, N - v[anotherApple].back() ) ) );
        }
    }

    cout << ( (minTime == INT_MAX) ? -1 : minTime ) << endl;
    return 0;
}
