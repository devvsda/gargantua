#include<iostream>
#include<cstdio>

using namespace std;

void func(char *s) {
    if(*s == NULL) return;
    func(s+1);
    func(s+1);
    printf("%s", s);
}

main() {
    func("xyz");
    printf("\n");
    return 0;
}
