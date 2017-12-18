#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

#define MAX_CUSTOMER 100005

using namespace std;

struct node {
    int sTime;
    int eTime;
    int cabin;
};

bool blockCustomer[MAX_CUSTOMER];
vector< pair< pair<int, char>, int > > v;
map<int, int> seatOccupied;
map<int, int> :: iterator it;
node customers[MAX_CUSTOMER];

struct compare {
    bool operator()( const pair< pair<int, int>, char > &A, const pair< pair<int, int>, char > &B ) {
        return ( (A.first.first < B.first.first) || ( (A.first.first == B.first.first) && ( (A.first.second == B.first.second == 'S') || (A.first.second == B.first.second == 'E') || (A.first.second == 'E' && B.first.second == 'S') ) ) ) ;
    }
};

main() {
    int T;
    int N, K;
    int s, e, c;
    int totalCustomer = 0;
    int count = 0;

    scanf("%d", &T);

    while(T--) {

        for(int i = 0; i < MAX_CUSTOMER; i++) blockCustomer[i] = false;
        scanf("%d %d", &N, &K);
        totalCustomer = 0;
        count = 0;

        for(int i = 0; i < N; i++) {
            scanf("%d %d %d", &s, &e, &c);
            v.push_back( pair< pair<int, char>, int >(pair<int, char>(s, 'S'), i) );
            v.push_back( pair< pair<int, char>, int >(pair<int, char>(e, 'E'), i) );
            customers[i].sTime = s;
            customers[i].eTime = e;
            customers[i].cabin = c;
        }

        sort(v.begin(), v.end(), compare());

        for(int i = 0; i < v.size(); i++) {
            if( v[i].first.second == 'S' ) {
                if( seatOccupied.find( customers[v[i].second].cabin ) == seatOccupied.end() ) {
                    seatOccupied.insert( pair<int, int>( customers[v[i].second].cabin, v[i].second ) );
                    count++;
                }
                else {
                    it = seatOccupied.find( customers[v[i].second].cabin );
                    if( (customers[ v[i].second ].eTime) < (customers[ it->second ].eTime) ) {
                        blockCustomer[ it->second ] = true;
                        it->second = v[i].second;
                    }
                    else {
                        blockCustomer[ v[i].second ] = true;
                    }
                }
            }
            else if( blockCustomer[ v[i].second ] == false ) {
                count--;
                totalCustomer++;
                seatOccupied.erase( customers[v[i].second].cabin );
            }
        }
        printf("%d\n", totalCustomer);
        v.clear();
    }
    return 0;
}

