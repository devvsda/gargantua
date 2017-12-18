#include<iostream>

using namespace std;

void nextGreaterElement(int arr[], int size) {
    stack<int> s;
    s.push(arr[0]);
    int next;
    int element;

    for(int i = 1; i < size; i++) {
        next = arr[i];
        if(s.empty()) break;
        element = s.pop();

        while(element < next) {
            printf("%d %d\n", element , next);
            if( !s.empty() ) element = s.pop();
        }

        if(next < element) {
            s.push(element);
        }

        s.push(next);
    }

    while(!s.empty()) {
        printf(s.top(), -1);
        s.pop();
    }
}

main() {
    return 0;
}
