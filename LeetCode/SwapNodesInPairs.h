/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 Given 1->2->3->4, you should return the list as 2->1->4->3.

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
		ListNode* curr = head;
		ListNode* next = curr->next;
		ListNode* newHead = next;

		while (curr != nullptr) {
			
			if (count % 2 == 0) {
				last->next = curr->next;
				curr->next = last;
			}
			last = curr;
			curr = last->next;
			count++;
		}
		return newHead;
	}
};