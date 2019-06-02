#include<iostream>
#include"TwoSum.h"
#include"SwapNodesInPairs.h"
#include"MergeTwoSortedList.h"

using namespace std;
void testSwapNodesInPair();
void testTwoSum();
void testMergeTwoSortedList();


int main() {
	
	//testTwoSum();
	//testSwapNodesInPair();
	testMergeTwoSortedList();
	return 0;
}



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

void testMergeTwoSortedList()
{
	ListNode* curr = new ListNode(1);
	ListNode* first = curr;
	curr->next = new ListNode(4);
	curr = curr->next;
	curr->next = new ListNode(5);
	curr = curr->next;
	curr->next = new ListNode(7);
	curr = curr->next;
	curr->next = new ListNode(8);
	curr = curr->next;
	
	ListNode* curr2 = new ListNode(2);
	ListNode* second = curr2;
	curr2->next = new ListNode(6);
	curr2 = curr2->next;
	curr2->next = new ListNode(7);
	curr2 = curr2->next;
	curr2->next = new ListNode(8);
	curr2 = curr2->next;
	curr2->next = new ListNode(9);
	curr2 = curr2->next;

	//while (first != nullptr) {
	//	cout << first->val << endl;
	//	first = first->next;
	//}
	//cout << " " << endl;
	//while (second != nullptr) {
	//	cout << second->val << endl;
	//	second = second->next;
	//}

	SolutionMergeTwoSortedLists s;
	ListNode* ret = s.mergeTwoLists(first, second);

	while (ret != nullptr) {
		cout << ret->val << endl;
		ret = ret->next;
	}
}

void testSwapNodesInPair() {
	ListNode* curr = new ListNode(1);
	ListNode* first = curr;
	int i = 2;
	while (i <= 10)
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