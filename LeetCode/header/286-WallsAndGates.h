class WallsAndGatesSolution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		//vector<vector<int>> res(rooms.size(), vector<int>(rooms[0].size(), INT_MAX));
		
		for (size_t i = 0; i < rooms.size(); i++){
			for (size_t j = 0; j < rooms[i].size(); j++){
				if (rooms[i][j] == 0) {
					vector<vector<int>> visited(rooms.size(), vector<int>(rooms[0].size(), 0));
					queue<pair<pair<int, int>, int>> q;
					q.push({ { i,j },0 });

					while (q.size() != 0) {
						auto cur = q.front();
						q.pop();
						int r = cur.first.first;
						int c = cur.first.second;
						int level = cur.second;
						
						vector<pair<int, int>> neighbors = { {r - 1,c}, {r, c + 1}, {r + 1, c}, {r, c - 1} };
						level++;
						for (size_t k = 0; k < neighbors.size(); k++){
							auto neighbor = neighbors[k];
							if (inBound(neighbor.first, neighbor.second, rooms.size(), rooms[i].size())) {
								if (rooms[neighbor.first][neighbor.second] != -1 && rooms[neighbor.first][neighbor.second] != 0) {
									if (level < rooms[neighbor.first][neighbor.second]) {
										rooms[neighbor.first][neighbor.second] = level;
										q.push({ neighbor,level });
									}
								}
							}
						}
					}
				}
			}
		}
	}

	bool inBound(int r, int c, int rows, int cols) {
		if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
		return true;
	}
};