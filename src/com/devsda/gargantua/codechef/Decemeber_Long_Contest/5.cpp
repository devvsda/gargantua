#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct compare {
    bool operator()( const pair<char, int> &left, const pair<char, int> &right ) {
        return ( ( left.second < right.second ) || ( (left.second == right.second)&&(left.first < right.first) ) );
    }
};

char chr[256];

 main() {
    int T;
    cin >> T;
    while(T--) {
        int i = 0;
        vector< pair<char, int> > v;
        int count;
        string frequencySeq, cypher, cypherTemp;
        fflush(stdin);
        cin >> frequencySeq;
        fflush(stdin);
        getline(cin, cypher);
        fflush(stdin);

        cypherTemp = cypher;
        cypher.erase(cypher.begin() + (cypher.size() - 1) );
        sort(cypher.begin(), cypher.end());
        i = 0;
        //while(i < cypher.size() && cypher[i] != ' ') i++;
        //while(i < cypher.size() && cypher[i] == ' ') cypher.erase(i, 1);
        while(cypher[i] == ' ') cypher.erase(cypher.begin() + 0);

        i = 0;
        while(i < (cypher.size()-1) ) {
            count = 1;
            while( (i < cypher.size()-1) && (cypher[i] == cypher[i+1]) ) {
                count++;
                i++;
            }
            v.push_back( pair<char, int>(cypher[i], count) );
            i++;
        }
        if( i > 0 && (cypher[i] != cypher[i-1]) ) v.push_back( pair<char, int>(cypher[i], 1) );
        sort(v.begin(), v.end(), compare() );

        int j = frequencySeq.size()-1;
        for(i = v.size()-1; i >= 0; ) {
            chr[ v[i--].first ] = frequencySeq[j--];
        }

        for(i = 0; i < cypherTemp.size()-1; i++) {
            if(cypherTemp[i] == ' ') cout << ' ';
            else if(cypherTemp[i] >= 65 && cypherTemp[i] <= 90) cout << (char)('A' + chr[cypherTemp[i]] - 'a');
            else cout << chr[cypherTemp[i]];
        }
        cout << "!\n";
    }
    return 0;
 }
