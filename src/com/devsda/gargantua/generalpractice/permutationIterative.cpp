#include<iostream>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

int cnt;

template<class BidirIt>
bool nextPermutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            iter_swap(i, i2);
            reverse(i1, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
}

void checkString(string s) {
	int i;
	for(i = 1; i < s.size(); i++) {
		if(s[i-1] == s[i]) break;
	}

	if(i == s.size()) cnt++;
}

int main() {
	string s;
	cin >> s;

	sort(s.begin(), s.end());

	do {
		checkString(s);
	} while(nextPermutation(s.begin(), s.end()));

	cout << cnt << endl;

	return 0;
}