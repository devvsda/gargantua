#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<limits.h>

#define MAX 100

using namespace std;

int minPartition[MAX]; // If not possible, then -1; otherwise any positive number.

class CuttingBitString {
    public :
        int getmin(string s);
};

bool check( string s ) {
    if(s[0] == '0') return false;
    long long int val = 0;
    for(int i = 0; i < s.size(); i++) { val = 2*val + (s[i] == '1'); }
    while( (val%5) == 0 ) { val /= 5; }
    return (val == 1);
}

int CuttingBitString::getmin(string s) {
    for(int i = 0; i < s.size(); i++) {
        if( check(s.substr(0, i+1)) ) minPartition[i] = 1;
        else {
            minPartition[i] = -1;
            for(int j = 1; j < i; j++) {
                if( minPartition[j-1] != -1 && check( s.substr(j, i-j+1) ) ) {
                    if(minPartition[i] == -1 || minPartition[i] > minPartition[j-1]+1 ) {
                        minPartition[i] = minPartition[j-1]+1;
                    }
                }
            }
        }
    }
    return minPartition[s.size()-1];
}
