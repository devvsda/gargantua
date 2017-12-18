stack<int> s;

int findCelebrity(int size {
    for(int i = 0; i < size; i++) {
        s.push(i+1);
    }

    int A = s.pop();
    int B = s.pop();

    while(s.size() != 1) {
        if( isAknowsB(A, B)) {
            A = s.pop();
        }
        else B = s.pop();
    }

    int C = s.pop();

    if( isCknowsA(C, A)) C = A;
    if( isCknowsA(C, B)) C = B;

    for(int i = 0; i < size; i++) {
        if(C != i) {
            if( isCknowsA(C, i)) return -1;
            if( !isCknowsA(i, C)) return -1;
        }
    }
}
