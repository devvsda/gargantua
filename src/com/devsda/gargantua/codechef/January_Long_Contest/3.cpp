#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

struct node {
    int sTime;
    int eTime;
    int cabin;
};

struct compare {
    bool operator()( const pair< pair<int, char>, int > &A, const pair< pair<int, char>, int > &B ) {
        return ( (A.first.first < B.first.first) || ( (A.first.first == B.first.first) && (A.first.second == 'E') ) ) ;
    }
};

main() {
    int T;
    int N, K;
    int sTime, eTime, cabin;
    cin >> T;

    while(T--) {
        cin >> N >> K;
        node points[N];
        vector< pair< pair<int, char>, int > > v;
        int totalCustomer = 0;
        int count = 0;
        map<int, int> seatOccupied;
        map<int, int> :: iterator it;
        set<int> blockCustomers;
        for(int i = 0; i < N; i++) {
            cin >> sTime >> eTime >> cabin;
            points[i].sTime = sTime;
            points[i].eTime = eTime;
            points[i].cabin = cabin;
            v.push_back( pair< pair<int, char>, int >(pair<int, char>(sTime, 'S'), i) );
            v.push_back( pair< pair<int, char>, int >(pair<int, char>(eTime, 'E'), i) );
        }

        sort(v.begin(), v.end(), compare());

        for(int i = 0; i < v.size(); i++) {
            if(v[i].first.second == 'S') {
                if( seatOccupied.count(points[v[i].second].cabin) == 0 ) {
                    seatOccupied.insert(pair<int, int>(points[v[i].second].cabin, v[i].second));
                    count++;
                }
                else {
                    it = seatOccupied.find(points[v[i].second].cabin);
                    if( (points[v[i].second].eTime) < points[it->second].eTime ) {
                        blockCustomers.insert(it->second);
                        it->second = v[i].second;
                        count--;
                    }
                    else {
                        blockCustomers.insert(v[i].second);
                    }
                }
            }
            else if( blockCustomers.count(v[i].second) == 0 ){
                count--;
                totalCustomer++;
                seatOccupied.erase( seatOccupied.find(points[v[i].second].cabin) );
            }
        }
        cout << totalCustomer << endl;
    }
    return 0;
}
