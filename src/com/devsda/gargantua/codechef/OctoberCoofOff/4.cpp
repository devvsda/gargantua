#include<iostream>
#include<vector>
#include<string>

#define ONE 1
#define NONE 0

using namespace std;

main() {
    int T;
    int size;
    int state;
    int answer;
    int offset;
    bool cont;
    string input;

    cin >> T;

    while(T--) {
        cin >> size;
        cin >> input;

        state = NONE;
        answer = 0;

        do {
            cont = false;
            if(input[0] == '4') state = ONE;
            offset = 0;
            for( int i = 1; (i < input.size()); ) {
                if( input[i] == '7' && state == ONE ) {
                    answer += (i + offset);
                    offset += 2;
                    input.erase(input.begin() + i-1 );
                    input.erase(input.begin() + i-1 );
                    if(i-2 >= 0 ) { if(input[i-2] != '4') state = NONE; }
                    else state = NONE;
                    cont = true;
                    i--;
                }
                else if(input[i] != '4') { state = NONE; i++;}
                else { state = ONE; i++; }
            }
        }while(cont);
        cout << answer << endl;
    }
    return 0;
}
