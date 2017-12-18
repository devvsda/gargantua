#include<iostream>
#include<map>
#include<list>

using namespace std;

int timeAfterConversion(string time, int coolingTime) {
    int hrs = 0;
    int mins = 0;

    int hrsFlag = 1;

    for(int i = 0; i < time.size(); i++) {
        if(time[i] == ':') {
            hrsFlag = 0;
            continue;
        }

        if(hrsFlag) {
            hrs = hrs *10 + (time[i] - 48);
        } else {
            mins = mins *10 + (time[i] - 48);
        }
    }

    int finalMins = hrs*60 + mins + coolingTime;
    return finalMins;
}

int main() {
    int N;
    int coolingTime;
    int NA, NB;
    string A, B;
    list< pair<int, int> > numbersOfShipsAtA, numbersOfShipsAtB;

    int numbersOfShipsRequiredAtA = 0;
    int numbersOfShipsRequiredAtB = 0;

    cin >> N;

    while(N--) {
        cin >> coolingTime;
        cin >> NA, NB;

        for(int i =0; i < NA; i++) {
            cin >> A >> B;
            numbersOfShipsAtA.push_back(pair<int, int>(timeAfterConversion(A, 0), 1));
            numbersOfShipsAtB.push_back(pair<int, int>(timeAfterConversion(B, coolingTime), 1));
        }

        for(int i = 0; i < NB; i++) {
            cin >> B >> A;
            numbersOfShipsAtB.push_back(pair<int, int>(timeAfterConversion(B, 0), 2));
            numbersOfShipsAtA.push_back(pair<int, int>(timeAfterConversion(A, coolingTime), 2));
        }

        sort(numbersOfShipsAtA.begin(), numbersOfShipsAtA.end());
        sort(numbersOfShipsAtB.begin(), numbersOfShipsAtB.end());

        cout << numbersOfShipsRequiredAtA << " " << numbersOfShipsRequiredAtB << endl;
    }
}
