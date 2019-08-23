

class Add2NumbersSolution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* first = l1;
		ListNode* second = l2;
		ListNode* trav = new ListNode(0);
		ListNode* res = trav;
		int carry = 0, sum;
		while (true) {
			if (first != NULL || second != NULL) {

				if (first != NULL && second != NULL) sum = first->val + second->val + carry;
				else if (first != NULL && second == NULL)sum = first->val + carry;
				else if (first == NULL && second != NULL)sum = second->val + carry;

				if (sum >= 10) { carry = 1; trav->next = new ListNode(sum - 10); }
				else { trav->next = new ListNode(sum); carry = 0; }
				trav = trav->next;

				if (first != NULL)first = first->next;
				if (second != NULL)second = second->next;
			}
			else {
				if (carry == 1)trav->next = new ListNode(1); carry = 0;
				break;
			}
		}

		return res->next;
	}
};

class Add2Numbers2Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// v3 is longer than v4
		vector<int> v1, v2, v3, v4;
		ListNode *trav = NULL, *temp;

		while (l1 != NULL) {v1.push_back(l1->val);l1 = l1->next;}
		while (l2 != NULL) { v2.push_back(l2->val); l2 = l2->next; }
		if (v1.size() > v2.size()) { v3 = v1; v4 = v2; }
		else { v3 = v2; v4 = v1; }

		int second = v4.size()-1, first = v3.size()-1;
		int carry = 0, sum;
		while (true) {
			
			if (first >= 0) {
				if (second >= 0) sum = v3[first] + v4[second] + carry;
				else sum = v3[first] + carry;
				
				if (sum >= 10) { temp = new ListNode(sum - 10); carry = 1; }
				else { temp = new ListNode(sum); carry = 0; }

				temp->next = trav;
				trav = temp;
			}
			else {
				if (carry == 1) {
					temp = new ListNode(1);
					temp->next = trav;
					trav = temp;
				}
				break;
			}
			first--;
			second--;
		}
		return trav;
	}


};