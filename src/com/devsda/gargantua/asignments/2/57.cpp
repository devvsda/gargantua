#include<iostream>
#include<string>

using namespace std;

/*bool handleStarWildCard(string s1, int i, string s2, int j) {

}*/

bool isSimilar(string s1, int i, string s2, int j) {
    if(i == s1.size() && j == s2.size()) return true;
    if(i != s1.size() && j == s2.size()) {
        if(s1[i] == '*' && i == (s1.size() - 1) ) return true;
        return false;
    }
    if(i == s1.size() && j != s2.size()){
        if(s2[j] == '*' && j == (s2.size() - 1) ) return true;
        return false;
    }

    if(s1[i] == '*') return isSimilar(s1, i+1, s2, j) || isSimilar(s1, i, s2, j+1);
    else if(s2[j] == '*') return isSimilar(s1, i, s2, j+1) || isSimilar(s1, i+1, s2, j);
    else if(s1[i] == '?' || s2[j] == '?') return isSimilar(s1, i+1, s2, j+1);
    else if(s1[i] == s2[j]) return isSimilar(s1, i+1, s2, j+1);
    return false;
}

main() {
    cout << isSimilar("g*k*", 0, "geeks", 0);
    return 0;
}
