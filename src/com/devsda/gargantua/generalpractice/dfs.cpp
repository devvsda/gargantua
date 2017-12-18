#include<iostream>
#include<vector>

using namespace std;

#define INFINITY 1000
#define NO_PARENT 1000

#define NOT_PROCESSED 0
#define PROCESSING 1
#define PROCESSED 2

struct graphNode {
	int index;
	int color;
	int parent;
};

graphNode nodes[100];
vector< vector<int> > links(100);

void fillNode(int index, int value) {
	nodes[index].index = value;
	nodes[index].color = NOT_PROCESSED;
	nodes[index].parent = NO_PARENT;
}

void printNode(int index) {
	cout << "GraphNode info of index : " << nodes[index].index << " " << ", parent : " <<  nodes[index].parent << endl;
}

void printLinks(int N) {
	for(int i = 1; i <= N; i++) {
		cout << "For node : " << i << ", there are links - " << endl;
		for(int j = 0; j < links[i].size(); j++) {
			cout << links[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int startNode) {

	nodes[startNode].color = PROCESSING;

	for(int neighbours = 0; neighbours < links[startNode].size(); neighbours++) {
		if(nodes[links[startNode][neighbours]].color == NOT_PROCESSED) {
			nodes[links[startNode][neighbours]].parent = startNode;
			dfs(links[startNode][neighbours]);
		}
	}

	nodes[startNode].color = PROCESSED;
}

void printNodes(int N) {
	for(int i = 1; i <= N; i++) {
		printNode(i);
	}
}

int main() {
	int numberOfNodes, numberOfEdges;
	int sourceNode, destNode;
	cin >> numberOfNodes >> numberOfEdges;

	for(int i = 1; i <= numberOfNodes; i++ ) {
		fillNode(i, i);
	}

	for(int i = 0; i < numberOfEdges; i++) {
		cin >> sourceNode >> destNode;
		links[sourceNode].push_back(destNode);
	}

	printLinks(numberOfNodes);

	dfs(1);

	printNodes(numberOfNodes);

	return 0;
}