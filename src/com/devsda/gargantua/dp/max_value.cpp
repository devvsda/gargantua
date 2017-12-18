#include<iostream>

using namespace std;

int Max[6][6];
int valid[6][6];
int V[] = {1, 2, 3, 3, 2, 1};
char Op[] = {'+',  '*', '*', '+', '+'};

int maxExpr( int begin , int end) {
    if ( valid[begin][end] )
        return Max[begin][end];
    if ( begin == end ) {
        Max[begin][end] = V[begin];
        valid[begin][end] = true;
        return V[ begin] ;
    }
    if ( begin + 1 == end ) {
        Max[begin] [end] = (Op [begin]== '+') ? V[begin] + V[end] : V[begin] * V[end];
        valid[begin][end] = true;
        return Max[begin] [end];
    }
    int max = INT_MIN;
    int candidateMax = 0;

    for ( int i = begin + 1; i < end; i++ ) {
        int lMax = maxExpr( begin , i);
        cout << "\nbegin  " << begin << " end " << end << endl;
        int rMax = maxExpr( i +1 , end);
        cout << "\n\t\tbegin  " << begin << " end " << end << endl;
        if( Op[i] == '+' ) {
            candidateMax = lMax + rMax;
        }
        else {
            candidateMax = lMax * rMax;
        }

        max = (max < candidateMax) ? candidateMax : max;
    }
        Max [begin] [end] = max;
        valid [begin][ end] = true;
        return max;
}

main() {
    cout << endl << maxExpr(0, 5);
    return 0;
}
