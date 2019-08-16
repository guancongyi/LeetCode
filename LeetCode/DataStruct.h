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
void testKillProcess();
void testMinStack();
void testCopyListWithRandomPtr();
void testEvaluateDivision();
void testLRUCache();
void testRectOverlap();
void testWidthOfBTSolution();
void testConstructBT();
void testPopulatingRightPtrsI();
void testPopulatingRightPtrsII();
void testSortCharByFreq();
void testValidAnagram();

#ifndef NODE
#define NODE

class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

#endif // !NODE

