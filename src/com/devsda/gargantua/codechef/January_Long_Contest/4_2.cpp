#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

#define MAX 102

using namespace std;

int degree[MAX];
int graph[MAX][MAX];
bool visited[MAX];
queue<int> q;

void clearr(queue<int> &q) {
    queue<int> empti;
    swap(q, empti);
}

bool isPossible(int N) {
        int i, j;
        while( !q.empty() ) {
            int node = q.front();
            q.pop();
            for(i = 1; i <= N; i++) {
                if( graph[node][i] != 0 ) break;
            }
            for(j = 1; j <= N; j++ ) {
                if( j != node && graph[i][j] != 0 ) {
                    if(visited[j] == true) {
                        return false;
                    }
                    degree[i] -= graph[i][j];
                    degree[j] -= graph[i][j];
                    if( degree[j] == 0) { return false; }
                    if(degree[j] == 1) q.push(j);
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                }
            }
        }
        return true;
}

main() {
    int T;
    int N, M;
    int x, y;
    int i, j;
    int minDegree;
    int minDegreeIndex;

    cin >> T;

    while(T--) {
        clearr(q);
        memset(degree, 0, sizeof(degree));
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        cin >> N >> M;
        for(i = 0; i < M; i++) {
            cin >> x >> y;
            degree[x]++;
            degree[y]++;
            graph[x][y]++;
            graph[y][x]++;
        }
        if(N%2) {
            cout << "NO\n";
            continue;
        }

        //minDegree = degree[1];
        //minDegreeIndex = 1;

        for( i = 1; i <= N; i++ ) {
             if(degree[i] == 1) {
                 q.push(i);
                 visited[i] = true;
             }
             if(degree[i] == 0) {
                break;
            }
            /*if(minDegree > degree[i]) {
                minDegree = degree[i];
                minDegreeIndex = i;
            }*/
        }

        if( i <= N ) { cout << "NO\n"; continue; }

        if( q.size() == 0 ) {

            for(int node = 1; node <= N; node++) {
                vector< pair<int, int> > v;
                for(i = 1; i <= N; i++) {
                    if(graph[node][i] != 0) v.push_back( pair<int, int>(i, graph[node][i]) );
                }

                for(i = 0; i < v.size(); i++) {

                    for(j = 0; j < v.size(); j++) {
                        if(j != i) {
                            degree[node] -= v[j].second;
                            degree[v[j].first] -= v[j].second;
                            graph[node][v[j].first] = 0;
                            graph[v[j].first][node] = 0;
                        }
                        else if(graph[node][v[j].first] > 1){
                            degree[node] -= (v[j].second - 1);
                            degree[v[j].first] -= (v[j].second - 1);
                            graph[node][ v[j].first ] -= (v[j].second - 1);
                            graph[v[j].first][node] -= (v[j].second - 1);
                        }
                        if( degree[ v[j].first ] == 0 ) break;
                        if( degree[ v[j].first ]== 1 ) { q.push(v[j].first); visited[v[j].first] = true; }
                    }

                    if( j < v.size() ) { break; }

                    q.push(node);
                    visited[node] = true;
                    if(isPossible(N)) {
                        break;
                    }
                    clearr(q);

                    for(int j = 0; j < v.size(); j++) {
                        if(j != i) {
                            degree[node] += v[j].second;
                            degree[v[j].first] += v[j].second;
                            graph[node][v[j].first] += v[j].second;
                            graph[v[j].first][node] += v[j].second;
                        }
                        else {
                            degree[node] += (v[j].second-1);
                            degree[v[j].first] += (v[j].second-1);
                            graph[node][v[j].first] += (v[j].second-1);
                            graph[v[j].first][node] += (v[j].second-1);
                        }
                        if(degree[node] > 1) visited[node] = false;
                        if(degree[v[j].first] > 1) visited[v[j].first] = false;
                }
            }

                if( j < v.size() ) { cout << "NO\n"; continue; }
                if(i < v.size()) { cout << "YES\n"; continue;}

                cout << "NO\n";
                continue;
            }
        }

            if(isPossible(N)) cout << "YES\n";
            else cout << "NO\n";
    }
    return 0;
}
