#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;
/*
class BinPackingEasy {
    public :

};
*/

int minBins(vector <int> item) {
            int setItems = 0;
            int index;
            int done[item.size()];
            memset(done, 0, sizeof(done));
            int i, j;
            sort(item.begin(), item.end());
            for(i = (item.size()-1); i >= 0; i--) {
                if(done[i]) continue;
                index = -1;
                for(j = 0; j < i; j++) {
                    if( !done[j] && (item[i] + item[j] <= 300) ) {
                         index = j;
                    }
                }
                if(index != -1) {
                    done[i] = done[index] = 1;
                    setItems += 2;
                }
                cout << setItems << endl;
            }
            return ( (setItems/2) + (item.size()-setItems) );
        }


main() {
    int a[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
    vector<int> v;
    v.push_back(123);
    v.push_back(145);
    v.push_back(167);
    v.push_back(213);
    v.push_back(245);
    v.push_back(267);
    v.push_back(289);
    v.push_back(132);
    v.push_back(154);
    v.push_back(176);
    v.push_back(198);
    cout << "answer  : " << minBins(v) << endl;
    return 0;
}

