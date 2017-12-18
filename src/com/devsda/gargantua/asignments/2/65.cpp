#include<iostream>

using namespace std;

int maxSubString(string str) {
    int visited[256];
    memset(visited, -1, sizeof(int)*256);

    visited[ str[0] ] = 0;
    int maxSize = 1;
    int currentSize = 1;

    for(int i = 1; i < str.size(); i++) {
        int prevIndex = visited[ str[i]];
        if(prevIndex == -1 || (i - currentSize > prevIndex) ) currentSize++;
        else {
            if(maxSize < currentSize) maxSize = currentSize;
            currentSize = i - prevIndex;

        }
        visited[str[i]] = i;
    }

    if(currentSize > maxSize) maxSize = currentSize;
    return maxSize;
}

main() {
    cout << maxSubString("GEEKSFORGEEKS");
    return 0;
}
