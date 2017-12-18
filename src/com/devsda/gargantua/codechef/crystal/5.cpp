#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

char jumble[100][100];
vector< vector< pair<int, int> > > co_ordinates(26);
int xx;

int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1 };
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1 };

int isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= xx || y >= xx) return 0;
    return 1;
}

int DFS(int x, int y, int index, string s) {
    for(int i = 0; i < 8; i++) {
        int newX = x+dx[i];
        int newY = y+dy[i];
        index = 1;
        while( isValid(newX, newY) && (index != s.size()) && (jumble[newX][newY] == s[index]) ) {
            newX += dx[i];
            newY += dy[i];
            index += 1;
        }
        if(index == s.size()) {
            printf("%d,%d %d,%d\n", (x+1), (y+1), (newX-dx[i]+1), (newY-dy[i]+1));
            return 1;
        }
    }
    return 0;
}
void printCo_ordinates(string s) {
    int i;
    for(i = 0; i < co_ordinates[s[0]-'A'].size(); i++) {
        int x = co_ordinates[s[0]-'A'][i].first;
        int y = co_ordinates[s[0]-'A'][i].second;
        int moveAhead = DFS(x, y, 1, s);
        if(moveAhead) break;
    }
    if(i == co_ordinates[s[0]-'A'].size()) cout << "Not found\n";
}

main() {
    string s;
    cin >> xx;
    for(int i = 0; i < xx; i++) {
        cin >> s;
        for(int j = 0; j < xx; j++) {
            jumble[i][j] = s[j];
            co_ordinates[s[j]-'A'].push_back( pair<int, int>(i, j) );
        }
    }

    cin >> s;
    while(s != "0") {
        printCo_ordinates(s);
        cin >> s;
    }

    return 0;
}
