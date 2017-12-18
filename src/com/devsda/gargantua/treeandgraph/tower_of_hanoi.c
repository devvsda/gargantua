#include<stdio.h>

void towerOfHanoi(int n, char s, char a, char d) {
    if(n == 0) { printf("\n\t%d\tchlo khatam hua iska natak", n); return; }
    else {
        printf("\n chl wapis recursion krne %d", n-1);
        towerOfHanoi(n-1, s, d, a);
        printf("\n\t%d  move from %c  to %c", n,s, d);
        towerOfHanoi(n-1, a, s, d);
        printf("\n\t\tniche wle function me hu  %d", n-1);
    }
}

main() {
    towerOfHanoi(4, 's','a' , 'd');
    return 0;
}
