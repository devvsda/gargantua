#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<limits.h>

#define MAX 100

using namespace std;

long long int input[MAX][MAX];
string ss;


class CuttingBitString {
    public :
        int getmin(string s);
};

bool isPower5(long long int val) {
    if(val == 0) return false;
    while(val%5 == 0) {
        val /= 5;
    }
    if(val == 1) return true;
    return false;
}

void getMinPartition(int size, int *partition, int currentPartition, int startIndex ) {
    if( startIndex == size ) {
        (*partition) = min( (*partition), currentPartition );
        return;
    }
    for(int i = size-1; i >= startIndex; i--) {
        if( ( ss[size-1-i] == '1' ) && isPower5( input[startIndex][i] ) ) {
            getMinPartition(size, partition, currentPartition+1, i+1);
        }
    }
}

int CuttingBitString::getmin(string s) {
    ss = s;
    int partition = INT_MAX;
    int sze = s.size();
    int index = sze-1;
    for(int i = 0; i < sze; i++) {
        input[i][i] = (s[index--] - 48);
    }

    for(int i = 0; i < sze; i++) {
        index = sze-2-i;
        for(int j = i+1; j < sze; j++) {
            input[i][j] = input[i][j-1] + ( ( (s[index--]-48) == 1 ) ? pow( 2, (double)(j-i) ) : 0 );
        }
    }
    getMinPartition(sze, &partition, 0, 0);
    if(partition == INT_MAX) return -1;
    return partition;
}

/*main() {
    //"110011011"
    getmin("1");

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << input[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}*/
