#include<iostream>

using namespace std;

int maxPartition(string str) {
    int size = str.size();
    bool palindrome[size][size];
    int maxCut[size][size];

    memset(palindrome, false, sizeof(bool)*size*size);
    memset(maxCut, 0, sizeof(int)*size*size);

    for(int i = 0; i < size; i++) {
        palindrome[i][i] = true;
    }

    for(int i = 0; i < size; i++) {
        maxCut[i][i] = 0;
    }

    for(int length = 2; length <= size; length++) {
        for(int row = 0; row < (size - length + 1); row++) {
            int column = row + length - 1;
            if(str[row] == str[column]) {
                if(length == 2) {
                    palindrome[row][column] = true;
                }
                else palindrome[row][column] = palindrome[row+1][column-1];
            }


            if(palindrome[row][column]) {
                maxCut[row][column] = 0;
            }
            else {
                maxCut[row][column] = INT_MAX;
                for(int i = row; i < column; i++) {
                    maxCut[row][column] = min(maxCut[row][column], maxCut[row][i] + maxCut[i+1][column] + 1);
                }
            }
        }
    }
    return maxCut[0][size-1];
}

main() {
    cout << maxPartition("ABABBBABBABABA");
    return 0;
}
