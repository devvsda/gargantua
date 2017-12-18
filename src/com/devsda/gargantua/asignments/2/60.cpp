#include<iostream>

using namespace std;

int LongestPalindrome(string input) {
    int size = input.size();
    int output[size][size];

    for(int i = 0; i < (size); i++)
        for(int j = 0; j < (size); j++)
            output[i][j] = 0;

    for(int i = 0; i < (size); i++) {
        output[i][i] = 1;
    }

    /*for(int i = 0; i < size-1; i++) {
        if(input[i] == input[i+1]) {

        }
    }*/

    int maxm = INT_MIN;

    for(int length = 2; length<=size; length++) {
        for(int row = 0; row<(size-length+1); row++) {
            int column = row+length-1;
            if(input[row]== input[column]) output[row][column] = output[row+1][column-1] + 2;
            if(output[row][column] > maxm) maxm = output[row][column];
            //else output[row][column] = max( output[row][column-1], output[row+1][column] );
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << output[i][j] << "    ";
        }
        cout << endl;
    }

    cout << endl << endl << maxm << endl;
    return output[0][size-1];
}

main() {
    cout << LongestPalindrome("BFNDABCBAAAABCDCBA");
    return 0;
}
