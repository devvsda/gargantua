#include<iostream>
#include<limits.h>

using namespace std;

class TheShuttles {
    public :
        int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
            int answer = 0;
            int minCost = INT_MAX;
            for(int i = 1; i <= 100; i++) {
                answer = 0;
                for(int j = 0; j <  cnt.size(); j++) {
                    answer += cnt[j]/i;
                    if(cnt[j]%i != 0) answer++;
                }
                minCost = min(minCost, answer*(baseCost + i*seatCost));
            }
            return minCost;
        }
};

main() {
    return 0;
}

