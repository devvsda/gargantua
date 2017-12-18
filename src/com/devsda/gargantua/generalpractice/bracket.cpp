#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isSequenceValid(string input) {

	stack<char> bracket;

	for(int i = 0; i < input.size(); i++) {

		if(input[i] == '(' || input[i] == '{' || input[i] == '[') {
			
			bracket.push(input[i]);
		
		} else if(input[i] == ')' || input[i] == '}' || input[i] == ']') {
			
			if(bracket.size() == 0) return false;

			if(input[i] == ')') {
				if('(' == bracket.top()){
					bracket.pop();
				} else {
					return false;	
				}
			} else if(input[i] == '}') {
				if('{' == bracket.top()){
					bracket.pop();
				} else {
					return false;	
				}
			} else if(input[i] == ']') {
				if('[' == bracket.top()){
					bracket.pop();
				} else {
					return false;	
				}
			}

		} else {
			// Will reach here only when current char is different than above 6 chars.
			return false;
		}
	}

	if(bracket.size() != 0) return false;
	return true;
}

int main() {

	while(true) {
		string s;
		cin >> s;
		cout << isSequenceValid(s);
		cout << endl;
	}
	return 0;
}