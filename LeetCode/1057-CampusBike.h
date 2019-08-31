/*

dist: a 2d matrix with distance and the worker's id
1,2 2,3
4,5 5,6

*/


class CampusBikeSolution {
public:
	bool comp() {

	}

	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {

		vector < vector<pair<int, int>> >dist(bikes.size(), vector<pair<int, int>>(workers.size(), { 0,0 }));
		
		for (int i = 0; i < bikes.size(); i++) {
			int xb = bikes[i][0], yb = bikes[i][1];
			for (int j = 0; j < workers.size(); j++) {
				int xw = workers[j][0], yw = workers[j][1];
				dist[i][j].first = abs(yb - yw) + abs(xb - xw);
				dist[i][j].second = j;
			}
			sort(dist[i].begin(), dist[i].end());
		}

		vector<int> res(workers.size());
		unordered_map<int, int> mp; // check if a bike has been assigned

		// for each worker, check the closest bike
		/*for (int i = 0; i < workers.size(); i++) {
			int best = INT32_MAX;
			int bestId;
			int j = 0;
			while (j < dist.size()) {
				if (dist[j][i] == 0) continue;
				if (dist[j][i] < best && mp.find(j) == mp.end()) {
					best = dist[j][i];
					bestId = j ;
				}
				j++;
			}
			res[i] = bestId;
			mp[bestId] = 1;
			
		}*/
		return res;
	}
};