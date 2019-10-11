


class LongestIncreasingPathSolution {
public:
	//struct comp
	//{
	//	bool operator()(const pair<pair<int, int>, int>& lhs, const pair<pair<int, int>, int>& rhs)
	//	{
	//		return lhs.second > rhs.second;
	//	}
	//};
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)return 0;
		int R = matrix.size();
		int C = matrix[0].size();
		if (R == 1 && C == 1)return 1;


		queue<pair<pair<int, int>,int>> q;
		vector<vector<int>> topo(R, vector<int>(C, 0));
		for (size_t i = 0; i < R; i++) {
			for (size_t j = 0; j < C; j++) {
				vector<pair<int, int>> neighbors = { {i - 1,j}, {i, j + 1}, {i + 1, j}, {i, j - 1} };
				for (size_t k = 0; k < neighbors.size(); k++) {
					if (inBound(neighbors[k].first, neighbors[k].second, R, C)) {
						if (matrix[neighbors[k].first][neighbors[k].second] > matrix[i][j]) topo[i][j] += 1;
					}
				}
				if (topo[i][j] == 0) q.push({ { i,j },1 });
			}
		}
		
		int best = 0;
		while (q.size() != 0) {
			auto cur = q.front();
			q.pop();
			int r = cur.first.first; int c = cur.first.second; int level = cur.second;
			
			vector<pair<int, int>> neighbors = { {r - 1,c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
			level++;
			for (size_t k = 0; k < neighbors.size(); k++){
				auto neighbor = neighbors[k];
				if (inBound(neighbor.first, neighbor.second, R, C)) {

					if (matrix[r][c] > matrix[neighbor.first][neighbor.second]) {
						if (--topo[neighbor.first][neighbor.second] == 0) q.push({ neighbor,level });
					}
				}
			}
			if (level > best) best = level;
		}

		return best;

	}

	bool inBound(int r, int c, int rows, int cols) {
		if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
		return true;
	}
};