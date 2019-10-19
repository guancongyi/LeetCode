class CheapestFlightWithKStopsSolution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		map<int, vector<vector<int>>> adjList;
		map<int, int> visited;
		for (int i = 0; i < flights.size(); i++) {
			int u = flights[i][0]; int v = flights[i][1]; int w = flights[i][2];
			adjList[u].push_back({ v, w });
		}

		queue<vector<int>> q;
		q.push({ src, 0 });

		int level = -1;
		int ret = INT_MAX;
		while (q.size() != 0) {
			int n = q.size();
			level++;
			for (int i = 0; i < n; i++) {
				auto cur = q.front(); q.pop();
				int u = cur[0], currCost = cur[1];

				if (u == dst) ret = min(ret, currCost);
				//if(visited[u]) continue;
				for (int j = 0; j < adjList[u].size(); j++) {
					int v = adjList[u][j][0], cost = adjList[u][j][1];
					if (ret > (currCost + cost)) {
						q.push({ v,currCost + cost });
					}
				}
				//visited[u] = 1;
			}
			if (level > K) break;
		}
		return (ret == INT_MAX) ? -1 : ret;

	}
};