#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

set<string> setStr;

void checkString(string s) {
	//cout << s << endl;
	int i;
	for(i = 1; i < s.size(); i++) {
		if(s[i-1] == s[i]) break;
	}

	if(i == s.size()) setStr.insert(s);
}

void getAllPermutation(string input, int start, int end) {

	if(start == end) {
		checkString(input);
		return;
	}


	for(int i = start; i <= end; i++) {
		swap(input[start], input[i]);
		getAllPermutation(input, start + 1, end );
		swap(input[start], input[i]);
	}
}

int main() {

	string s;
	cin >> s;

	getAllPermutation(s, 0, s.size() - 1);

	cout << setStr.size() << endl;

	return 0;
}