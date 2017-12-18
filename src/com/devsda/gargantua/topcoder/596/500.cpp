#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

/*
class ColorfulRoad {
    public :
        int minEnergy(string road);
};
*/

int /*ColorfulRoad::*/minEnergy(string road) {
    int sze = road.size();
    int dp[sze];
    for( int i = 0; i < sze; i++ ) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 1; i < sze; i++) {
        char other;
        if( road[i] == 'R') other = 'B';
        else if(road[i] == 'G') other = 'R';
        else other = 'G';
        for(int j = 0; j < i; j++) {
            if( dp[j] != INT_MAX && road[j] == other ) {
                if( dp[i] == INT_MAX || (dp[j] + (i-j)*(i-j)) < dp[i] ) {
                    dp[i] = dp[j] + (i-j)*(i-j);
                }
            }
        }
    }
    //for( int i = 0; i < sze; i++ ) cout << dp[i] << "  ";
    //cout << endl;
    return ( (dp[sze-1] == INT_MAX) ? -1 : dp[sze-1] );
}

main() {
    cout << minEnergy("RBG");
    return 0;
}
