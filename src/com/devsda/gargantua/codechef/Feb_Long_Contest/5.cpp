#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

#define MAX 100000

//#define NOT_STARTED_YET 0
//#define UNDER_PREOCESSING 1
//#define PROCESSING_COMPLETED 2

vector< vector<int> > v(50001);
int havingDrought[MAX];
int isWindowOpen[MAX];
//int states[MAX];
bool visited[MAX];
int answer;

// HADD H, BFS KAISE KOI LAGA SAKTAA H YHAA PE....
// DFS LAGEGAA IDHAR.
/*void BFS(int node) {
    queue<int> q;
    int index;
    q.push(node);
    states[node] = UNDER_PREOCESSING;

    while(q.size() != 0) {
        index = q.front();
        q.pop();
        for(int i = 0; i < v[index].size(); i++) {
            if( states[v[index][i]] == NOT_STARTED_YET && isWindowOpen[v[index][i]] ) {
                q.push(v[index][i]);
                states[v[index][i]] = UNDER_PREOCESSING;
                answer++;
            }
        }
        states[index] = PROCESSING_COMPLETED;
    }
}*/

void DFS(int node, int *count) {
    visited[node] = true;
    (*count)++;
    //int pairs;
    //if(isWindowOpen[node])
    //int pairs = 1;
    //else pairs = 0;
    for(int i = 0; i < v[node].size(); i++) {
        if(isWindowOpen[v[node][i]] && !visited[v[node][i]]) {
            //pairs = pairs +
            DFS(v[node][i], count);
        }
    }
    //return pairs;
}

main() {
    int N, M;
    int x, y;
    int secondAnswer = 0;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> isWindowOpen[i];

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        if(isWindowOpen[x] && isWindowOpen[y]) havingDrought[x] = havingDrought[y] = 1;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i = 1; i <= N; i++ ) {
        if( !visited[i] && isWindowOpen[i]) {
            int count = 0;
            DFS(i, &count);
            answer += (count*(count-1))/2;
        }
        /*if(isWindowOpen[i]){
            memset(states, 0, sizeof(states));
            BFS(i);
        }*/
    }

    for(int i = 1; i <= N; i++) secondAnswer += havingDrought[i];
    cout << (answer/2) << " " <<  secondAnswer << endl;
    return 0;
}
