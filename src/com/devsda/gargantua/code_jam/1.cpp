#include<stdio.h>
#include<string>

using namespace std;

int isPresent[17];

main() {
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    int answer1, answer2;
    int value, cnt, answerValue;
    scanf("%d", &T);


    for(int t = 1; t <= T; t++) {
        memset(isPresent, 0, sizeof(isPresent));
        cnt = 0;
        scanf("%d", &answer1);
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                scanf("%d", &value);
                if(i == answer1) isPresent[value] = 1;
            }
        }
        scanf("%d", &answer2);
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                scanf("%d", &value);
                if(i == answer2) {
                    if( isPresent[value] ) { cnt++; answerValue = value; }
                }
            }
        }

        if(cnt == 0) printf("Case #%d: Volunteer cheated!\n", t);
        else if(cnt == 1) printf("Case #%d: %d\n", t, answerValue);
        else printf("Case #%d: Bad magician!\n", t);
    }
    return 0;
}
