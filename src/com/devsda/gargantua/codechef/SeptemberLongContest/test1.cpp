#include<iostream>
#include<cmath>

using namespace std;

int arr[100];
main() {
    int count = 0;
    for(int i = 1; i < 100; i++) {
        //count = i;
        count = 0;
        for(int j = 1; j <= sqrt(i); j++) {
            count += i/j;
            //count += ((i/j)-1);
        }
        arr[i] = count;
    }


    for(int i = 1; i < 100; i++) {
        cout << i << "---->" << arr[i] << endl;
    }

    return 0;
}
