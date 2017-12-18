#include<iostream>

using namespace std;

#define MAX 2000009

long long int input[MAX/2];
long long int segmentTree[MAX];

int buildSegmentTree( int startInput, int endInput, int startSegment ) {
    if( startInput == endInput ) {
        segmentTree[startSegment] = input[startInput];
        return segmentTree[startSegment];
    }

    int mid = startInput + (endInput - startInput)/2;

    segmentTree[startSegment] = buildSegmentTree( startInput, mid, startSegment*2 + 1) +  buildSegmentTree( mid+1, endInput, startSegment*2 + 2);
    return segmentTree[startSegment];
}


void degradeKey(int startIndex, int endIndex, int index, int startSegment, int val) {
    if(startIndex > endIndex) return;
    if(startIndex == endIndex) {
        segmentTree[startSegment] -= val;
        return;
    }
    int mid = startIndex + (endIndex - startIndex)/2;
    if(index <= mid) degradeKey(startIndex, mid, index, (startSegment*2 + 1), val);
    else degradeKey(mid+1, endIndex, index, (startSegment*2 + 2), val);
    segmentTree[startSegment] -= val;
}

void upgradeKey(int startIndex, int endIndex, int index, int startSegment, int val) {
    if(startIndex > endIndex) return;
    if(startIndex == endIndex) {
        segmentTree[startSegment] += val;
        return;
    }
    int mid = startIndex + (endIndex - startIndex)/2;
    if(index <= mid) upgradeKey(startIndex, mid, index, startSegment*2 + 1, val);
    else upgradeKey(mid+1, endIndex, index, startSegment*2 + 2, val);
    segmentTree[startSegment] += val;
}


long long int sumQuery( int startIndex, int endIndex, int startQuery, int endQuery, int startSegment ) {
    if(startQuery > endIndex || endQuery < startIndex) return 0;
    if(startQuery <= startIndex && endQuery >= endIndex) return (long long int)segmentTree[startSegment];
    int mid = startIndex + (endIndex - startIndex)/2;
    return (long long int)sumQuery(startIndex, mid, startQuery, endQuery, startSegment*2 + 1) + (long long int)sumQuery(mid+1, endIndex, startQuery, endQuery, startSegment*2 + 2);
}

main() {
    int N;
    int Q;
    int x, y;

    cin >> N >> Q;

    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    buildSegmentTree(0, N-1, 0);

    for(int i = 0; i < Q; i++ ) {
        char action;
        cin >> action;

        switch(action) {
            case 'S' :
                cin >> x >> y;
                cout << sumQuery(0, N-1, x, y, 0) << endl;
                break;
            case 'G' :
                cin >> x >> y;
                upgradeKey(0, N-1, x, 0, y);
                break;
            case 'T' :
                cin >> x >> y;
                degradeKey(0, N-1, x, 0, y);
                break;
        };
    }
    return 0;
}
