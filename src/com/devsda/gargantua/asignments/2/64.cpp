#include<iostream>

using namespace std;

void printPermutationRecur(char *s1, char *answer, int length, int index) {

    for(int i = 0; i <= length; i++) {
        answer[index] = s1[i];
        if(index == (length)) {
            printf("%s\n", answer);
        }
        else
        printPermutationRecur(s1, answer, length, index+1);
    }
}

void printPermutation(char *s1, int length) {
    char *answer = (char *)malloc(sizeof(char)*(length+1));
    answer[length] = '\0';
    printPermutationRecur(s1, answer, length-1, 0);
}

main() {
    char *s1 = "XXY";
    printPermutation(s1, 3);
    return 0;
}
