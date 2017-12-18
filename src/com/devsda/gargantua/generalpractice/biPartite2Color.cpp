#include<iostream>

using namespace std;

#define RED 0
#define BLUE 1
#define NOCOLOR 2

int colors[100];

vector< vector<int> > adjacencyList(100);

queue<int> queue;

int isBiPartite(int rootNode, int color) {
	
	colors[rootNode] = color;
	queue.enqueue(rootNode);

	while(!queue.empty()) {
		int currentNode = queue.dequeue();
		for(int i = 0; i < adjacencyList[rootNode].size(); i++) {
			int childNode = adjacencyList[rootNode][i];
			if(colors[childNode] == NOCOLOR) {
				colors[childNode] = ~colors[rootNode];
				queue.enqueue(childNode);
			} else if(colors[childNode] == colors[rootNode]) {
				return -1;
			}
		}
	}

	return 1;
}

int main() {

}