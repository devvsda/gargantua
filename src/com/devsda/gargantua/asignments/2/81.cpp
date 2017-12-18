#include<iostream>

using namespace std;

int divide(int x, int y) {
    int den = y, num = x;
    int answer = 0;
    while(num > den) {
        int iter = 1;
        int count = 0;
        while(iter < num ) { count++; iter *= den; }
        answer += count-1;
        num = num - (iter/den);
        cout << answer << " " << num << "  " << den << endl;
    }
    return answer;
}

main() {
    int x, y;
    cin >> x >> y;
    cout << divide(x, y);
    return 0;
}
