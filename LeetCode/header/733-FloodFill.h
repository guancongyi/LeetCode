class FloodFillSolution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
		stack<pair<int, int>> s;
		s.push({ sr,sc });

		while (s.size() != 0) {
			auto cur = s.top();
			s.pop();
			int r = cur.first;
			int c = cur.second;


			vector<pair<int, int>> neighbors = { {r - 1,c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
			for (int i = 0; i < neighbors.size(); i++) {
				auto neighbor = neighbors[i];
				if (inBound(neighbor.first, neighbor.second, image.size(), image[0].size())) {
					if (!visited[neighbor.first][neighbor.second]) {
						if (image[neighbor.first][neighbor.second] == image[r][c]) s.push(neighbor);
					}
				}
			}
			image[r][c] = newColor;
			visited[r][c] = 1;

		}
		return image;
	}

	bool inBound(int r, int c, int rows, int cols) {
		if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
		return true;
	}
};