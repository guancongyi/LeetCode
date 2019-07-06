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