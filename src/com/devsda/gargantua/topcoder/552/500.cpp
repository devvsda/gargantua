#include<iostream>
#include<algorithm>

using namespace std;

class FoxPaintingBalls{
    public :
       long long theMax(long long R, long long G, long long B, int N);
};

long long FoxPaintingBalls::theMax(long long R, long long G, long long B, int N){
    long long int x = ((N*(N+1))/6);
    if( N%3 == 0 || N%3 == 2 ) return ( min(R, min(G, B) )/x );
    long long int left = 0;
    long long int right = R+G+B;
    long long int result = 0;
    while(left <= right) {
        long long int mid = left + (right - left)/2;
        if( min(R, min(G, B))/x <= mid && R+G+B - 3*mid*x <= mid ) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid -1;
        }
    }
    return result;
}

main() {
    return 0;
}
