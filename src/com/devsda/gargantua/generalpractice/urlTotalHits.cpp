#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

map< string, pair< int, set<int> > > processedData;

void printMap() {
	map<string, pair<int, set<int> > > :: iterator itr;

	for(itr = processedData.begin(); itr != processedData.end(); itr++) {
		cout << itr->first << " " << itr->second.first << " " << itr->second.second.size() << endl; 
	}
}

void addIntoMap(string link, int userId) {
	if(processedData.count(link)) {
		pair< int, set<int> > value = processedData.find(link)->second;
		value.first++;
		value.second.insert(userId);
		processedData[link] = value;
	} else {
		set<int> usersClickedOnThisLink;
		usersClickedOnThisLink.insert(userId);
		pair< int, set<int> > value = pair< int, set<int> > (1, usersClickedOnThisLink);
		processedData[link] = value;
	}

	//printMap();
}

int main() {
	int N;
	cin >> N;

	string time;
	int userId;
	string link;

	// Input => time userId link
	// For example -> 10/03/2016 3 http://google.com

	for(int i = 0; i < N; i++) {
		cin >> time >> userId >> link;
		addIntoMap(link, userId);
	}

	printMap();

	return 0;
}