class Compare
{
public:
	bool operator() (const vector<int>& v1, const vector<int>& v2){
		return v1[1] > v2[1];
	}
};

class networkDelayTimeSolution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		unordered_map<int, vector<vector<int>>> adjList;
		map<int, int> weights;
		map<int, int> visited;
		for (int i = 0; i < times.size(); i++) {
			weights[times[i][0]] = INT_MAX;
			weights[times[i][1]] = INT_MAX;
			adjList[times[i][0]].push_back({ times[i][1], times[i][2] });
		}

		weights[K] = 0;
		priority_queue<vector<int>, std::vector<vector<int>>, Compare> pq;
		pq.push({ K,0 });

		while (pq.size() != 0) {
			auto cur = pq.top();
			pq.pop();
			//cout << cur[0] << endl;
			auto neighbors = adjList[cur[0]];
			if (visited[cur[0]]) continue;
			for (auto i = 0; i < neighbors.size(); i++) {
				auto neighbor = neighbors[i];
				if ((weights[cur[0]] + neighbor[1]) < weights[neighbor[0]])
					weights[neighbor[0]] = weights[cur[0]] + neighbor[1];
				pq.push({ neighbor[0],weights[cur[0]] + neighbor[1] });

			}
			visited[cur[0]] = 1;
		}

		int total = INT_MIN;
		for (auto i : weights) {
			total = max(total, i.second);
		}

		if (visited.size() != N) return -1;

		return total;
	}
};