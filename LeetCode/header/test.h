#include"1-TwoSum.h"
#include"SwapNodesInPairs.h"
#include"MergeTwoSortedList.h"
#include"ReverseList.h"
#include"middleNode.h"
#include"NextLargerNodes.h"
#include"MaxArea.h"
#include"78-Subsets.h"
#include"FlipAndInvertImage.h"
#include"200_95-IslandProblems.h"
#include"FindDuplicates.h"
#include"CandyCrush.h"
#include"ValidParentheses.h"
#include"DecodeString.h"
#include"BestTimeToBuyAndSellStock.h"
#include"MovingAverage.h"
#include"FirstUniqChar.h"
#include"ValidBST.h"
#include "582-KillProcess.h"
#include"MinStack.h"
#include"CopyListWithRandomPtr.h"
#include"EvaluateDivision.h"
#include"LRUCache.h"
#include"RectOverlap.h"
#include"BloombergMock1.h"
#include"ConstructBTFromPreorderAndInorder.h"
#include"PopulatingRightPtrsI.h"
#include"PopulatingRightPtrsII.h"
#include"SortCharByFrequency.h"
#include"ValidAnagram.h"
#include"TopKFreqWords.h"
#include"MeetingRoomI.h"
#include"MeetingRoomII.h"
#include"BTZigZagTraversal.h"
#include"Add2Numbers.h"
#include"LongestPalindrome.h"
#include"MaxmiumSubarray.h"
#include"HappyNumber.h"
#include"AkunaC++.h"
#include"MaxDepthBT.h"
#include"SortedArrayToBST.h"
#include"LinkedListCycle.h"
#include"KClosestPointToOrigin.h"
#include"BackSpaceCompare.h"
#include"UniqueEmailAddr.h"
#include"CountBtNodes.h"
#include"1057-CampusBike.h"
#include"766-ToeplitzMatrix.h"
#include"422-ValidWordSquare.h"
#include"56-MergeIntervals.h"
#include"939-MinAreaOfRect.h"
#include"993-CousinsInBT.h"
#include"102-BTLevelOrderTrav.h"
#include"724-FindPivotIndex.h"
#include"604-DesignCompressedStrIterator.h"
#include"408-ValidWordAbbr.h"
#include"285-InorderSuccessorInBST.h"
#include"298_549-BTLongestConsecutive.h"
#include"204-countPrimes.h"
#include"380-InsertDelGetRandomO1.h"
#include"22-GenerateParenthesis.h"
#include"3_159_340LongestSubstring.h"
#include"55-JumpGame.h"
#include"376-WiggleSubsequence.h"
#include"222-CountCompleteTreeNodes.h"
#include"406-QreconstructionByHeight.h"
#include"763-PartitionLabel.h"
#include"455-AssignCookies.h"
#include"763-PartitionLabel.h"
#include "767-ReorganizeString.h"
#include"402-RemoveKDigits.h"

using namespace std;

void testTwoSum() {
	SolutionTwoSum s;
	vector<int> test, rslt;
	test.push_back(3);
	test.push_back(3);
	test.push_back(4);

	rslt = s.twoSum1(test, 6);

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
	//test.push_back(5);
	Subsets1_2 s;
	vector<vector<int>> ret = s.subsets(test);
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

void testIslandProblems()
{
	vector<vector<char>> test;

	/*test.push_back({ '1','1','0','0','0' });
	test.push_back({ '1','1','0','0','0' });
	test.push_back({ '0','0','1','0','0' });
	test.push_back({ '0','0','0','1','1' });
	test.push_back({ '0','0','0','1','1' });*/

	/*test.push_back({ 0,0,1,0,0,0,0,1,0,0,0,0,0 });
	test.push_back({ 0,0,0,0,0,0,0,1,1,1,0,0,0 });
	test.push_back({ 0,1,1,0,1,0,0,0,0,0,0,0,0 });
	test.push_back({ 0,1,0,0,1,1,0,0,1,0,1,0,0 });
	test.push_back({ 0,1,0,0,1,1,0,0,1,1,1,0,0 });*/

	//test.push_back({ 0,0,0,0,0,0,0,0,0,0,1,0,0 });
	//test.push_back({ 0,0,0,0,0,0,0,1,1,1,0,0,0 });
	//test.push_back({ 0,0,0,0,0,0,0,1,1,0,0,0,0 });

	MaxAreaOfIslandSolution s;
	NumOfIslandSolution s2;
	int ret = s2.numIslands(test);
	//int ret = s.maxAreaOfIsland(test);
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
	vector<int> test({ 7,1 });
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

void testKillProcess()
{
	vector<int> pid({ 6,1,3,9,5,8,7,4,10 });
	vector<int> ppid({ 5,8,4,5,10,5,3,8,0 });
	KillProcessSolution k;
	vector<int> ret = k.killProcess2nd(pid, ppid, 10);
	for (size_t i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
}

void testMinStack()
{
	MinStack* obj = new MinStack();
	obj->push(-10);
	obj->push(14);
	obj->push(-20);
	obj->push(10);
	obj->push(-7);

	int param_3 = obj->top();
	obj->pop();
	obj->pop();
	int param_4 = obj->getMin();
	obj->pop();
	obj->push(20);
	int param_5 = obj->getMin();
	cout << param_3 << " " << param_4 << " " << param_5;
}

void testCopyListWithRandomPtr()
{
	Node* one = new Node(1, NULL, NULL);
	Node* two = new Node(2, NULL, NULL);
	Node* three = new Node(3, NULL, NULL);
	Node* four = new Node(4, NULL, NULL);
	one->next = two;
	one->random = three;
	two->next = three;
	two->random = three;
	three->next = four;


	CopyListWithRandomPtrSolution s;
	Node* ret = s.copyRandomList(one);
	Node* temp = ret;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;

	}
	cout << endl;
	temp = ret;
	while (temp != NULL) {
		if (temp->random != NULL) { cout << temp->random->val << " "; }
		else { cout << " " << " "; }
		temp = temp->next;
	}
}

void testEvaluateDivision()
{
	vector<vector<string>> qs;
	vector<vector<string>> eqs;
	vector<double> vals;
	eqs.push_back({ "a","b" });
	eqs.push_back({ "e","f" });
	eqs.push_back({ "b","e" });
	vals.push_back(3.4);
	vals.push_back(1.4);
	vals.push_back(2.3);
	qs.push_back({ "a", "f" });


	EvaluateDivisionSolution s;
	vector<double> ret = s.calcEquation(eqs, vals, qs);
	for (size_t i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	//qs.push_back({ 0,0,0,1,1 });
}

void testLRUCache()
{
	LRUCache* obj = new LRUCache(2);

	obj->put(2, 6);
	obj->put(1, 5);
	obj->put(1, 2);
	cout << obj->get(1) << endl;
	cout << obj->get(2) << endl;

	/*cout << obj->get(3) << endl;
	obj->put(4, 4);
	cout << obj->get(5) << endl;
	obj->put(5, 6);*/
	//cout << obj->get(1) << endl;
}

void testRectOverlap()
{
	vector<int> v1({ -7,-3,10,5 });
	vector<int> v2({ -6,-5,5,10 });
	RectOverlapSolution s;
	cout << s.isRectangleOverlap(v1, v2) << endl;
}

void testWidthOfBTSolution()
{
	TreeNode* t = new TreeNode(2);
	t->left = new TreeNode(1);
	t->right = new TreeNode(3);
	t->left->left = new TreeNode(0);
	t->left->right = new TreeNode(2);
	t->right->left = new TreeNode(4);
	t->right->right = new TreeNode(6);

	WidthOfBTSolution s;
	cout << s.widthOfBinaryTree(t) << endl;
}

void testConstructBT()
{
	vector<int> pre({ 1,2,4,5,6,3,7 });
	vector<int> in({ 4,2,5,1,6,3,7 });
	ConstructBTSolution s, s2;
	TreeNode* ret = s.buildTree(pre, in);
	TreeNode* ret2 = s2.buildTree(pre, in);
	s.preorder(ret);
	cout << endl;
	s.inorder(ret2);


}

void testPopulatingRightPtrsI()
{

	Node* t = new Node(1, NULL, NULL, NULL);
	t->left = new Node(2, NULL, NULL, NULL);
	t->right = new Node(3, NULL, NULL, NULL);
	t->left->left = new Node(4, NULL, NULL, NULL);
	t->left->right = new Node(5, NULL, NULL, NULL);
	t->right->left = new Node(6, NULL, NULL, NULL);
	t->right->right = new Node(7, NULL, NULL, NULL);
	t->left->left->left = new Node(8, NULL, NULL, NULL);
	t->left->left->right = new Node(9, NULL, NULL, NULL);
	t->left->right->left = new Node(10, NULL, NULL, NULL);
	t->left->right->right = new Node(11, NULL, NULL, NULL);

	t->right->left->left = new Node(12, NULL, NULL, NULL);
	t->right->left->right = new Node(13, NULL, NULL, NULL);
	t->right->right->left = new Node(14, NULL, NULL, NULL);
	t->right->right->right = new Node(15, NULL, NULL, NULL);

	t->left->left->left->left = new Node(16, NULL, NULL, NULL);
	t->left->left->right->left = new Node(18, NULL, NULL, NULL);
	t->left->right->left->left = new Node(20, NULL, NULL, NULL);
	t->left->right->right->left = new Node(22, NULL, NULL, NULL);
	t->left->left->left->right = new Node(17, NULL, NULL, NULL);
	t->left->left->right->right = new Node(19, NULL, NULL, NULL);
	t->left->right->left->right = new Node(21, NULL, NULL, NULL);
	t->left->right->right->right = new Node(23, NULL, NULL, NULL);

	t->right->left->left->left = new Node(24, NULL, NULL, NULL);
	t->right->left->right->left = new Node(26, NULL, NULL, NULL);
	t->right->right->left->left = new Node(28, NULL, NULL, NULL);
	t->right->right->right->left = new Node(30, NULL, NULL, NULL);
	t->right->left->left->right = new Node(25, NULL, NULL, NULL);
	t->right->left->right->right = new Node(27, NULL, NULL, NULL);
	t->right->right->left->right = new Node(29, NULL, NULL, NULL);
	t->right->right->right->right = new Node(31, NULL, NULL, NULL);

	PopulatingRightPtrsSolution s;
	Node* ret = s.connect(t);
	cout << "test";
}

void testPopulatingRightPtrsII()
{
	Node* t = new Node(1, NULL, NULL, NULL);
	t->left = new Node(2, NULL, NULL, NULL);
	t->right = new Node(3, NULL, NULL, NULL);
	t->left->left = new Node(4, NULL, NULL, NULL);
	t->left->right = new Node(5, NULL, NULL, NULL);
	t->right->left = new Node(6, NULL, NULL, NULL);
	t->right->right = new Node(7, NULL, NULL, NULL);
	t->left->left->left = new Node(8, NULL, NULL, NULL);
	t->left->left->right = new Node(9, NULL, NULL, NULL);
	//t->left->right->left = new Node(10, NULL, NULL, NULL);
	t->left->right->right = new Node(11, NULL, NULL, NULL);

	//t->right->left->left = new Node(12, NULL, NULL, NULL);
	//t->right->left->right = new Node(13, NULL, NULL, NULL);
	t->right->right->left = new Node(14, NULL, NULL, NULL);
	t->right->right->right = new Node(15, NULL, NULL, NULL);

	PopulatingRightPtrsIISolution s;
	Node* ret = s.connect(t);
	cout << "test";
}

void testSortCharByFreq()
{
	SortCharByFreqSolution s;
	cout << s.frequencySort("cccaaa");
}

void testValidAnagram()
{
	ValidAnagramSolution sol;
	string s = "Anagram";
	string t = "nagaram";
	cout << sol.isAnagram(s, t);
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

void testTopKFreqWords() {
	vector<string> strs({ "i", "love", "leetcode", "i", "love", "coding"});
	TopKsSolution s;
	vector<string> ret = s.topKFrequent(strs, 2);
	for (size_t i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
}

void testMeetingRoomI() {
	vector<vector<int>> vec({ {5,10},{15,20},{2,30} });
	MeetingRoomISolution s;
	s.canAttendMeetings(vec);
}

void testMeetingRoomII() {
	//vector<vector<int>> vec({ {0,30},{5,25},{10,15 },{12,20},{13,14},{14,15} }); // 5
	vector<vector<int>> vec({ {7,10},{2,8},{8,10} });
	MeetingRoomIISolution s;
	cout << s.minMeetingRoomsAns(vec);
}

void testBTZigZagTraversal() {
	TreeNode* t = new TreeNode(3);
	t->left = new TreeNode(4);
	t->right = new TreeNode(5);
	t->left->left = new TreeNode(-7);
	t->left->right = new TreeNode(-6);
	t->left->left->left = new TreeNode(-7);
	t->left->right->left = new TreeNode(-5);
	t->left->right->left->right = new TreeNode(-4);
	BTZigZagSolution s;
	vector<vector<int>> ret = s.zigzagLevelOrder(t);

}

void testAdd2Numbers2() {
	ListNode* curr = new ListNode(9);
	ListNode* first = curr;
	curr->next = new ListNode(9);
	curr = curr->next;
	curr->next = new ListNode(9);
	curr = curr->next;
	curr->next = new ListNode(9);
	curr = curr->next;
	curr->next = new ListNode(5);
	curr = curr->next;

	ListNode* second = new ListNode(5);
	Add2Numbers2Solution s;
	ListNode* res = s.addTwoNumbers(first, second);

}

void testLongestPalindrome() {
	string s = "aabaaccaab";
	LongestPalindromeSolution sol;
	cout<< sol.longestPalindrome(s);

}

void testMaxSubArray() {
	vector<int> test;
	test.push_back(-2);
	test.push_back(1);
	test.push_back(-3);
	test.push_back(4);
	test.push_back(-1);
	test.push_back(2);
	test.push_back(1);
	test.push_back(-5);
	test.push_back(4);
	MaxSubArraySolution s;
	cout << s.maxSubArray(test);
}

void testHappyNumber() {
	HappySolution s;
	cout << s.isHappy(0);
}

void testKClosestPointToOrigin() {
	vector<vector<int>> vec({ {1,3},{-2,2} });
	KClosestPointsSolution s;
	vector<vector<int>> ret = s.kClosest(vec,1);
	
}

void testCampusBike() {
	CampusBikeSolution s;
	vector<vector<int>> ws({ {0,0},{1,1},{2,0} });
	vector<vector<int>> bs({ {1,0},{2,2},{2,1} });

	s.assignBikes(ws, bs);

}

void testToeplitzMatrix() {
	vector<vector<int>> test({ 
		{1,2,3,4},
		{5,1,2,3},
		{9,5,1,2} });

	ToeplitzMatrixSolution s;
	cout << s.isToeplitzMatrix(test);
}

void testMergeIntervals() {
	vector<vector<int>> test({
		{2,3},
		{2,2},
		{3,3},
		{1,3},
		{5,7},
		{2,2},
		{4,6} });

	MergeIntervalsSolution s;
	vector<vector<int>> ret = s.merge(test);
}

void testMinAreaOfRect() {
	vector<vector<int>> rects({
	{1,1},
	{1,3},
	{1,4},
	{3,1},
	{3,3},
	//{},
	{3,4} });

	MinAreaOfRectSolution s;
	s.minAreaRect(rects);
}

void testValidWordAbbr() {
	string w = "abbbbbbbbbb";
	string abbr = "a10";
	ValidWordAbbrSolution s;
	cout << s.validWordAbbreviation(w, abbr);
}

void testBTLongestConsecutive() {
	TreeNode* t = new TreeNode(1);
	t->left = new TreeNode(2);
	t->right = new TreeNode(2);
	t->left->left = new TreeNode(1);
	t->left->right = new TreeNode(3);
	//t->left->left->left = new TreeNode(-7);
	t->left->right->right = new TreeNode(4);
	//t->left->right->left->right = new TreeNode(-4);

	BTLongestCOnsecutiveSolution s;
	s.longestConsecutiveII(t);

}

void testGenerateParenthesis() {
	GenerateParenthesisSolution s;
	s.generateParenthesis(2);
}

void testLongestSubString() {
	string str = "aba";
	LongestSubStringSolution s;

	int ret = s.lengthOfLongestSubstringKDistinct(str,1);


}

void testJumpGame() {
	vector<int> n = { 4,2,0,0,1,1,4,4,4,0,4,0};
	JumpGameSolution s;
	cout << s.canJump(n) << endl;
}

void testQreConstructByHeight(){
	vector<vector<int>> test({
		{7,0},
		{4,4},
		{7,1},
		{5,0},
		{6,1},
		{5,2},
		{2,6},
		{1,1} });

	QreconstructByHeightSolution s;
	s.reconstructQueue(test);

}

void testPartitionLabel() {
	string s = "abcbadede";
	PartitionLabelSolution ps;
	ps.partitionLabels(s);
}

void testAssignCookies() {
	vector<int> s = { 5,6,7,8 };
	vector<int> g = { 10, 9,8,7 };
	AssignCookiesSolution ss;
	ss.findContentChildren(g, s);
}

void testReorganizeStr() {
	string str = "aaab";
	ReorganizeStringSolution s;
	s.reorganizeString(str);
}

void testRemoveKDigits() {
	string s = "181510534";
	RemoveKDigitsSolution ss;
	ss.removeKdigits(s,5);
}