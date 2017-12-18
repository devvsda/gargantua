#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

set<string> setStr;

void permutation(int k, string &s) 
{
    for(int j = 1; j < s.size(); ++j) 
    {
        std::swap(s[k % (j + 1)], s[j]); 
        k = k / (j + 1);
    }
}

int factorial(int n) {
	int answer = 1;
	for(int i = 1; i <= n; i++) answer *= n;
	return answer;
}

void checkString(string s) {
	//cout << s << endl;
	int i;
	for(i = 1; i < s.size(); i++) {
		if(s[i-1] == s[i]) break;
	}

	if(i == s.size()) setStr.insert(s);
}

int main() {
	string s;
	cin >> s;

	for(int i = 1; i <= factorial(s.size()); i++) {
		permutation(i, s);
		checkString(s);
	}

	cout << setStr.size() << endl;
	return 0;
}