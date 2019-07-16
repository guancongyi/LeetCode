#include<iostream>
#include<math.h>
#include <queue>


#include"TwoSum.h"
#include"SwapNodesInPairs.h"
#include"MergeTwoSortedList.h"
#include"ReverseList.h"
#include"middleNode.h"
#include"NextLargerNodes.h"
#include"MaxArea.h"
#include"Subsets.h"
#include"FlipAndInvertImage.h"
#include"MaxAreaOfIsland.h"
#include"FindDuplicates.h"
#include"CandyCrush.h"
#include"ValidParentheses.h"
#include"DecodeString.h"
#include"BestTimeToBuyAndSellStock.h"
#include"MovingAverage.h"
#include"FirstUniqChar.h"
#include"ValidBST.h"


using namespace std;

void testSwapNodesInPair();
void testTwoSum();
void testMergeTwoSortedList();
void testReverseList();
void testNextLargerNodes();
void testMaxArea();
void testSubsets();
void testFlipAndInvertImage();
void testMaxAreaOfIsland();
void testDuplicates();
void testValidParentheses();
void testDecodeString();
void testBestProfit();
void testMovingAvg();
void testFirstUniqChar();
void testValidBST();


int main() {
	
	//testTwoSum();
	//testSwapNodesInPair();
	//testMergeTwoSortedList();
	//testReverseList();
	//testNextLargerNodes();
	//testMaxArea();
	//testSubsets();
	//testFlipAndInvertImage();
	//testMaxAreaOfIsland();
	//testDuplicates();
	//testValidParentheses();
	//testDecodeString();
	//testBestProfit();
	//testMovingAvg();
	//testFirstUniqChar();
	testValidBST();
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

void testFlipAndInvertImage()
{
	vector<vector<int>> test;
	test.push_back({ 1, 1, 0 });
	test.push_back({ 1, 0, 1 });
	test.push_back({ 0, 0, 0 });
	//test.push_back({ 0, 1, 0 });
	//test.push_back({ 0, 1, 0 });
	FlipAndInvertImageSolution s;
	vector<vector<int>> ret = s.flipAndInvertImage(test);
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (size_t j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j];
		}
		cout << endl;
	}
}

void testMaxAreaOfIsland()
{
	vector<vector<int>> test;

	test.push_back({ 1,1,0,0,0 });
	test.push_back({ 1,1,0,0,0 });
	test.push_back({ 0,0,0,1,1 });
	test.push_back({ 0,0,0,1,1 });

	/*test.push_back({ 0,0,1,0,0,0,0,1,0,0,0,0,0 });
	test.push_back({ 0,0,0,0,0,0,0,1,1,1,0,0,0 });
	test.push_back({ 0,1,1,0,1,0,0,0,0,0,0,0,0 });
	test.push_back({ 0,1,0,0,1,1,0,0,1,0,1,0,0 });
	test.push_back({ 0,1,0,0,1,1,0,0,1,1,1,0,0 });*/

	//test.push_back({ 0,0,0,0,0,0,0,0,0,0,1,0,0 });
	//test.push_back({ 0,0,0,0,0,0,0,1,1,1,0,0,0 });
	//test.push_back({ 0,0,0,0,0,0,0,1,1,0,0,0,0 });

	MaxAreaOfIslandSolution s;
	int ret = s.maxAreaOfIsland(test);
	cout << ret;
}

void testDuplicates()
{
	vector<int> test({ 1,2,3,4,3,3 });
	FindDuplicatesSolution s;
	vector<int> ret = s.findDuplicates(test);

	for (size_t j = 0; j < ret.size(); j++) {
		cout << ret[j];
	}
}

void testValidParentheses()
{
	string test = "]]";
	ValidParenthesesSolution s;
	bool ret = s.isValid(test);
	cout << ret << endl;
}

void testDecodeString()
{
	string str = "10[a]";
	DecodeStringSolution s;
	string ret = s.decodeString(str);
	cout << ret << endl;
}

void testBestProfit()
{
	vector<int> test({ 7,1});
	BestProfitSolution s;
	int ret = s.maxProfit(test);
	cout << ret;
}

void testMovingAvg()
{
	MovingAverage* obj = new MovingAverage(3);
	for (size_t i = 0; i < 4; i++)
	{
		double a = obj->next(i);
		cout << a << endl;
	}
	

}

void testFirstUniqChar()
{
	string str = "doloveleetcodedoyouilove";
	FirstUniqCharSolution s;
	int ret = s.firstUniqChar(str);
	cout << ret;
}

void testValidBST()
{
	TreeNode* t = new TreeNode(2);
	t->left = new TreeNode(1);
	t->right = new TreeNode(3);
	/*t->left->left = new TreeNode(0);
	t->left->right = new TreeNode(2);
	t->right->left = new TreeNode(4);
	t->right->right = new TreeNode(6);*/

	//t->left->right->right = new TreeNode(3);

	ValidBSTSolution s;
	cout << s.isValidBST(t) << endl;
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