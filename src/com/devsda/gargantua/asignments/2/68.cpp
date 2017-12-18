#include<iostream>
#include<cmath>

using namespace std;

bool visited[26];

void swap(char *a, char *b) { *a = *a^*b; *b = *a^*b; *a = *a^*b; }

void shiftSubString(char * str, int start, int size) {
    int newIndex;
    //printf("start : %d end : %d\n", start, start+size-1);

    //printf("\nOriginal String : %s\n", str);
    for(int oldIndex=(start+1); oldIndex < (start+size-1); oldIndex++) {
        int j = oldIndex;
        char temp = str[j];
        if(!visited[j]) {
            do{
                visited[j] = true;
                if(j%2) newIndex = j/2;
                else newIndex = j/2 + (size)/2;
                //visited[newIndex] = true;
                swap(&temp, &str[newIndex]);
                j = newIndex;

            }while(j != oldIndex);
        }
    }
}

 void shiftNumber(char *str, int size) {
     int n = size;
     int k = 0;
     int lenRemaning = size;
     int startIndex  = 0;
     while( (pow((double)3, (double)k) + 1) <= n) k++;
     k = pow(3, (double)(k-1)) + 1;


    memset(visited, false, sizeof(bool)*26);
    while(lenRemaning) {
        cout << "K is : " << k << "LenRemaining : " << lenRemaning << endl;

        do{
            //printf("StartIndex : %d   k : %d   lenRemaining : %d\n", startIndex, k, lenRemaning);
            shiftSubString(str, startIndex, k);
            lenRemaning = lenRemaning - k;
            startIndex += (k);
        }while(k <= lenRemaning);
        if(!lenRemaning) break;
        k = 0;
        while( (pow(3, (double)k) + 1) <= lenRemaning ) k++;
        k = pow(3, (double)(k-1)) + 1;
    }
 }

main() {
    char str[] = "a1b2c3d4e5f6g7";
    int size = sizeof(str)/sizeof(str[0]);
    shiftNumber(str, size-1);
    printf("\nAnswer is : %s\n", str);
    return 0;
}
