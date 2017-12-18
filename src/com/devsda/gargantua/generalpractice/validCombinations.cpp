#include<iostream>

using namespace std;

char bracketsCombination[100];

void printSequence(int n) {
	for(int i = 0; i <= n; i++) cout << bracketsCombination[i];
	cout << endl;
}

void printAllCombinationsUtil(int openSmallBracketsCount, int closesmallBracketsCount, int smallBracketsCount,
 int openCurlyBracketsCount, int closeCurlyBracketsCount, int curlyBracketCounts,
  int openBigBracketsCount, int closeBigBracketsCount, int bigBracketCounts,
   int index) {
	if(closesmallBracketsCount > openSmallBracketsCount ||
	 closeCurlyBracketsCount > openCurlyBracketsCount ||
	  closeBigBracketsCount > openBigBracketsCount) return;

	if(index == (smallBracketsCount + curlyBracketCounts + bigBracketCounts)*2) {
		printSequence(index);
		return;
	}

	if(openSmallBracketsCount > closesmallBracketsCount) {
		bracketsCombination[index] = ')';
		printAllCombinationsUtil(openSmallBracketsCount, closesmallBracketsCount+1, smallBracketsCount,
		 openCurlyBracketsCount, closeCurlyBracketsCount, curlyBracketCounts,
		  openBigBracketsCount, closeBigBracketsCount, bigBracketCounts,
		   index+1);
	}

	if(openSmallBracketsCount < smallBracketsCount) {
		bracketsCombination[index] = '(';
		printAllCombinationsUtil(openSmallBracketsCount+1, closesmallBracketsCount, smallBracketsCount,
		 openCurlyBracketsCount, closeCurlyBracketsCount, curlyBracketCounts,
		  openBigBracketsCount, closeBigBracketsCount, bigBracketCounts,
		   index+1);
	}

	if(openCurlyBracketsCount > closeCurlyBracketsCount) {
		bracketsCombination[index] = '}';
		printAllCombinationsUtil(openSmallBracketsCount, closesmallBracketsCount, smallBracketsCount,
		 openCurlyBracketsCount, closeCurlyBracketsCount+1, curlyBracketCounts,
		  openBigBracketsCount, closeBigBracketsCount, bigBracketCounts,
		   index+1);
	}

	if(openCurlyBracketsCount < curlyBracketCounts) {
		bracketsCombination[index] = '{';
		printAllCombinationsUtil(openSmallBracketsCount, closesmallBracketsCount, smallBracketsCount,
		 openCurlyBracketsCount+1, closeCurlyBracketsCount, curlyBracketCounts,
		  openBigBracketsCount, closeBigBracketsCount, bigBracketCounts,
		   index+1);
	}

	if(openBigBracketsCount > closeBigBracketsCount) {
		bracketsCombination[index] = ']';
		printAllCombinationsUtil(openSmallBracketsCount, closesmallBracketsCount, smallBracketsCount,
		 openCurlyBracketsCount, closeCurlyBrßßacketsCount, curlyBracketCounts,
		  openBigBracketsCount, closeBigBracketsCount+1, bigBracketCounts,
		   index+1);
	}

	if(openBigBracketsCount < bigBracketCounts) {
		bracketsCombination[index] = '[';
		printAllCombinationsUtil(openSmallBracketsCount, closesmallBracketsCount, smallBracketsCount,
		 openCurlyBracketsCount, closeCurlyBracketsCount, curlyBracketCounts,
		  openBigBracketsCount+1, closeBigBracketsCount, bigBracketCounts,
		   index+1);
	}
}

void printAllCombinations(int smallBracketsCount, int curlyBracketCounts, int bigBracketCounts) {
	printAllCombinationsUtil(0, 0, smallBracketsCount, 0, 0, curlyBracketCounts, 0, 0, bigBracketCounts, 0);
}

int main() {
	printAllCombinations(1, 1, 1);
	return 0;
}