/*
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. 
Note the answer is not 11, because the island must be connected 4-directionally.

Solution:
DFS:
iterate through every number in the matrix,
whenever see 1, the DFS will start, and mark every node it visited.

*/

class MaxAreaOfIslandSolution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		vector<vector<int>> visited(rows, vector<int>(cols));
		int maxArea = 0;
		for (size_t i = 0; i < rows; i++){
			for (size_t j = 0; j < cols; j++) {
				if (grid[i][j] == 0 || visited[i][j] == 1) {
					continue;
				}
				else {
					//DFS
					vector<pair<int,int>> myStack;
					myStack.push_back({i,j});
				
					int count = 0;
					while (myStack.size() > 0) {
						pair<int,int> curr = myStack.back();
						myStack.pop_back();
						count++;
						int r = curr.first;
						int c = curr.second;
						visited[r][c] = 1;

						int up = (r == 0) ? 0 : r - 1;
						int down = (r == rows-1) ? rows-1 : r + 1;
						int left = (c == 0) ? 0 : c - 1;
						int right = (c == cols-1) ? cols-1 : c + 1;
						
						if (grid[r][left] == 1 && visited[r][left] != 1) {
							myStack.push_back({ r,c-1 });
							visited[r][left] = 1;
						}
						if (grid[r][right] == 1 && visited[r][right] != 1) {
							myStack.push_back({ r,right });
							visited[r][right] = 1;
						}
						if (grid[up][c] == 1 && visited[up][c] != 1) {
							myStack.push_back({ up,c });
							visited[up][c] = 1;
						}
						if (grid[down][c] == 1 && visited[down][c] != 1) {
							myStack.push_back({ down,c });
							visited[down][c] = 1;
						}
					}
					if (count > maxArea) {
						maxArea = count;
					}
				}
			}
		}
		return maxArea;
		
	}
};

class NumOfIslandSolution {
public:
	int numIslands(vector<vector<char>>& grid) {
		
		int M = grid.size();
		if (M == 0)return 0;
		int N = grid[0].size();
		int num = 0;
		vector<vector<int>> visited(M, vector<int>(N, 0));
		stack<pair<int, int>> s;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] || grid[i][j]=='0') continue;
				else {
					
					s.push({ i,j });
					visited[i][j] = 1;

					// dfs
					while (!s.empty()) {
						pair<int, int> cur = s.top();
						s.pop();
						int x = cur.first, y = cur.second;

						if ((x + 1) < M) { if (grid[x + 1][y] == '1' & !visited[x + 1][y]) s.push({ x + 1,y }); visited[x + 1][y] = 1; }
						if ((x - 1) >= 0) { if (grid[x - 1][y] == '1' & !visited[x - 1][y]) s.push({ x - 1, y }); visited[x - 1][y] = 1; }
						if ((y + 1) < N) { if (grid[x][y + 1] == '1' && !visited[x][y + 1]) s.push({ x, y + 1 }); visited[x][y + 1] = 1; }
						if ((y - 1) >= 0) { if (grid[x][y - 1] == '1' && !visited[x][y - 1]) s.push({ x, y - 1 }); visited[x][y - 1] = 1; }
						
					}
					num++;
				}
			}
		}

		return num;
	}
};