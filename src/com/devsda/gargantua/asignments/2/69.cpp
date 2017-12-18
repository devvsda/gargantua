#include<iostream>
#include<cmath>

using namespace std;

void swap(char *a, char *b) { *a = *a^*b; *b = *a^*b; *a = *a^*b; }

void reverse ( char* str, int low, int high )
{
    while ( low < high )
    {
        swap( &str[low], &str[high] );
        ++low;
        --high;
    }
}

void cycleLeaderAlgo(char *str, int shift, int len) {
    int j;
    char temp;
    for( int  i = 1; i < len; i *= 3) {
        j = i;
        temp = str[j+shift];
        do{
            if(j < len/2) j *= 2;
            else j = (2*j -len +1);//if(j%2) j = j/2 + len/2;
            //else j = j/2;
            swap(&temp, &str[j+shift]);
        }while(i != j);
    }
}
void shiftDigitToRightSide(char *str, int size) {
    int lenRemaining = size;
    int shift = 0;
    int k = 0;

    while(lenRemaining) {
        k = 0;
        while( (pow(3, (double)(k)) + 1) <= lenRemaining) k++;
        k = pow(3, (double)(k-1)) + 1;

        do {
            cycleLeaderAlgo(str, shift, k);

            //reverse(str, shift/2, shift-1);
            //reverse(str, shift, shift+ (k/2) -1);
            //reverse(str, shift/2, shift+(k/2)-1);
            shift += k;
            lenRemaining -= k;
        }while(k <= lenRemaining);

    }

}

main() {
    char str[] = "abcdefg1234567";   //"a1b2c3d4e5f6g7";
    int size = sizeof(str)/sizeof(str[0]);
    shiftDigitToRightSide(str, size-1);
    printf("\nAnswer is : %s\n", str);
    return 0;
}
