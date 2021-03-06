class GenerateParenthesisSolution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string str = "";
		int open = 0;
		int close = 0;
		clever(res, "", open, close, n);
		return res;
	}

	void clever(vector<string>& res, string str, int open, int close, int max) {
		if (str.length() == 2 * max) {
			res.push_back(str);
		}

		if (open < max) {


			clever(res, str + "(", open + 1, close, max);
		}

		if (close < open) {

			clever(res, str + ")", open, close + 1, max);
		}
	}


};