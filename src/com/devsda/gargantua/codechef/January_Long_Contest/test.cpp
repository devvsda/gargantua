#include<iostream>
#include<map>
#include<cmath>

using namespace std;



main() {
    //unsigned long long int range = pow(2, sizeof(unsigned long long int)*8);
    //printf("%llu", range);
    unsigned long long int i;
    scanf("%llu", &i); //*10000000000000000000L;
    printf("%llu", (((i-1)%i)*((i-1)%i))%i  );
    /*
    unsigned long long int input = 999999999999999999L;
    unsigned long long int B = 999999999999999999L;
    unsigned long long int C = 10000000000000000000L;
    input = ((input%C)*(B%C))%C;
    printf("%llu", input);
    */
    return 0;
}
