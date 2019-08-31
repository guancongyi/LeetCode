class ToeplitzMatrixSolution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int M = matrix.size();
		vector<int> last;
		for (int i = 0; i < M; i++) {
			if (!i) { last = matrix[i]; continue; }

			vector<int> cur = matrix[i];
			cur.erase(cur.begin());
			last.pop_back();
			if (last != cur) return false;
			else last = matrix[i];

		}
		return true;
	}
};