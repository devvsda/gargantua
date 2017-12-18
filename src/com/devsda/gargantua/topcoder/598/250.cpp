#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;
/*
class ErasingCharacters {
public:

};
*/

    string simulate(string s){
        bool move = false;
        int i;
        do {
            move = false;
            for(i = 0; (i < s.size()-1); i++) {
                if(s[i] == s[i+1]) {
                move = true;
                break;
                }
            }
            if(move && s.size() == 2) return "";
            else if(move) {
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
            }
        }while(move);
        return s;
    }

main() {
    cout << simulate("cc");
    return 0;
}
