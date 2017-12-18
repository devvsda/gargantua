#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

#define MAX_CUSTOMER 100005
// Strucure to store information of every customer
/*struct node {
    int sTime;
    int eTime;
    int cabin;
};*/

int cabinCustomer[MAX_CUSTOMER];
int endTimeCustomer[MAX_CUSTOMER];

// If any Customer is not allowed to enter to maximize number of customer, then TRUE, otherwise FALSE
//bool blockCustomer[100005];
set<int> blockCustomer;
// (StartingTime/EndingTime, state(STARTING/ENDING), customer Id)
vector< pair< pair<int, char>, int > > v;
// Which cabin is allocated to which customer (cabin, customer Id)
map<int, int> seatOccupied;
map<int, int> :: iterator it;
//node customers[100005];

// It sorts vector, in increasing way, If Starting and Ending state time is same, then Ending comes first
struct compare {
    bool operator()( const pair< pair<int, char>, int > &A, const pair< pair<int, char>, int > &B ) {
        return ( (A.first.first < B.first.first) || ( (A.first.first == B.first.first) && (A.first.second == 'E') ) ) ;
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

        //for(int i = 0; i <= 100002; i++) blockCustomer[i] = false;
        scanf("%d %d", &N, &K);
        totalCustomer = 0;
        count = 0;

        for(int i = 0; i < N; i++) {
            scanf("%d %d %d", &s, &e, &c);
            v.push_back( pair< pair<int, char>, int >(pair<int, char>(s, 'S'), i) );
            v.push_back( pair< pair<int, char>, int >(pair<int, char>(e, 'E'), i) );
            /*customers[i].sTime = s;
            customers[i].eTime = e;
            customers[i].cabin = c;*/
            cabinCustomer[i] = c;
            endTimeCustomer[i] = e;
        }

        sort(v.begin(), v.end(), compare());

        for(int i = 0; i < v.size(); i++) {
            // If value is in starting state
            if( v[i].first.second == 'S' ) {
                // If Cabin is free
                if( seatOccupied.find( cabinCustomer[v[i].second] ) == seatOccupied.end() ) {
                    seatOccupied.insert( pair<int, int>( cabinCustomer[v[i].second], v[i].second ) );
                    count++;
                }
                // If that seat is already boooked by previous customer, then use greedy approach
                else {
                    it = seatOccupied.find( cabinCustomer[v[i].second] ); // Previously Seated Customer
                    // Block Previous customer
                    if( (endTimeCustomer[ v[i].second ]) < (endTimeCustomer[ it->second ]) ) {
                        //blockCustomer[ it->second ] = true;
                        blockCustomer.insert(it->second);
                        it->second = v[i].second;
                    }
                    else {
                        //blockCustomer[ v[i].second ] = true;
                        blockCustomer.insert(v[i].second);
                    }
                }
            }
            // If it is End state, means customer is going to leave ,and also that customer is not blocked then increment customer count
            else if( blockCustomer.count(v[i].second) == 0) { //blockCustomer[ v[i].second ] == false ) {
                count--;
                totalCustomer++;
                //if( seatOccupied.find(customers[v[i].second].cabin) != seatOccupied.end() )
                seatOccupied.erase( cabinCustomer[v[i].second] );
            }
        }
        printf("%d\n", totalCustomer);
        v.clear();
        blockCustomer.clear();
        //seatOccupied.clear();
    }
    return 0;
}
