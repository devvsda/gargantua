#include<iostream>

using namespace std;

void ball_distribution(int val, int size, int t, int A[])
{
    int count=0;
    int B[10004];

    if( size == 1 ){
        cout << A[0] << endl;
    }

    else{
        for(int i=0; i < size; i += t ){
            A[i]=0;
        }

    for( int i = 0; i < size; i++ ){
        if(A[i]){
            B[count++] = A[i];
        }
    }

    ball_distribution(val, count, ++t, B );
    }
}


main()
{
    int test_cases;
    int val;
    int A[10004];
    cin >> test_cases;

    while(test_cases){
        cin >> val;

        for( int i=0; i < val; i++ ){
            A[i]=i+1;
        }

        ball_distribution(val, val, 2, A);
        test_cases--;
    }

    return 0;
}
