#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

unsigned long long int combinations[65];

unsigned long long int choose(int n) {
    unsigned long long int answer = pow(2, (double)n);
    cout << answer << endl;
    answer = (answer)*( sqrt((2)/(3.14*n)) );
    return answer;
}

/*unsigned long long choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}*/

main() {


    return 0;
}
