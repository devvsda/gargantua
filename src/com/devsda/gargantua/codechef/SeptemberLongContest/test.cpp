#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

#define START 0
#define END 53

int primeNumber[] = {2,	3,	5,	7,	11,	13,	17,	19,	23,
29,	31,	37,	41,	43,	47,	53,	59,	61,	67,
71,	73,	79,	83,	89,	97,	101,	103,	107,	109,
113,	127,	131,	137,	139,	149,	151,	157,	163,	167,
173,	179,	181,	191,	193,	197,	199,	211,	223,	227,
229,	233,	239, 241, 251};

int findFloorIndex(int key, int start, int end) {
    if(start > end) return -1;
    if( primeNumber[end] <= key ) return end;
    if(primeNumber[start] > key) return -1;

    int mid = start + (end - start)/2;

    if( ( (mid == 0) ||  (primeNumber[mid-1] <= key) )&& (primeNumber[mid] > key) )  return (mid-1);
    if( (primeNumber[mid] <= key) && ( (mid == end) || (primeNumber[mid+1] > key) ) ) return mid;

    if(primeNumber[mid] > key) return findFloorIndex(key, start, mid-1);
    else return findFloorIndex(key, mid, end);
}

main() {
    cout << findFloorIndex(2, START, END);
}
