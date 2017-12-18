#include<iostream>

using namespace std;

main() {
    float f1 = 0.945;
    float f2 = 0;
    int i = 0;

    while( (f1 - i) != 0) {
        f1 *= 10;
        i = f1;
    }

    cout << f1;

    return 0;
}
