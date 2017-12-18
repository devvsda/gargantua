#include<iostream>
#include<map>
#include<string>

using namespace std;

main() {
    int T;
    int N;
    string name;
    long long int score;

    cin >> T;

    while(T--) {
        cin >> N;
        map<long long int, string> m;
        for(int i = 0; i < N; i++) {
            cin >> name >> score;
            if(m.count(score) > 0) m.find(score)->second = "DUPLICATE";
            else m.insert( pair<long long int, string>(score, name) );
        }
        map<long long int, string> :: iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            if(it->second == "DUPLICATE") continue;
            break;
        }
        if(it != m.end()) cout << it->second << endl;
        else cout << "Nobody wins.\n";
    }
    return 0;
}
