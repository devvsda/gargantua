#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return ( (a.first < b.first) || ( (a.first == b.first)&&(a.second < b.second) ) );
    }
};

class TheBrickTowerMediumDivTwo {
    public :
        vector<int> find(vector<int> heights);
};

vector<int> TheBrickTowerMediumDivTwo::find(vector<int> heights) {
    vector< pair<int, int> > v;
    vector<int> answer;
    for(int i = 0; i < heights.size(); i++) v.push_back(pair<int, int>(heights[i], i));
    sort( v.begin(), v.end(), compare() );
    for(int i = 0; i < v.size(); i++) answer.push_back(v[i].second);
    int i;
    for(i = 0; i < answer.size(); i++ ) if(answer[i] == 0) break;
    answer[i] = answer[0];
    answer[0] = 0;
    return answer;
}

main() {
    return 0;
}
