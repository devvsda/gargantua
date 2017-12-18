#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

vector< pair<int, int> > v;

bool isPossible( bool *edges, int *degree, int start, int sze, int num1s, int vertex ) {
    if( start == sze ) return false;
    for(int i = 1; i <= vertex; i++) if( degree[i] != 1) break;
    if( i == (vertex+1) ) return true;
    bool withoutRemoving = isPossible(edges, degree, start+1, sze, num1s, vertex);
    if(withoutRemoving == true) return true;
    if(degree[v[start].first] > 0) { degree[v[start].first]--; degree[v[start].second]--; }
    return isPossible(edges, degree, start+1, sze, num1s, vertex);
}
main() {
    int T;
    int N, M;
    cin >> T;

    while(T--) {
        cin >> N >> M;
        bool edges[M];
        int degree[N+1];
        memset(edges, 0, sizeof(edges));
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < M; i++) {
            cin >> x >> y;
            degree[x]++;
            degree[y]++;
            if(x < y) v.push_back(pair<int, int>(x, y);
            else v.push_back(pair<int, int>(y, x));
        }

        if( isPossible(edges, degree, 0, M, 0, N) ) cout << "YES\n";
        else cout << "NO\n";
        v.clear();
    }
    return 0;
}
