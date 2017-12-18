#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

double getMinutes(string s) {
    double hrs = (double)( (s[0]-48)*10 + (s[1]-48) );
    double mins = (double)( (s[3]-48)*10 + (s[4]-48) );
    return ( (hrs*60) + mins );
}

main() {
    int T;
    cin >> T;

    while(T--) {
        string t1, t2;
        double mins;
        cin >> t1 >> t2 >> mins;
        double t1m = getMinutes(t1);
        double t2m = getMinutes(t2);
        double diff = t1m - t2m;
        if( (2*mins) <= diff)  {
            cout << setprecision(1) << fixed << (diff + mins) << " " << setprecision(1) << fixed << diff << "\n"; // << endl;
            //cout << (double)(diff + mins) << " "  << diff << "\n"; // << endl;
        }
        else if(mins <= diff){
            cout << setprecision(1) << fixed << (diff + mins) << " " << setprecision(1) << fixed << ( diff + ( (2*mins) - diff)/2 ) << "\n";// << endl;
            //cout << (double)(diff + mins) << " " << ( diff + ( (2*mins) - diff)/2 ) << "\n";// << endl;
        }
        else {
            cout << setprecision(1) << fixed << (diff + mins) << " ";
            cout << setprecision(1) << fixed << ((diff)/2 + (mins)) << endl;
            //cout <<  (diff + mins) << " ";
            //cout <<  (double)((diff)/2 + (mins)) << endl;
        }
    }

    return 0;
}
