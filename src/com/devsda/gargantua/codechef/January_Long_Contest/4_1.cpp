#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

#define MAX 102

using namespace std;

int degree[MAX];
int graph[MAX][MAX];
bool visited[MAX];

main() {
    int T;
    int N, M;
    int x, y;
    int i, j;
    int flag = 0;

    cin >> T;

    while(T--) {
        queue<int> q;
        memset(degree, 0, sizeof(degree));
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        flag = 0;
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

        for( i = 1; i <= N; i++ ) {
             if(degree[i] == 1) {
                 q.push(i);
                 visited[i] = true;
             }
             if(degree[i] == 0) {
                flag = 1;
                break;
            }
        }

        while( (flag == 0) && (!q.empty()) ) {
            int node = q.front();
            q.pop();
            for(i = 1; i <= N; i++) {
                if( graph[node][i] != 0 ) break;
            }
            for( j = 1; j <= N; j++ ) {
                if( j != node && graph[i][j] != 0 ) {
                    if(visited[j] == true) {
                        flag = 1;
                        break;
                    }
                    degree[i] -= graph[i][j];
                    degree[j] -= graph[i][j];
                    if( degree[j] == 0) { flag = 1; break; }
                    if(degree[j] == 1) q.push(j);
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                }

            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
