/**
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

I am using a dumb way
Better idea using a fast, slow pointer, when fast pointer reached, the slow pointer
should be at the position of half length of the list.
 */
class SolutionMiddleNode {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* countPtr = head;
		int count = 0;
		while (countPtr != NULL) {
			count++; 
			countPtr = countPtr->next;
		}
		int mid;
		if (count % 2 == 0) { mid = (count / 2) + 1; }
		else { mid = (count / 2)+1; }

		int count2 = 0;
		
		while (head != NULL) {
			count2++;
			if (count2 == mid) {
				return head;
			}
			head = head->next;
		}
		
		return NULL;
		
	}
};
