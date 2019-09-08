

class MinAreaOfRectSolution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		// store x -> y1, y2, ...
		unordered_map<int, set<int, less<int>>> um;
		for (int i = 0; i < points.size(); i++) {
			auto it = um.find(points[i][0]);
			if (it == um.end()) {
				set<int, less<int>> temp;
				temp.insert(points[i][1]);
				um[points[i][0]] = temp;
			}
			else um[points[i][0]].insert(points[i][1]);
		}
		// go through each entry
		int area = INT_MAX;
		for ( auto i = um.begin(); i !=um.end(); i++){
			set<int> s1 = i->second;
			if (s1.size() < 1) continue;
			
			auto k = i;
			++k;
			for (auto j = k; j != um.end(); j++) {
				set<int> s2 = j->second;
				if (s2.size() < 2) continue;
				set<int, less<int>> intersect;
				set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
					inserter(intersect, intersect.begin()));

				if (intersect.size() < 2) continue;
	
				for (auto k = intersect.begin(); k != intersect.end(); k++) {
					auto next = k;
					++next;
					if(next!=intersect.end())area = min(area, abs(j->first - i->first) * abs(*next - *k));
				}	
			}
		}
		if (area == INT_MAX) return 0;
		return area;
	}
};