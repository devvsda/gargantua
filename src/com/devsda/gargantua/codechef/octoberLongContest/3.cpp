#include<stdio.h>
#include<algorithm>

using namespace std;

int workingArray[50];

main() {
    int T;
    int n;
    int val;
    int sum = 0;
    int answer = 0;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &n);
        sum = 0;
        answer = 0;

        for(int i = 0; i < n; i++) scanf("%d", &workingArray[i]);
        for(int i = 0; i < n; i++) {
            scanf("%d", &val);
            workingArray[i] = val - workingArray[i];
            sum += workingArray[i];
        }
        if(n == 1) {
            if(workingArray[0] <= 0) printf("%d\n", -workingArray[0] );
            else printf("-1\n");
        }
        else if(n == 2){
            if(workingArray[0] + workingArray[1] == 0) {
                printf("%d\n", max(workingArray[0], workingArray[1]));
            }
            else {
                printf("-1\n");
            }
        }
        else {
            sum = sum/(n-2);
            for(int i = 0; i < n; i++) {
                if( (sum - workingArray[i])%2 == 0 ) {
                    workingArray[i] = (sum - workingArray[i])/2;
                    answer += workingArray[i];
                    if(workingArray[i] < 0) {
                        answer = -1;
                        break;
                    }
                }
                else { answer = -1; break; }
            }

            printf("%d\n", answer);
        }
    }
    return 0;
}
