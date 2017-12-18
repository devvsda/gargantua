#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

bool isValid(int A, int B) {
    while(A != 0) {
        if( ((A & 1) == 1) && ((B & 1) == 0) ) return false;
        A >>= 1;
        B >>= 1;
    }
    return true;
}

class ORSolitaireDiv2 {
    public :
        int getMinimum(vector <int> numbers, int goal) {
            int i = 0;
            int count = 0;
            int answer = INT_MAX;
            int num;
            int goalTemp = goal;

            while(goal != 0) {
                count = 0;
                num = (goal & (1) );
                if(num == 1) {
                    for(int j = 0; j < numbers.size(); j++) {
                        if( (numbers[j] & (1 << i)) && isValid(numbers[j], goalTemp)) count++;
                    }
                    answer = min(answer, count);
                    if(answer == 0) return answer;
                }
                goal = goal >> 1;
                i++;
            }
            return answer;
        }
};


main() {
    return 0;
}
