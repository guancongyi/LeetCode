class FlipAndInvertImageSolution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (size_t i = 0; i < A.size(); i++){
			reverse(A[i].begin(), A[i].end());
			vector<int> row = A[i];
			vector<int> elem;
			for (int it:row){
				elem.push_back(1-it);
			}
			A[i] = elem;

		}
		return A;
	}
};