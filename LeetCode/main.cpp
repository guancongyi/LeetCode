#include<iostream>
#include"TwoSum.h"
#include"SwapNodesInPairs.h"

using namespace std;

void testTwoSum() {
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
}

void testSwapNodesInPair() {
	
	
	
	ListNode* curr = new ListNode(1);
	ListNode* first = curr;
	int i = 2;
	while(i <= 10)
	{
		curr->next = new ListNode(i);
		curr = curr->next;
		i++;
	}
	
	//while (first != nullptr) {
	//	cout << first->val << endl;
	//	first = first->next;
	//}

	SolutionSwapNodesInPairs s;
	ListNode* ret = s.swapPairs(first);

	while (ret != nullptr) {
		cout << ret->val << endl;
		ret = ret->next;
	}
}

int main() {
	
	//testTwoSum();
	testSwapNodesInPair();
	return 0;
}

