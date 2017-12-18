#include<iostream>

using namespace std;

void ApplyPermutation( int *permutation , int *A, int n) {
    for (int i = 0; i < n; ++i) {
    if (permutation[i] > 0) {
        int j = i;
        int tmp = A[ i ] ;
        do {
            int k = permutation[j];
            int swap_var = A[k];
            A[k] = tmp;
            tmp = swap_var;
            //I Mark j as vis it ed .
            permutation [j] *= -1; //I I sets the sign
            j = k;
        } while (j != i);
    }
    }

for (int i = 0; i < n; ++ i) {
    permutation[i] *= 1;
}
}
main() {
    int per[] = {3, 1, 2, 4};
    int A[] = {1, 2, 3, 4};
    ApplyPermutation(per, A, 4);
    return 0;
}
