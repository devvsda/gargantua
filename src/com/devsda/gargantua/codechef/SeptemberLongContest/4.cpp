#include<iostream>
#include<bitset>

using namespace std;

bitset<100000003> bs;

int getGCD(int num, int den) {
    if(den == 0) return num;
    return getGCD(den , num % den);
}

void isPrime() {
    bs.set();
    for(long long i = 2; i < 500000005LL; i++) {
        if(bs[i] == 0) continue;
        long long j = i*2;
        while(j <= 1000000001LL) {
            bs.set(j, 0);
            j += i;
        }
    }
}

//int arr[500000002];

main() {
    //freopen ( "input.txt", "r", stdin );
    //cout << bs;
    isPrime();
    //for(int i = 1; i < 20; i++) cout << bs[i] << " " ;
    int T;
    int N;
    int countNumerator = 0;
    int countDenominator;
    int gcd;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N;
        if(N == 1) {
            cout << "1/1\n";
            continue;
        }
        countNumerator = N;
        for(int i = 1; i <= (N/2); i++) {
            countNumerator += ((N/i)-1);
        }
        countDenominator = N*N;
        gcd = getGCD(countDenominator, countNumerator);
        cout << (countNumerator/gcd) << "/" << (countDenominator/gcd) << endl;
    }
    return 0;
}
