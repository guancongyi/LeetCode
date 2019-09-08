/*
if board is 9*4, 
for each row, I only check from row 3 to row 6
for each col, I only check from col 2

*/


class CandyCrushSolution {
public:
	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		//int r_begin = 2;
		//int r_end = board.size() - 3;
		//int c_begin = 2;
		//int c_end = board[0].size() - 3;
		int rows = board.size()-1;
		int cols = board[0].size() - 1;

		int end = 0;
		while (!end) {
			//check vertically:
			vector<pair<int, int>> candies;

			for (size_t i = 0; i <= cols; i++)
			{
				int count1 = 0;
				int col = 0;
				while (col <= rows) {
					int curr = board[rows][col];
					while (1) {
						col++;
						if (col == rows) { break; }
						if (board[rows][col] == curr) {
							count1++;
						}
						else {
							if (count1 >= 3) {
								candies.push_back({ rows,col - 1 });
							}
							else {
								curr = board[rows][col];
							}
						}
					}
				}
				
			}

			
			

			//check horizontally:
			int j = 0;
			while (j <= cols) {
				//check left
				//check right
			}
			
			
		}
		

	}
};