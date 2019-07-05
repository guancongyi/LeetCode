/*
Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

*/


class FlipAndInvertImageSolution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (size_t i = 0; i < A.size(); i++){
			//reverse(A[i].begin(), A[i].end());
			for (size_t j = 0; j <= (A[i].size()-1)/2; j++)
			{
				int end = A[i].size()-1-j;
				int front = j;
				int temp = A[i][end];
				if (front == end) {
					A[i][end] = 1 - A[i][end];
				}
				else if(front < end){
					A[i][end] = A[i][front];
					A[i][front] = temp;
					A[i][end] = 1-A[i][end];
					A[i][front] =1- A[i][front];
				}				
			}

		}
		return A;
	}
};