#include<iostream>
#include"TwoSum.h"

using namespace std;

int main() {
	
	SolutionTwoSum s;
	vector<int> test, rslt;
	test.push_back(3);
	test.push_back(3);
	test.push_back(4);



	rslt = s.twoSum(test, 6);

	cout << "Solutions are: ";
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << "   ";
	}

	return 0;
}