#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> findAllSubset(char c, vector<string> v) {
    int size = v.size();
    if(size == 1) {
        v.push_back("");
        return v;
    }
    c = v[size-1][0];
    v.pop_back();
    v = findAllSubset(c, v);
    int k = v.size();
    for(int i = 0; i < k; i++) {
        string s= "";
        if(v[i].size() == 0){
            s += c;
            v.push_back(s);
        }
        else {
            s += v[i] + c;
            v.push_back( s );
        }
    }
    return v;
}

main() {
    vector<string> v, ans;
    char c = 65;
    v.push_back("a");
    v.push_back("b");
    v.push_back("c");
    v.push_back("d");
    ans = findAllSubset(c, v);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] <<endl;
    return 0;
}
