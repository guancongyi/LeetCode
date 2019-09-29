class FriendCircleSolution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		map<int, int> lut;
		int count = 0;
		for (int i = 0; i < M.size(); i++) {
			if (lut.find(i) == lut.end()) {
				//cout << count <<endl;
				count++;
				stack<int> s;
				s.push(i);
				lut[i] = i;

				while (s.size() != 0) {
					int cur = s.top();
					s.pop();
					//if(lut.find(cur) != lut.end()) continue;
					for (int j = 0; j < M[cur].size(); j++) {
						if (M[cur][j] == 1 && lut.find(j) == lut.end()) {
							lut[j] = cur;
							s.push(j);
						}
					}
				}
			}

		}
		return count;
	}
};