#include<iostream>

using namespace std;

void findLPS(char *str, int *lps, int size) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < size) {
        if(str[i] == str[len]) {
            lps[i++] = ++len;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else lps[i++] = 0;
        }
    }
}

void KMP(char *txt, char *pat) {
    int txtSize = strlen(txt);
    int patSize = strlen(pat);

    int i = 0;
    int j = 0;

    while(i < txtSize) {
        if(txt[i] == pat[j]) {
            i++;
            j++;

            if(j == patSize) {
                printf("FOUNDED!!!!!!");
            }
        }
        else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
}
main() {
    char str[] = "ABABAABAB";
    int size = sizeof(str)/sizeof(str[0]);
    int *lps = (int *)malloc(sizeof(int)*size);
    findLPS(str, lps, size);
    for(int i = 0; i < size-1; i++) cout << lps[i] << "  ";
    cout << endl;
    return 0;
}
