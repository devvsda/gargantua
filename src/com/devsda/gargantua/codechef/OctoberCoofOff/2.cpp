//#include<iostream>
//#include<vector>
//#include<string>
#include<stdio.h>

using namespace std;

int numOfDigits(int val) {
    int count = 0;
    while(val) {
        val /= 10;
        count++;
    }
    return count;
}


int isMultiple(int val) {
    int count = 0;
    while( (val%10 == 0)) {
        val = val/10;
        count++;
    }
    return count;
}
main() {
    int T;
    int L;
    int R;
    long long int answer = 0;
    long long int currentAnswer;
    int num;
    int iter;
    int newVal;
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &L, &R);
        answer = 0;
        int i = L;
        while(i <= R) {
            num = numOfDigits(i);
            iter = 10*num - i;
            newVal = (i+iter-1);
            if( newVal <= R ) {
                answer += ( (( (newVal%1000000007)*(newVal+1) ) - ( (i-1)*(i%1000000007) ) )/2)*num;
                i = newVal+1;
            }
            else {
                answer += ( (((R%1000000007)*(R+1)) - ((i-1)*(i%1000000007)))/2)*num;
                i = R+1;
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}

