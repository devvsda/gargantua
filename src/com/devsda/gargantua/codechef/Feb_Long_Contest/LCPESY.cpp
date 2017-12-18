#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

main() {
    string s1, s2;
    int t;
    int i, j;
    int count;
    cin >> t;
    while(t--) {
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        i = j = 0;
        count = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] < s2[j]) {
                i++;
            }
            else if(s1[i] > s2[j]) {
                j++;
            }
            else {
                i++;
                j++;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
