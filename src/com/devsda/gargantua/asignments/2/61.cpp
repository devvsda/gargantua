// Rank of a String
#include<iostream>

using namespace std;

int factorial(int num) {
    int answer = 1;
    while(num > 0) {
        answer *= num;
        num--;
    }
    return answer;
}

int findRank(string str) {
    int count = 0;
    int answer = 0;
    int fact = factorial(str.size());
    int j = str.size();

    for(int i = 0; i < str.size(); i++) {
        count = 0;
        fact /= (j--);
        for(int j = i+1; j < str.size(); j++) {
            if(str[j] < str[i]) count++;
        }

        answer = answer + count*(fact);
    }
    return answer;
}

main() {
    cout << findRank("STRING");
    return 0;
}
