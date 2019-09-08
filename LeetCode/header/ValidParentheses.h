/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Solution:
Think way too much, not necessary,
just use a STACK...
*/

class ValidParenthesesSolution {
public:
	bool isValid(string s) {
		vector<char> myStack;
		
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
				myStack.push_back(s[i]);
			}
			else {
				if (myStack.size() != 0) {
					if (checkPair(myStack.back(), s[i])) {
						myStack.pop_back();
					}
					else{
						return 0;
					}

				}
				else {
					return 0;
				}
			}
		}
		if (myStack.size() != 0) { return 0; }
		return 1;
	}
	
	//int helper(int parent, int curr, string s) {
	//	// exceed max length
	//	if (curr == s.length()-1) { return curr; }
	//	// met another open bracket
	//	else if (s[curr] == '{' || s[curr] == '(' || s[curr] == '[') {	
	//		int ret =  helper(curr, curr + 1, s);
	//		if (ret == -1) { return -1; }
	//	}
	//	// met close bracket
	//	else {
	//		// adjacent is the close bracket
	//		if (checkPair(s[curr], s[parent]) == 1) {
	//			return helper(parent - 1, curr + 1, s);
	//		}
	//		return -1; 
	//		
	//	}
	//}

	int checkPair(char a, char b) {
		switch (a)
		{
		case '{':
			if (b == '}') return 1;
			else return 0;
		case '}':
			if (b == '{') return 1;
			else return 0;
		case '[':
			if (b == ']') return 1;
			else return 0;
		case ']':
			if (b == '[') return 1;
			else return 0;
		case '(':
			if (b == ')') return 1;
			else return 0;
		case ')':
			if (b == '(') return 1;
			else return 0;
		default:
			break;
		}
	}

};