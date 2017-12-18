#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 10000
double a[MAX];
double b[MAX];

int main() {
    //freopen("D-large.in", "r", stdin);
    //freopen("D-large.out", "w", stdout);

	int T, N;

	cin >> T;

    for( int t = 1; t < (T+1); t++ ) {

		cin >> N;

		int flag = 1, cnt1 = 0, cnt2 = 0;

		for(int i = 0; i < N; i++) cin >> a[i];
		for(int i = 0; i < N; i++) cin >> b[i];

		sort( a, a+N );
		sort( b, b+N );

		for( int i = N - 1, j = N-1; j >= 0; ) {
			if( a[i] < b[j] ) j--;
			else {
				j--; i--; cnt1++;
			}
		}

		for( int i = N-1, j = N-1; i >= 0; i-- ) {
			if( b[j] > a[i] ) {
				j--; cnt2++;
			}
		}

        cout << "Case #" << t << ": " << cnt1 << " " << N-cnt2 << endl;
	}
	return 0;
}
