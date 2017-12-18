#include<iostream>

using namespace std;

void swap(int *a, int *b) { *a = *a^*b; *b = *a^*b; *a = *a^*b; }

int removeDuplicate(string str) {
    bool visited[256];
    memset(visited, false, sizeof(bool)*256);
    int j = -1;
    for(int i = 0; i < str.size(); i++) {
        if( !visited[str[i]] ) {
            swap( str[++j], str[i]);
        }
        visited[str[i]] = true;
    }

    for(int i = 0; i <= j; i++) cout << str[i];
    return j;
}

main() {
    string str = "geeksforgeeks";
    int size = removeDuplicate(str);

    return 0;
}
