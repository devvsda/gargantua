#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define MAX 1000000000


class Suminator {
    public :
        int findMissing(vector <int> program, int wantedResult);
};

long long int calc(vector<int> p, int val) {
    stack<long long int> s;
    long long int first, second;

    for(int i = 0; i < p.size(); i++) { if(p[i] == -1) { p[i] = val; break; } }
    for(int i = 0; i < 100; i++) s.push(0);

    for(int i = 0; i < p.size(); i++) {
        if(p[i] > 0) s.push(p[i]);
        else {
            first = s.top();
            s.pop();
            second = s.top();
            s.pop();
            s.push(first+second);
        }
    }
    return s.top();
}

int Suminator::findMissing(vector <int> program, int wantedResult) {
    if( cal(program, 0) == wantedResult ) return 0;

    long long int u = calc(program, 1);
    long long int v = calc(program, 2);

    if(u == v) return -1;

    if(u < wantedResult) return (wantedResult - (u-1) );
    else -1;
}
