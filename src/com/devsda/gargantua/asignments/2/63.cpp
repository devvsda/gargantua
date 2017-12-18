#include<iostream>

using namespace std;

void print(char answer[]) {
    for(int i = 0; i < 6; i++) {
        cout << answer[i];
    }
    cout << endl;
}
void printAnagram(string s1, int i, int M, string s2, int j, int N, char answer[], int index) {
    if(i == M && j == N) {
        print(answer);// << endl;
        return;
    }
    if(i < M) {
        answer[index] = s1[i];
        printAnagram(s1, i+1, M, s2, j, N, answer, index+1);
    }
    if(j < N) {
        answer[index] = s2[j];
        printAnagram(s1, i, M, s2, j+1, N, answer, index+1);
    }
}

main() {
    char answer[6];
    printAnagram("XYZ", 0, 3, "ABC", 0, 3,  answer, 0);
    return 0;
}
