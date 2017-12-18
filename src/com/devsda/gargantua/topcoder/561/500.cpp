#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*class ICPCBalloons{
public:
    int minRepaintings(vector<int> balloonCount, string balloonSize, vector<int> maxAccepted);
};*/

int ceilFind( vector<int> v, int start, int end, int target ) {
    if(start > end) return -1;
    if( v[start] >= target ) return start;
    if( v[end] < target ) return -1;
    int mid = start + (end - start)/2;
    if( v[mid] < target ) return ceilFind( v, mid+1, end, target );
    else return ceilFind( v, start, mid, target);
}

int floorFind( vector<int> v, int start, int end, int target ) {
    if(start > end) return -1;
    if( v[end] < target ) return end;
    if( v[start] >= target ) return -1;
    int mid = start + (end - start)/2;
    if( (v[mid] < target) && (mid+1 > end || v[mid+1] >= target) ) return mid;
    if( v[mid] >= target ) return floorFind(v, start, mid, target);
    else return floorFind(v, mid+1, end, target);
}

int ICPCBalloons::minRepaintings(vector<int> balloonCount, string balloonSize, vector<int> maxAccepted) {
    vector<int> vL, vM;
    for(int i = 0; i < balonCount.size(); i++) {
        if(balloonSize[i] == 'L') vL.push_back(balloonCount[i]);
        else vM.push_back(balloonCount[i]);
    }

    sort(vL.begin(), vL.end());
    sort(vM.begin(), vM.end());
    sort(maxAccepted.begin(), maxAccepted.end());

    for(int i = maxAccepted.size() - 1; i >= 0; i--) {
        int availL = ceilFind(v, 0, vL.size()-1, maxAccepted[i]);
        int availM = ceilFind(v, 0, vM.size()-1, maxAccepted[i]);

        if( availL != -1 && availM != -1 ) {
            if( vL[availL] < aM[availM]) {
                vL[availL] -= maxAccepted[i];
                sort(vL.begin(), vL.end());
            }
            else {
                vM[availM] -= maxAccepted[i];
                sort(vM.begin(), vM.end());
            }
        }
        else if( availL != -1 ) {
            vL[availL] -= maxAccepted[i];
            sort(vL.begin(), vL.end());
        }
        else if(availM != -1) {
            vM[availM] -= maxAccepted[i];
            sort(vM.begin(), vM.end());
        }
        else {

        }
    }
}

main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(11);

    cout << floorFind(v, 0, 4, 19);
    return 0;
}
