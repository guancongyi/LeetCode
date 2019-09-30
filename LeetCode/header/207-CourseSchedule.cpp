class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		map<int, vector<int>> graph;
		map<int, int> degrees;
		for (int i = 0; i < prerequisites.size(); i++) {
			int first = prerequisites[i][0];
			int sec = prerequisites[i][1];
			if (graph.find(first) == graph.end()) graph[first] = { sec };
			else graph[first].push_back(sec);
		}
		for (int i = 0; i < prerequisites.size(); i++) {
			int first = prerequisites[i][0];
			int sec = prerequisites[i][1];
			if (degrees.find(first) == degrees.end()) {
				degrees[first] = 0;
				if (degrees.find(sec) == degrees.end()) degrees[sec] = 1;
				else degrees[sec]++;
			}
			else {
				if (degrees.find(sec) == degrees.end()) degrees[sec] = 1;
				else degrees[sec]++;
			}
		}


		stack<int> s;
		for (auto it : degrees) {
			if (it.second == 0) s.push(it.first);
		}


		// sort
		int count = 0;
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			count++;
			vector<int> children = graph[cur];
			for (int j = 0; j < children.size(); j++) {
				degrees[children[j]] -= 1;
				if (degrees[children[j]] == 0) {
					s.push(children[j]);
				}
			}
		}

		cout << count;

		if (numCourses >= count && count == degrees.size()) return true;
		return false;
	}
};