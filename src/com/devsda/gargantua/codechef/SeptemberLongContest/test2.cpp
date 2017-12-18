#include<iostream>

using namespace std;

unsigned long long choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

main() {
    /*long long count = 0;
    for(int i = 0; i < 1000000000; i += 100000000) {
        cout << i << "  " << count << endl;
        if( choose(i, i/2) >= 10000000000000000ll ) count++;
    }
    cout << "COUNT IS : " << count << endl;
    */
    cout << choose(100000000, 50000000);
    return 0;
}
