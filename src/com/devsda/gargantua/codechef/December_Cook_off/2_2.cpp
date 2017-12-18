#include<iostream>

using namespace std;

int lft[100000];
int rght[100000];
char answer[100000000];

main() {
    int T;
    int N;

    cin >> T;

    while( T-- ) {
        long long int k = 0;
        cin >> N;
        for(int i = 0; i < N; i++) { cin >> lft[i] >> rght[i]; }
        for(int i = 0; i < N-1; i++) {
            while( lft[i] != lft[i+1] || rght[i] != rght[i+1] ) {
                if( ( (lft[i] + 1) <= lft[i+1] ) && ( (lft[i] + 1) < rght[i] ) ) {
                    answer[k++] = 'L';
                    answer[k++] = '+';
                    lft[i]++;
                }
                else if( ( (lft[i] - 1) >= lft[i+1] ) && ( (lft[i] - 1) < rght[i] ) ) {
                    answer[k++] = 'L';
                    answer[k++] = '-';
                    lft[i]--;
                }
                else if( ( (rght[i] + 1) <= rght[i+1] ) && ( lft[i] < (rght[i] + 1) ) ) {
                    answer[k++] = 'R';
                    answer[k++] = '+';
                    rght[i]++;
                }
                else if( ( ( rght[i] - 1 ) >= rght[i+1] ) && ( lft[i] < ( rght[i] - 1 ) ) ) {
                    answer[k++] = 'R';
                    answer[k++] = '-';
                    rght[i]--;
                }
            }
        }
        answer[k] = '\0';
        cout << (k >> 1) << endl << answer << endl;
    }
    return 0;
}
