#include<iostream>
#include<string>

using namespace std;

main() {
    string input;
    string output= "";
    int stampcost;
    int pushcost;
    int first_cost;
    int second_cost = 0;
    cin >> input >> stampcost >> pushcost;

    for(int i = 1; ; i++) {
        first_cost = i*stampcost;
        for(int j = 0; j < input.size() - i; ) {
            if(i != 1) {
                if(input[j] == '*') {

                }
            }
        }
    }

    return 0;
}
