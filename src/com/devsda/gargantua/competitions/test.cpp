#include<iostream>
#include<string>
#include<stdio.h>
#include<time.h>

using namespace std;

string third(string input) {
    return input;
}

string second(string input) {
    return third(input);
}

string first(string input){
    return second(input);
}

main() {
    string input;
    clock_t begin, end;
    cin >> input;
    begin = clock();
    cout << first(input);
    end = clock();
    cout << endl << (double)(end-begin)/CLOCKS_PER_SEC << endl;
    return 0;
}
