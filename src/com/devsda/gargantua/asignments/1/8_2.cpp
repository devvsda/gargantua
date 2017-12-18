#include<iostream>
#include<vector>

using namespace std;

struct point {
    int x;
    int y;
};
vector<struct point *> v_point;

int findPath(int x, int y) {
    struct point *p = new point;
    p->x = x;
    p->y = y;
    v_point.push_back(p);
    if(x == 0 && y == 0) {
        cout << "\n\t" << x << "  " << y;
        return true;
    }
    int success = 0;
    if( x >= 1 ) {
        cout << "\n1... success = " << success << " x =  " << x << "  "  << " y = " << y;
        success = findPath(x-1, y);
        //cout << "\n1.1...success = " << success << " x =  " << x << "  "  << " y = " << y;
    }
    if(y >= 1) {
        cout << "\n2... \t success = " << success << " x =  " << x << "  "  << " y = " << y;
        success = findPath(x, y-1);
        //cout << "\n2.2...\t success = " << success << " x =  " << x << "  "  << " y = " << y;
    }
    if(!success){
        cout << "\n3...\t\t success = " << success << " x =  " << x << "  "  << " y = " << y;
        v_point.pop_back();
        cout << "\n3.3...\t\t success = " << success << " x =  " << x << "  "  << " y = " << y;
    }
    return success;
}

main() {
    cout << endl << findPath(2,2);
    return 0;
}
