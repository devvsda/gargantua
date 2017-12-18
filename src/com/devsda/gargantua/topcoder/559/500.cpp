#include<iostream>
#include<string.h>

using namespace  std;

class HyperKnight{
    public :
        long countCells(int a, int b, int numRows, int numColumns, int k);
};

bool isValid(int x, int y, int nx, int ny) {
    if(x < 0 || y < 0 || x >= nx || y >= ny) return false;
    return true;
}

long HyperKnight::countCells(int a, int b, int numRows, int numColumns, int k) {
    long long int answer = 0;
    int x[] = {a, a, -a, -a, b, b, -b, -b};
    int y[] = {b, -b, b, -b, a, -a, a, -a};

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numColumns; j++) {
            int temp = 0;
            for( int k = 0; k < 8; k++ ) {
                if( isValid(i+x[k], j+y[k], numRows, numColumns) ) temp++;
            }
            if(temp == k) answer++;
        }
    }
    return answer;
}

main() {
    return 0;
}
