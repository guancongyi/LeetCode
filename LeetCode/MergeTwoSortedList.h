
/*
   Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

   Input: 1->2->4, 1->3->4
   Output: 1->1->2->3->4->4
*/

class SolutionMergeTwoSortedLists {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		ListNode* curr = new ListNode(-1);
		ListNode* head = curr;

		recursiveMerge(l1, l2, curr);

		head = head->next;
		return head;
	}

	ListNode* recursiveMerge(ListNode* n1, ListNode* n2, ListNode* curr) {
		if (n1 == nullptr && n2 != nullptr) {
			curr->next = n2;
			return curr;
		}
		else if (n1 != nullptr && n2 == nullptr) {
			curr->next = n1;
			return curr;
		}
		else if (n1 == nullptr && n2 == nullptr) {
			return curr;
		}

		if (n1->val <= n2->val) {
			curr->next = n1;
			curr = n1;
			n1 = n1->next;
			recursiveMerge(n1, n2, curr);
		}
		else if (n1->val > n2->val) {
			curr->next = n2;
			curr = n2;
			n2 = n2->next;
			recursiveMerge(n1, n2, curr);
		}
		return curr;
	}
};


 