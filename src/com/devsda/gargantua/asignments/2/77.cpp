#include<iostream>
#include<stack>
#include<string>

using namespace std;

/*
bool isRightPattern( string input) {
    if(input.size() == 0) return true;
    stack<char> s;
    if(input[0] = '}') return false;
    s.push(input[0]);
    for(int i = 1; i < input.size(); i++) {
        if(input[i] == '}') {
            if(s.empty()) return false;
            s.pop();
        }
        else s.push(input[i]);
    }

    if(s.empty()) return true;
    return false;
}
*/

bool isRightPattern(string input) {
    int open = 0;
    int close = 0;

    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '{') open++;
        else close++;

        if(close > open) return false;
    }

    return (open == close);
}

main() {
    cout << isRightPattern("");
    return 0;
}
