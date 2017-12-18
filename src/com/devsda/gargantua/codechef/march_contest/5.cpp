#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std;

#define MAX 20

int count_bits(long long int n) {
  int c; // c accumulates the total bits set in v
  for (c = 0; n; c++)
    n &= n - 1; // clear the least significant bit set
  return c;
}

vector<int> v[MAX];

main() {
    int N, M, K;
    long long int iter, temp;
    int pos, flag;
    int value;
    int maxOffers = INT_MIN;
    int cnt;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> K;
        for(int j = 0; j < K; j++) {
            cin >> value;
            v[i].push_back(value);
        }
    }

    iter = ( 1 << M ) - 1;

    while(iter >= 0) {
        set<int> st;
        cnt = count_bits(iter);
        if(cnt <= maxOffers) { --iter; continue; }
        temp = iter;

        pos = 0;
        flag = 0;
        while(temp) {
            if(temp&1) {
                for(int i = 0; i < v[pos].size(); i++) {
                    if(st.count(v[pos][i]) ) { flag = 1; break; }
                    st.insert(v[pos][i]);
                }
            }
            if(flag) break;
            pos++;
            temp = temp >> 1;
        }

        if(!flag) maxOffers = max(maxOffers, cnt);
        --iter;
    }

    cout << maxOffers << endl;

    return 0;
}
