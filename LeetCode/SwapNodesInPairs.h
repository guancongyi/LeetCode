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
		ListNode* parent = nullptr;
		ListNode* curr = head;
		if (head == NULL) { return NULL; }
		ListNode* newHead = curr->next;

		while (curr != nullptr) {
			ListNode* temp = curr;
			ListNode* temp2 = curr->next;
			if (count == 1) {
				if (curr->next == NULL) { return curr; }
				curr->next = curr->next->next;
				parent = curr;
			}
			else if (count % 2 == 0) {
				curr->next = last;
			}
			else {
				if (curr->next != NULL) {
					parent->next = curr->next;
					curr->next = curr->next->next;
					parent = curr;
				}
			}
			last = temp;
			curr = temp2;
			count++;
		}
		return newHead;
	}
};