#include<stdio.h>
#include<limits.h>
#include<string>
#include<iostream>

using namespace std;

char matrix[200][200];
int workingArray[200][200];

void printArray(int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << workingArray[i][j] << "  ";
        }
        cout << endl;
    }
}

void findAllShortestPath(int N) {
    for(int k = 1; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if( workingArray[i][k] != INT_MAX && workingArray[k][j] != INT_MAX && ((workingArray[i][j]) > (workingArray[i][k] + workingArray[k][j])) )
                    workingArray[i][j] = (workingArray[i][k] + workingArray[k][j]);
            }
        }
        //cout << "K = " << k << endl;
        //printArray(N);
        //cout << endl;
    }
}

main() {
    int T;
    int N;
    int Q;
    int x, y;
    string s;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            cin >> s;
            for(int j = 0; j < N; j++) {
                matrix[i][j] = s[j];
                if(matrix[i][j] == 'Y') workingArray[i][j] = 1;
                else workingArray[i][j] = INT_MAX;
            }
        }
        //printArray(N);
        findAllShortestPath(N);
        scanf("%d", &Q);
        while(Q--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", workingArray[x][y]);
        }
    }
    return 0;
}
