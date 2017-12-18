#include<iostream>

using namespace std;

int gcd(int a, int b) {
    if(a < b) gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

main() {
    cout << gcd(105, 220);
    return 0;
}
