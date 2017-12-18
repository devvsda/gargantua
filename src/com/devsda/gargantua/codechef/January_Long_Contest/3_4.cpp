#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAX_CUSTOMER 100005

int cabinCustomer[MAX_CUSTOMER];
int endTimeCustomer[MAX_CUSTOMER];
bool blockCustomer[MAX_CUSTOMER];
map<int, int> seatOccupied;
map<int, int> :: iterator it;

struct compare {
    bool operator()( const pair< pair<int, int>, char > &A, const pair< pair<int, int>, char > &B ) {
        return ( (A.first.first < B.first.first) || ( (A.first.first == B.first.first) && ( (A.second == B.second == 'S') || (A.second == B.second == 'E') || (A.second == 'E' && B.second == 'S') ) ) ) ;
    }
};

main() {
    int T;
    int N, K;
    int s, e, c;
    int totalCustomer = 0;

    scanf("%d", &T);

    while(T--) {
        vector< pair< pair<int, int>, char > > v;
        memset(blockCustomer, 0, sizeof(blockCustomer));
        scanf("%d %d", &N, &K);
        totalCustomer = 0;

        for(int i = 0; i < N; i++) {
            scanf("%d %d %d", &s, &e, &c);
            v.push_back( pair< pair<int, int>, char >(pair<int, int>(s, i), 'S') );
            v.push_back( pair< pair<int, int>, char >(pair<int, int>(e, i), 'E') );
            cabinCustomer[i] = c;
            endTimeCustomer[i] = e;
        }

        sort( v.begin(), v.end(), compare() );

        for(int i = 0; i < v.size(); i++) {
            if( v[i].second == 'S' ) {
                it = seatOccupied.find( cabinCustomer[ v[i].first.second ] );
                if(  it == seatOccupied.end() ) {
                    seatOccupied.insert( pair<int, int>( cabinCustomer[v[i].first.second], v[i].first.second ) );
                }
                else {
                    if( (endTimeCustomer[ v[i].first.second ]) < (endTimeCustomer[ it->second ]) ) {
                        blockCustomer[it->second] = true;
                        it->second = v[i].first.second;
                    }
                    else {
                        blockCustomer[v[i].first.second] = true;
                    }
                }
            }
            else if( blockCustomer[v[i].first.second] == false ) {
                totalCustomer++;
                seatOccupied.erase( cabinCustomer[v[i].first.second] );
            }
        }
        printf("%d\n", totalCustomer);
    }
    return 0;
}


