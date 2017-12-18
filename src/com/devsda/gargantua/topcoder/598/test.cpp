
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

    string simulate(string s){
        if(s.size() == 1) return s;

        for(int j = 1; j < s.size(); j++) {
            if(s[j] == s[j-1]) {
                s.erase(j-1, 1);
                s.erase(j-1, 1);
                j = 1;
            }
        }

        for(int j = 1; j < s.size(); j++) {
            if(s[j] == s[j-1]) {
                s.erase(j-1, 1);
                s.erase(j-1, 1);
                j = 1;
            }
        }

        return s;
    }

main() {
    cout << simulate("lklklkccklkcckllcclkccklklclkclkccklcklcklllkcckllkcclkccklklklkccklclkccklckll");
    return 0;
}
