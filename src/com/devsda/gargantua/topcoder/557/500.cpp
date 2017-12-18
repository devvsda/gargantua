#include<iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

class IncubatorEasy {
public:
  int maxMagicalGirls(vector <string>);
};

int calc(int bits, int sze, vector<string> &s) {
    int magical[sze];// = {0};
    int safe[sze];// = {0};
    memset(magical, 0, sizeof(magical));
    memset(safe, 0, sizeof(safe));

    for(int i = 0; i < sze; i++) magical[i] = ((bits >> i) & 1);
    for(int i = 0; i < sze; i++) {
        if(magical[i]) {
            for(int j = 0; j < sze; j++) {
                if(s[i][j] == 'Y') safe[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < sze; i++) {
        if(magical[i] && !safe[i]) cnt++;
    }
    return cnt;
}

int IncubatorEasy::maxMagicalGirls(vector<string> s) {
    int n = s.size();

    // Below is Floyd Warshell Algorithm, that helps to convert lovable matrix to protected matrix
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i][k] == 'Y' && s[k][j] == 'Y') {
                    s[i][j] = 'Y';
                }
            }
        }
    }

    int answer = INT_MIN;
    for(int i = 0; i < (1 << n); i++) {
        answer = max(answer, calc(i, n, s));
    }
    return answer;
}

main() {
    return 0;
}
