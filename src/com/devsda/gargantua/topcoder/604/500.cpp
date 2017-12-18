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

using namespace std;
/*
class PowerOfThreeEasy {
public:
	string ableToGet(int, int);
};

long long int steps[1000];
int i = 0;
void fill() {
    //int i = 0;
    steps[0] = 1;
    while(steps[i] <= 1000000000 ) {
        i++;
        steps[i] = 3*steps[i-1];
    }
}

void isPossible(int sx, int sy, int dx, int dy, int step) {
    if(step > 19) return false;
    if(sx > dx || sy > dy) return false;
    if(sx == dx && sy == dy) return true;
    return isPossible(sx+steps[step], sy, dx, dy, step+1) || isPossible(sx, sy+step[step], dx, dy, step+1);
}

string PowerOfThreeEasy::ableToGet(int x, int y) {
	fill();
	if( isPossible(0, 0, x, y, 0) ) return "possible";
	return "impossible"
}
*/
int i = 2000000000L;
main() {
    //fill();
    //cout << i+1 << "  " << steps[i+1] << endl;
    cout << i << endl;
    return 0;
}
