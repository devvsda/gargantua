#include<iostream>

using namespace std;

int isMatch(string a, string b, int ia, int ib) {
	
	// base condition
	if(ia == a.size() && ib == b.size()) return 1; 
	
	// example : aa , aaa*b*c*
	if(ia == a.size() && ib < b.size() - 1 && b[ib+1] == '*') return isMatch(a, b, ia, ib+2);
	
	// Base condition
	if(ia >= a.size() || ib >= b.size()) return 0;

    //cout << a.substr(ia) << " " << b.substr(ib) << endl;

	// removes ".", and treat it like similar character as a[ia]
	if( b[ib] == '.') {
		//cout << "PT1 " << a.substr(ia) << " " << b.substr(ib) << endl;
		b[ib] = a[ia];
		return isMatch(a, b, ia, ib);
	}

	// example : aa , ba
	if( a[ia] != b[ib] && ( ib == b.size()-1 || b[ib+1] != '*' ) ) {
		//cout << "PT2: " << a.substr(ia) << " " << b.substr(ib) << endl;
		return 0;
	}

	// example : aa , ab
	if( a[ia] == b[ib] && ( ib == b.size()-1 || b[ib+1] != '*' ) ) {
		//cout << "PT3 " << a.substr(ia) << " " << b.substr(ib) << endl;
		return isMatch(a, b, ia+1, ib+1);
	}

	// example : aa , b*aa
	if(a[ia] != b[ib] && ( ib == b.size()-1 || b[ib+1] == '*' ) ) {
		//cout << "PT4 " << a.substr(ia) << " " << b.substr(ib) << endl;
		return isMatch(a, b, ia, ib+2);
	}

	// example : aa , a*
	if( b[ib] == a[ia] && ( ib == b.size()-1 || b[ib+1] == '*' )) {
		//cout << "PT5 " << a.substr(ia) << " " << b.substr(ib) << endl;
		return ( isMatch(a, b, ia, ib+2) || isMatch(a, b, ia+1, ib));
	}

	// compilar will never reach here.
	return 0;
}


// dnagpal@groupon.com

int main() {

	string a, b;
	//cout << isMatch("aab", "aab", 0, 0);
	while(true) {
		cin >> a >> b;
		cout << isMatch(a, b, 0, 0) << endl;
	}
	
	return 0;
}