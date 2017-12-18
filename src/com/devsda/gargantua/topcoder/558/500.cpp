#include<iostream>
#include<string>

#define oo 1000000000

using namespace std;

int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    int N = desiredColor.size();
    int a[N];
    int cost[N+1];
    int offset;

	for (int i = 0; i < N; i++) {
		char c = desiredColor[i];
		if (c == '*') a[i] = 7;
		if (c == 'R') a[i] = 1;
		if (c == 'G') a[i] = 2;
		if (c == 'B') a[i] = 4;
	}
    int answer = oo;

    for(int length = 1; length <= N; length++) {

        cost[0] = 0;
        for(int i = 1; i <= N; i++) cost[i] = oo;

        for( int start = 0; start < N; start++ ) {
            //if(cost[i] == oo) continue;
            int color = 7;
            for( int last = start; last < N; last++ ) {
                color &= a[last];
                if( color == 0 ) break;
                offset = last - start + 1;
                if(offset < length) continue;
                if(cost[start] != oo) cost[last+1] = min( cost[last+1], cost[start] + ( (offset + length - 1)/length )*pushCost );
            }
        }
        cout << "\nLength : " << length << endl;
        for(int i = 0; i <= N; i++) cout << cost[i] << "  ";
        cout << "  COST{N} : " << cost[N] << endl;
        if(cost[N] != oo) answer = min(answer, (length*stampCost) + cost[N] );
    }
    return answer;
}

main() {
    cout << getMinimumCost("RRGGBB", 1, 1);
    return 0;
}
