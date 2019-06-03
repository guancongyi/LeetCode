/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 Given 1->2->3->4, you should return the list as 2->1->4->3.

 State machine:
 
 case 1: at first position
 curr points to third, set lastOdd to curr.

 case 2: at even position
 curr points to last.

 case 3: at odd position
 lastOdd points to curr's next,
 curr points to next's next,
 update lastOdd to curr.

 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class SolutionSwapNodesInPairs {
public:

	ListNode* swapPairs(ListNode* head) {
		int count = 1;
		ListNode* last = nullptr;
		ListNode* lastOdd = nullptr;
		ListNode* curr = head;
		if (head == NULL) { return NULL; }
		ListNode* newHead = curr->next;

		while (curr != nullptr) {
			ListNode* temp = curr;
			ListNode* temp2 = curr->next;
			if (count == 1) {
				if (curr->next == NULL) { return curr; }
				curr->next = curr->next->next;
				lastOdd = curr;
			}
			else if (count % 2 == 0) {
				curr->next = last;
			}
			else {
				if (curr->next != NULL) {
					lastOdd->next = curr->next;
					curr->next = curr->next->next;
					lastOdd = curr;
				}
			}
			last = temp;
			curr = temp2;
			count++;
		}
		return newHead;
	}
};