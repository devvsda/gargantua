#include<iostream>

using namespace std;

void func(int input[], bool best_visited[], bool stack_visited[], int *min_sum, int current_sum, int n, int sum, int current_index, int no_of_selected_item) {
    if(current_index == n) return;
    if(  (n - current_index) < ( (n/2) - no_of_selected_item) ) return;

    func(input, best_visited, stack_visited, n, sum, current_index+1, no_of_selected_item);

    current_sum += input[current_index];
    stack_visited[current_index] = true;

    if( n/2 == no_of_selected_item) {
        if( *min_sum > (sum/2) - current_sum ) {
            *min_sum = (sum/2) - current_sum;

            for(int i = 0; i < n; i++) {
                stack_visited[i] = stack_visited[i];
            }
        }
    }

    else {
        func(input, best_visited, stack_visited, n, sum, current_index + 1, no_of_selected_item + 1);
    }
    stack_visited[current_index] = false;
}
main() {
    return 0;
}
