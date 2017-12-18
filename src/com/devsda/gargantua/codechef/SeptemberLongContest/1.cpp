#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

#define ROW 500
#define COLUMN 500

#define START 0
#define END 53

char cell[ROW][COLUMN];
int leftCount[ROW][COLUMN];
int rightCount[ROW][COLUMN];
int topCount[ROW][COLUMN];
int bottomCount[ROW][COLUMN];

int primeNumber[] = {2,	3,	5,	7,	11,	13,	17,	19,	23,
29,	31,	37,	41,	43,	47,	53,	59,	61,	67,
71,	73,	79,	83,	89,	97,	101,	103,	107,	109,
113,	127,	131,	137,	139,	149,	151,	157,	163,	167,
173,	179,	181,	191,	193,	197,	199,	211,	223,	227,
229,	233,	239, 241, 251};

//int primeNumber[] ={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };

int findFloorIndex(int key, int start, int end) {
    if(start > end) return -1;
    if( primeNumber[end] <= key ) return end;
    if(primeNumber[start] > key) return -1;

    int mid = start + (end - start)/2;

    if( ((mid == 0) ||  (primeNumber[mid-1] <= key)) && (primeNumber[mid] > key)  )  return (mid-1);
    if( (primeNumber[mid] <= key) && ( (mid == end) || (primeNumber[mid+1] > key) ) ) return mid;

    if(primeNumber[mid] > key) return findFloorIndex(key, start, mid-1);
    else return findFloorIndex(key, mid, end);

    //if( key >= 2 ) return true;
    //return false;
}

void updateLeftCount(int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(j == 0) {
                leftCount[i][j] = 0;
            }
            else if( cell[i][j-1] != '#' ) {
                leftCount[i][j] = leftCount[i][j-1] + 1;
            }
            else {
                leftCount[i][j] = 0;
            }
        }
    }
}

void updateRightCount(int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = C-1; j >= 0; j--) {
            if(j == C-1) {
                rightCount[i][j] = 0;
            }
            else if( cell[i][j+1] != '#' ) {
                rightCount[i][j] = rightCount[i][j+1] + 1;
            }
            else {
                rightCount[i][j] = 0;
            }
        }
    }
}

void updateTopCount(int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(i == 0) {
                topCount[i][j] = 0;
            }
            else if(cell[i-1][j] != '#') {
                topCount[i][j] = topCount[i-1][j] + 1;
            }
            else {
                topCount[i][j] = 0;
            }
        }
    }
}

void updateBottomCount(int R, int C) {
    for(int i = R-1; i >= 0; i--) {
        for(int j = 0; j < C; j++) {
            if(i == R-1) {
                bottomCount[i][j] = 0;
            }
            else if(cell[i+1][j] != '#') {
                bottomCount[i][j] = bottomCount[i+1][j] + 1;
            }
            else {
                bottomCount[i][j] = 0;
            }
        }
    }
}

void resetAllCounters(int R, int C) {
   for(int i = 0; i < R; i++) {
       for(int j = 0; j < C; j++) {
           leftCount[i][j] = 0;
           rightCount[i][j] = 0;
           topCount[i][j] = 0;
           bottomCount[i][j] = 0;
       }
   }
   /*memset(leftCount, 0, sizeof(int)*(ROW*COLUMN));
   memset(rightCount, 0, sizeof(int)*(ROW*COLUMN));
   memset(topCount, 0, sizeof(int)*(ROW*COLUMN));
   memset(bottomCount, 0, sizeof(int)*(ROW*COLUMN));*/
}

void initializeCell(int R, int C) {
    for(int j = 0; j < R; j++) {
        for(int k = 0; k < C; k++) {
            cin >> cell[j][k];
        }
    }
}

void printMatrix(char arr[][50], int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
             cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void printMatrix(int arr[][50], int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void safePassengers() {
    int T;
    int R;
    int C;
    int count = 0;

    cin >> T;

    for(int i = 0; i < T; i++) {
        count = 0;
        cin >> R >> C;
        resetAllCounters(R, C);
        initializeCell(R, C);
        updateLeftCount(R, C);
        updateRightCount(R, C);
        updateTopCount(R, C);
        updateBottomCount(R, C);

        /*cout << "\nLeft Count\n";
        printMatrix(leftCount, R, C);
        cout << "\nRight Count\n";
        printMatrix(rightCount, R, C);
        cout << "\nTop Count\n";
        printMatrix(topCount, R, C);
        cout << "\nBottom Count\n";
        printMatrix(bottomCount, R, C);
        cout << endl;*/

        /*printMatrix(cell, R, C);
        cout << endl;*/

        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if( cell[j][k] != '#') {
                    //cout << "Reach Here";
                    int minm = min( min( leftCount[j][k], rightCount[j][k] ), min( topCount[j][k], bottomCount[j][k] ) );
                    //cout << "  " << minm;
                    int val = findFloorIndex( minm, START, END ) ;
                    //cout << "  " << val << endl;
                    if(val != -1) count = count + val + 1;
                }
            }
        }
        cout << count << endl;
    }
}

int main() {
    //freopen ("input.txt","r",stdin);
    safePassengers();
    return 0;
}
