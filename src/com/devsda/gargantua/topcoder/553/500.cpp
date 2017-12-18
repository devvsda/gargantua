#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define MAX 1000000000


class Suminator {
    public :
        int findMissing(vector <int> program, int wantedResult);
};



long long int getValue(vector<int> program, int mid) {
    stack<long long int> s;
    long long int first = 0;
    long long int second = 0;

    for(int i = 0; i < program.size(); i++) {
        if( program[i] > 0 ) s.push(program[i]);
        else if(program[i] == 0) {
            if( !s.empty() ) { first = s.top(); s.pop(); }
            else first = 0;
            if( !s.empty() ) { second = s.top(); s.pop(); }
            else second = 0;
            s.push( first+second );
        }
        else {
            if(mid == 0) {
                if( !s.empty() ) { first = s.top(); s.pop(); }
                else first = 0;
                if( !s.empty() ) { second = s.top(); s.pop(); }
                else second = 0;
                s.push(first + second);
            }
            else {
                s.push(mid);
            }
        }
    }
    return s.top();
}

int findAnswer(vector<int> program, int target, int start, int end) {
    cout << start << "   " << end << endl;
    if(start > end) return -1;
    int mid = start + ( end - start )/2;
    if( getValue(program, start) == target ) return start;
    long long int answer = getValue(program, mid);
    cout << answer << endl;
    if(answer == target) return mid;
    if(answer > target) return findAnswer(program, target, start, mid);
    else return findAnswer(program, target, mid+1, end);
}

int findMissing(vector <int> program, int wantedResult) {
    int right = MAX;
    int left = 0;
    return findAnswer(program, wantedResult, left, right);
}

main() {
    int arr[] = {2, 2, -1};
    vector<int> v;// = (arr);
    v.push_back(2);
    v.push_back(2);
    v.push_back(-1);
    cout << findMissing(v, 1);
    return 0;
}
