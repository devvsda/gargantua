#include<iostream>

#define OUT 1
#define IN 0

using namespace std;

int countWords(string input) {
    int currentState = OUT;
    int count = 0;
    int i = 0;

    while(i++ != input.size()) {
        if(input[i] == ' ' || input[i] ==  '\n' || input[i] == '\t') currentState = OUT;
        else if(currentState == OUT){
            currentState = IN;
            count++;
        }
    }

    return count;
}

main() {
    cout << countWords("jbikb  jkwdnvo      wkldjnwd");
    return 0;
}
