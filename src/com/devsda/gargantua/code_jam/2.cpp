#include<iostream>

using namespace std;

main() {
    //freopen("B-large.in", "r", stdin);
    //freopen("outputB2.txt", "w", stdout);

    int T;
    double C, F, X;
    double initialRate;
    double answer;

    cin >> T;

    for(int t = 1; t <= T; t++) {
        answer = 0.0;
        initialRate = 2.0;
        cin >> C >> F >> X;

        while( (X/initialRate) > ( (C/initialRate) + (X/(initialRate + F) ) ) ) {
            answer += (double)(C/initialRate);
            initialRate += F;
        }
        answer += (double)(X/initialRate);
        //cout << answer << endl;
        cout.precision(7);
        cout << "Case #" << t << ": " << fixed << answer << endl;
    }
    return 0;
}
