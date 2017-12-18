#include<iostream>
#include<vector>

using namespace std;

main() {
    int T;
    int N;
    int x, y;
    scanf( "%d", &T);

    while(T--) {
        int cnt = 0;
        int LN = 0, LP = 0, RN = 0, RP = 0;
        string answer = "";
        cin >> N;
        vector< pair< int, int > > v;
        for(int i = 0; i < N; i++) {
            cin >> x >> y;
            v.push_back(pair<int,int>(x, y));
        }

        for(int i = 1; i < v.size(); i++) {
            LN = 0; LP = 0; RN = 0; RP = 0;
            ( v[i-1].second > v[i].second ) ? (RN = v[i-1].second - v[i].second) : ( RP = v[i].second - v[i-1].second);
            ( v[i-1].first > v[i].first ) ? (LN = v[i-1].first - v[i].first) : ( LP = v[i].first - v[i-1].first);

            cnt += (LP + LN + RN + RP);
            //cout << cnt << endl;

            while(LP || LN || RN || RP) {
                //cout << LP << " " << LN << " " << RP << " " << RN << endl;
                if(LP > 0) {
                    if( (v[i-1].first + 1) < v[i-1].second ) {
                        (v[i-1].first)++;
                        LP--;
                        answer = answer + "L+";
                    }
                    else {
                        if(RP > 0) {
                            (v[i-1].second)++;
                            RP--;
                            answer += "R+";
                        }
                        else if(RN > 0) {
                            if( (v[i-1].first) < (v[i-1].second - 1) ) {
                                (v[i-1].second)--;
                                RN--;
                                answer += "R-";
                            }
                        }
                    }
                }
                else if(LN > 0) {
                    (v[i-1].first)--;
                    LN--;
                    answer += "L-";
                }
                else if(RP > 0) {
                    (v[i-1].second)++;
                    RP--;
                    answer += "R+";
                }
                else if(RN > 0) {
                    if( (v[i-1].first) < (v[i-1].second - 1) ) {
                        (v[i-1].second)--;
                        RN--;
                        answer += "R-";
                    }
                }
            }
        }
        cout << cnt << endl << answer << endl;
    }
    return 0;
}
