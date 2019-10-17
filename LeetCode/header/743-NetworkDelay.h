class Compare
{
public:
	bool operator() (const vector<int>& v1, const vector<int>& v2)
	{
		return v1[2] > v2[2];
	}
};

class networkDelayTimeSolution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		unordered_map<int, vector<vector<int>>> adjList;
		map<int, int> weights;
		map<int, int> visited;
		for (int i = 0; i < times.size(); i++) {
			if (adjList.find(times[i][0]) == adjList.end()) {
				vector<vector<int>> temp = { {times[i][0], times[i][1], times[i][2]} };
				adjList[times[i][0]] = temp;
				weights[times[i][0]] = INT_MAX;
				weights[times[i][1]] = INT_MAX;
			}
			else
				adjList[times[i][0]].push_back({ times[i][0], times[i][1], times[i][2] });
		}

		weights[K] = 0;
		priority_queue<vector<int>, std::vector<vector<int>>, Compare> pq;
		pq.push({ K,K,0 });

		while (pq.size() != 0) {
			auto cur = pq.top();
			pq.pop();
			visited[cur[1]] = 1;
			auto neighbors = adjList[cur[1]];
			for (auto i = 0; i < neighbors.size(); i++) {
				auto neighbor = neighbors[i];
				if (!visited[neighbor[1]]) {
					if ((weights[neighbor[0]] + neighbor[2]) < weights[neighbor[1]])
						weights[neighbor[1]] = weights[neighbor[0]] + neighbor[2];
					pq.push(neighbor);
				}
			}
		}

		int total = INT_MIN;
		for (auto i : weights) {
			total = max(total, i.second);
		}

		if (visited.size() != N) return -1;

		return total;
	}
};