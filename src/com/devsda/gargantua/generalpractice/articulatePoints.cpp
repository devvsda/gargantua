// Writing only main method.
#include<iostream>

using namespace std;


int time = 0;

vector< vector<int> > adjacencyList(1000);

void printArticulePoints(int node, bool visited[], int entryTime[], int earliestDescendent[], int parent[] ) {
	
	int childern = 0;

	time++;
	entryPoint[node] = earliestDescendent[node] = time;
	visited[node] = true;

	for(int i = 0; i < adjacencyList[node].size(); i++) {

	}
}

int main() {
	return 0;
}