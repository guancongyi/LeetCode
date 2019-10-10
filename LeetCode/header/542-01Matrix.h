class zeroOneMatSolution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int R = matrix.size(); int C = matrix[0].size();
		vector<vector<int>> res(R, vector<int>(C, INT_MAX));
		for (size_t i = 0; i < R; i++) {
			for (size_t j = 0; j < C; j++) {
				if (matrix[i][j] != 0) {
					queue<pair<pair<int, int>, int>> q;
					q.push({ { i,j },0 });

					while (q.size() != 0) {
						auto cur = q.front();
						q.pop();
						int r = cur.first.first; int c = cur.first.second; int level = cur.second;
						level++;
						vector<pair<int, int>> neighbors = { {r - 1,c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
						for (size_t k = 0; k < neighbors.size(); k++) {
							auto neighbor = neighbors[k];
							if (neighbor.first >= 0 && neighbor.second >= 0 && neighbor.first < R && neighbor.second < C) {
								if (matrix[neighbor.first][neighbor.second] == 0) {
									if (level < res[i][j]) {
										matrix[i][j] = level;
										res[i][j] = level;
									}
									while (q.size() != 0) { q.pop(); }
									break;

								}
								else {
									q.push({ neighbor, level });
								}
							}
						}
					}
				}

			}
		}

		return matrix;

	}
};