#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<set>

using namespace std;

class FoxAndWord {
public:
	int howManyPairs(vector <string>);
};

//set<pair<int, int>> s;
int FoxAndWord::howManyPairs(vector <string> words) {
    int count = 0;
	for(int i = 0; i < words.size(); i++) {
        string ss = words[i] + words[i];
        for(int j = i+1; j < words.size(); j++) {
            if( ss.find(words[j] != std::npos) count++;
        }
	}
	return count;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
