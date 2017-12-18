#include<iostream>
#include<vector>

using namespace std;

int bits[1024];

bool updateBit(int number) {
    int integerIndex = number / (32);
    int bitsToSet = 1 << (number % 32);
    if(bitsToSet & bits[integerIndex]) return true;
    else bits[integerIndex] = bits[integerIndex] | bitsToSet;
    return false;
}

void printDuplicate(vector<int> numbers) {
    
    for(int i = 0; i < numbers.size(); i++) {
        if(updateBit(numbers[i])) {
            cout << numbers[i] << " is duplicate \n";
        }
    } 
}

int main() {

	int N;
	int value;

	vector<int> v;

	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> value;
		v.push_back(value);
	}

	printDuplicate(v);
	return 0;
}