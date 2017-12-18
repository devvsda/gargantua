#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 1000000

long long int states[MAX];
long long int strengthFrequency[MAX];

main() {
    int T;
    int N;
    int iter;
    long long int a, b, c, d;
    long long int currentStrength;
    long long int captain[2];

    scanf("%d", &T);

    while(T--) {

        scanf("%d", &N);
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        for(int i = 0; i < MAX; i++) states[i] = -1;
        memset( strengthFrequency, 0, sizeof(strengthFrequency) );
        captain[0] = captain[1] = 0;

        currentStrength = d;
        strengthFrequency[currentStrength]++;

        iter = N-1;

        while(iter--) {
            if( states[currentStrength] == -1) {
                states[currentStrength] = ( currentStrength * ( a * currentStrength + b ) + c )%MAX;
            }
            strengthFrequency[states[currentStrength]]++;
            currentStrength = states[currentStrength];
        }

        iter = 0;

        for(int i = MAX-1; i >= 0; i--) {
            if( !( ( strengthFrequency[i] == 0 ) || (( strengthFrequency[i] % 2 ) == 0) ) ) {
                captain[iter] += i;
                iter = !iter;
            }
        }

        printf("%lld\n", abs(captain[0] - captain[1]));
    }
    return 0;
}
