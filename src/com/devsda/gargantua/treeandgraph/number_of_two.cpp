#include<iostream>

using namespace std;

int f(int n) {
    if(n == 0) return 0;

    int power = 1;
    int first;
    int reminder;
    int two_on_first_place = 0;//;// = 0;

    while(10*power < n) power *= 10;
    first = n/power;
    reminder = n%power;

    if( first > 2 ) two_on_first_place = power;
    else if(first == 2) two_on_first_place = reminder + 1;

    int two_on_other_place = first*f(power-1) + f(reminder);
    cout << " return is " << two_on_first_place + two_on_other_place << endl;
    return two_on_first_place + two_on_other_place;

 }

main() {
    int n;
    cin >> n;
    cout << endl << f(n) << endl;
    return 0;
}
