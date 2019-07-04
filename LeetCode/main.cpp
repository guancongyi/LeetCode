#include<iostream>
#include"TwoSum.h"
#include"SwapNodesInPairs.h"
#include"MergeTwoSortedList.h"
#include"ReverseList.h"
#include"middleNode.h"
#include"NextLargerNodes.h"
#include"MaxArea.h"
#include"Subsets.h"

using namespace std;
void testSwapNodesInPair();
void testTwoSum();
void testMergeTwoSortedList();
void testReverseList();
void testNextLargerNodes();
void testMaxArea();
void testSubsets();



int main() {
	
	//testTwoSum();
	//testSwapNodesInPair();
	//testMergeTwoSortedList();
	//testReverseList();
	//testNextLargerNodes();
	//testMaxArea();
	testSubsets();
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

	SolutionMergeTwoSortedLists s;
	ListNode* ret = s.mergeTwoLists(first, second);

	while (ret != nullptr) {
		cout << ret->val << endl;
		ret = ret->next;
	}
}

void testReverseList()
{
	ListNode* curr = new ListNode(1);
	ListNode* first = curr;
	curr->next = new ListNode(2);
	curr = curr->next;
	curr->next = new ListNode(3);
	curr = curr->next;
	curr->next = new ListNode(4);
	curr = curr->next;
	curr->next = new ListNode(5);
	curr = curr->next;

	ReverseListIter s;
	ListNode* ret = s.reverseListRecursive(first);

	while (ret != nullptr) {
		cout << ret->val << endl;
		ret = ret->next;
	}

}

void testNextLargerNodes()
{
	ListNode* curr = new ListNode(1);
	ListNode* first = curr;
	curr->next = new ListNode(2);
	curr = curr->next;
	curr->next = new ListNode(3);
	curr = curr->next;
	curr->next = new ListNode(4);
	curr = curr->next;
	curr->next = new ListNode(5);
	curr = curr->next;

	SolutionNextLargerNodes s;
	vector<int> ret = s.nextLargerNodes(first);

	for (size_t i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}


}

void testMaxArea()
{
	vector<int> test;
	test.push_back(1);
	test.push_back(8);
	test.push_back(6);
	test.push_back(2);
	test.push_back(5);
	test.push_back(4);
	test.push_back(8);
	test.push_back(3);
	test.push_back(7);

	SolutionMaxArea s;
	int rslt = s.maxArea(test);

	cout << "Solution is:" << rslt;

}

void testSubsets()
{
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	Subsets s;
	vector<vector<int>> ret = s.subsetss(test);
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (size_t j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j];
		}
		cout << endl;
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