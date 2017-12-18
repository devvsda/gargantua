#include<iostream>

using namespace std;

double probability_of_survival(int n, int m, int x, int y, int jumps) {
    int success = 0;
    int failure = 0;
    probability_of_survival_utility_func(n, m, x, y, 0, jumps, &sucess, &failure);
    return (double)((success)/(failure+success));
}

void probability_of_survival_utility_func(int n, int m, int x, int y, int jump_made, int jumps, int *success, int *failure) {
    if(x > m || x < 0 || y > n || y < 0) { (*failure)++; return;}
    if(jump_made == jumps) { (*success)++; return;}
    probability_of_survival_utility_func(n, m, x+1, y, jump_made++, jumps, success, failure);
    probability_of_survival_utility_func(n, m, x, y+1, jump_made++, jumps, success, failure);
    probability_of_survival_utility_func(n, m, x-1, y, jump_made++, jumps, success, failure);
    probability_of_survival_utility_func(n, m, x, y-1, jump_made++, jumps, success, failure);
}
