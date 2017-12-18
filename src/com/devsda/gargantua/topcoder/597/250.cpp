#include<iostream>
#include<string>
#include<vector>

using namespace std;

class LittleElephantAndDouble {
    public :
        string getAnswer(vector<int> A) {
            while(A[0]%2 == 0) A[0] /= 2;
            for(int i = 1; i < A.size(); i++) {
                while(A[i]%2 == 0) A[i] /= 2;
                if(A[i] != A[i-1]) return "NO";
            }
            return "YES";
        }
};

main() {

}
