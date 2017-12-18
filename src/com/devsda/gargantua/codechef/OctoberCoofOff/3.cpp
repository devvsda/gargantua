#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int arr[10005];
int dp[10005];
vector< pair<double, pair<int, int> > > v;

bool sort_pred(const pair<double, pair< int, int> >& left, const pair<double, pair<int, int > >& right)
{
    return ( (left.first < right.first) ||  ( (left.first == right.first) &&  (left.second.second > right.second.second) ) );
}

void printV(int N) {
    for(int i = 0; i < N; i++) cout << v[i].first << "  " << v[i].second.first << "  " << v[i].second.second << endl;
}

main() {
    int T;
    int N, W;
    double ratio;
    int number, points, time;
    int maxPoints;
    int p;
    int t;
    scanf("%d", &T);



    while(T--){
        scanf("%d %d", &N, &W);
        maxPoints = 0;
        t = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d %d %d", &number, &points, &time);
            ratio = (double)(number*points)/(double)time;
            v.push_back( pair<double, pair<int, int> >(ratio, pair<int, int>( (number*points), time) ));
        }
        printV(N);
        sort(v.begin(), v.end(), sort_pred);
        printf("\n");
        printV(N);
        printf("\n");

        for(int i = N-1; i >= 0; i--){
            /*if( t + v[i].second.second <= W) {
                t = t + v[i].second.second;
                maxPoints =  maxPoints + v[i].second.first;
            }
            if(t == W) break;*/
            arr[ v[i].second.second ] = v[i].second.first;
            if(v[i].second.second <= W) dp[ v[i].second.second ] = v[i].second.first;
        }

        /*int max = -999999;
        for(int i = 0; i <= W; i++) {
            for(int j = 0; ((j < i) && (j < (W-i))); j++ ) {
                if( dp[i] < dp[i] + arr[j]  ) dp[i] = dp[i] + arr[j];
                if(max < dp[i]) max = dp[i];
            }
        }
        printf("%d\n", max);*/
        v.clear();
    }
    return 0;
}

