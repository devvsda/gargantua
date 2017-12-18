#include<iostream>

using namespace std;

int makeChange( int n, int denom) {
    int nxt_denom = 0;
    switch(denom) {
        case 25:
            nxt_denom = 10;
            break;
        case 10:
            nxt_denom = 5;
            break;
        case 5:
            nxt_denom = 1;
            break;
        case 1:
            return 1;
    }
    int ways = 0;
    for(int i = 0; (i*denom) <= n; i++) {
        ways += makeChange( ((n-1)*denom), nxt_denom);
    }
    return ways;
}

main() {
    cout << makeChange(100, 25);
    return 0;
}
