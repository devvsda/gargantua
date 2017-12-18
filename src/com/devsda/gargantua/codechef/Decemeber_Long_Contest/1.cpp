#include<iostream>

using namespace std;

main() {
    int T;
    long long int N;
    long long int val;

    cin >> T;

    while(T--) {
        cin >> N;

        for(int j = 0; j < N; j++) cin >> val;

        if(N&1) cout << ( ((N-1)/2)*(N) ) << endl;
        else cout << ( (N/2)*(N-1) ) << endl;
    }
    return 0;
}
