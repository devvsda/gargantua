#include<iostream>
#include<vector>

using namespace std;

vector< vector< vector<int> > > v(11);

main() {
    int N;
    int Q;
    int x1, y1, x2, y2;
    int val;
    int num, xVal , yVal;
    int answer;

    cin >> N;

    vector< vector<int> > vv(301);

    for(int num = 0; num <= 10; num++) {
        for(int i = 0; i <= 300; i++) {
            v[num] = vv;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> val;
            v[val][i].push_back(j);
        }
    }

    cin >> Q;

    for(int i = 0; i < Q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        answer = 0;
        for(num = 1; num <= 10; num++) {
            for(xVal = x1; xVal <= x2; xVal++) {
                for(yVal = 0; yVal < v[num][xVal].size(); yVal++) {
                    if( v[num][xVal][yVal] >= y1 && v[num][xVal][yVal] <= y2) {
                        answer++;
                        break;
                    }
                }
                if(yVal != v[num][xVal].size()) break;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
