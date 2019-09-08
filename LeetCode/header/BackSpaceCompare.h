class BackSpaceCompSolution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> myStack;
		for (int i = S.length() - 1; i >= 0; i--) {
			myStack.push(S[i]);
		}

		string s1 = "";
		while (!myStack.empty()) {
			char cur = myStack.top();
			myStack.pop();
			if (cur == '#' && s1.length() > 0) s1.pop_back();
			if (cur != '#') s1 += cur;
		}

		for (int i = T.length() - 1; i >= 0; i--) {
			myStack.push(T[i]);
		}

		string s2 = "";
		while (!myStack.empty()) {
			char cur = myStack.top();
			myStack.pop();
			if (cur == '#' && s2.length() > 0) s2.pop_back();
			if(cur != '#') s2 += cur;
		}

		return s1 == s2;
	}
};