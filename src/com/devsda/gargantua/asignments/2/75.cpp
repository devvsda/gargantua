#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void swap(char *a, char *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int nextGreaterNumber(int number) {
    string s = "";

    while(number) {
        s = (char)((number%10) + 48) + s;
        number /= 10;
    }

    int first = s.size() - 2;
    while(first >= 0) {
        if(s[first] < s[first+1]) break;
        first--;
    }

    int second = first+1;
    for(int j = first + 1; j < s.size(); j++) {
        if(s[j] > s[first] && s[j] < s[second]) {
            second = j;
        }
    }

    swap(&s[first], &s[second]);

    sort(s.begin() + first+1, s.end());

    int i = 0;
    int answer = 0;
    while(i < s.size()) {
        answer = answer*10 + (s[i]-48);
        i++;
    }

    return answer;
}

main() {
    cout << nextGreaterNumber(12345);
}
