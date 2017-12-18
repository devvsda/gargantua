#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[] = {0, 1, 2, 3};

class TheBrickTowerMediumDivTwo {
    public :
        vector<int> find(vector<int> heights);
};

vector<int> TheBrickTowerMediumDivTwo::find( vector<int> hs ) {
    int sze = hs.size();
    vector<int> v;
    for(int i = 0; i < sze; i++) v.push_back(i);
    int minm = hs[0];
    int sum = hs[0];

    for(int i = 1; i < sze; i++) {
        minm = min(minm, hs[i]);
        sum += hs[i];
    }

    sum -= minm;

    do {
        int i = 1;
        int currSum = 0;
        for(i = 1; i < sze; i++) {
            currSum += max(hs[ v[i] ], hs[ v[i-1] ]);
        }
        if(currSum == sum) return v;
    }while( next_permutation( v.begin(), v.end() ) );
}

main() {
    find();
}
