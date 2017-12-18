#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i <= (int)(n); i++)
#define DEBUG if(0)
#define PAUSE system("pause")
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define LAST(a) (int(a.size()) - 1)
#define PN(n)   printf("%d",n)
#define PDN(n)  printf("%lf",n)
#define PLN(n)  printf("%lld",n)
#define PS(n)   printf("%s",n)
#define PL()    printf("\n")
#define PSP()    printf(" ");
#define SN(n)   scanf("%d",&n)
#define SDN(n)  scanf("%lf",&n)
#define SLN(n)  scanf("%lld",&n)
#define SS(n)   scanf("%s",n)
#define i64 long long
#define ff first
#define ss second
#define par pair<int, int>
#define PPP pair<par, par>
#define MAXM 1000000
#define get getchar_unlocked

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const double EPS = 1E-9;
const int INF = 100000000;
//const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535897932384626433832795;
const int MAX = 1005;
int dx[]={ 0, 0, -1, 1, -1, 1,-1, 1};
int dy[]={-1, 1,  0, 0, -1,-1, 1, 1};

long long int states[MAXM];
int strengthFrequency[MAXM];

inline int scan() {
    int n=0,s=1;
    char p = get();
    if(p=='-')  s=-1;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-')
        p = get();
    if(p=='-') s=-1,p = get();
    while(p>='0'&&p<='9'){
        n = (n<< 3) + (n<< 1) + (p - '0');
        p = get();
    }
    return n*s;
}

bool cmp(PPP a, PPP b){
    if(a.ff.ff > b.ff.ff)
        return true;
    else if(a.ff.ff == b.ff.ff && a.ss.ff < b.ss.ff)
        return true;
    else return false;
}


int main() {
    int T;
    int N;
    int iter;
    int a, b, c, d;
    long long int currentStrength;
    long long int captain[2];

    T = scan();

    while(T--) {

        N = scan();
        a = scan();
        b = scan();
        c = scan();
        d = scan();
        for(int i = 0; i < MAXM; i++) states[i] = -1;
        memset( strengthFrequency, 0, sizeof(strengthFrequency) );
        captain[0] = captain[1] = 0;

        currentStrength = d;
        strengthFrequency[currentStrength]++;

        iter = N-1;

        while(iter--) {
            if( states[currentStrength] == -1) {
                states[currentStrength] = ( currentStrength * ( a * currentStrength + b ) + c )%MAXM;
            }
            strengthFrequency[states[currentStrength]]++;
            currentStrength = states[currentStrength];
        }

        iter = 0;

        for(int i = MAXM-1; i >= 0; i--) {
            if( strengthFrequency[i] % 2 ) {
                captain[iter] += i;
                iter = !iter;
            }
        }

        PLN( abs(captain[0] - captain[1]) );
        PL();
    }

    return 0;
}

