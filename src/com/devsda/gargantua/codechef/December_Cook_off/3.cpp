#include<iostream>
#include<set>
#include<vector>
#include<string>

using namespace std;

vector< set<string> > v(50001);

main() {
    int T;
    int start, end;
    int N;

    cin >> T;

    while(T--) {
        string S;
        cin >> S;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> start >> end;
            for( int j = start; j <= end; j++ ) {
                for(int k = 1; k < (S.size() - j); k++ ) {
                    string ss = S.substr(j, k);
                    if( v[k].count(ss) == 0 ) v[k].insert(ss);
                    cout << "hi\n";
                }
            }

            int size = 0;
            for(int i = 0; i < 50001; i++) {
                size += v[i].size();
            }
            cout << size << endl;
            v.clear();
        }
    }
    return 0;
}
