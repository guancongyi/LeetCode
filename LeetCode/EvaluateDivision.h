/*
My solution:
first build the hash table with the structure below:
"a" ----- {"b", 2} 
"b" ----- {"a", 0.5} 
"c" ----- {"b", 1/3}
...

There are 2 situations:
1 n n simply insert 2 nodes to the map
2 y n insert 2 nodes and loop through one of them to find the relationship of exisiting itmes
and new coming items


Then loop through queries 

*/



class EvaluateDivisionSolution {
public:
	/*totally wrong answer
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		// Biuld map
		unordered_map<string, vector<pair<string, double>>> hash;
		string up, down;
		double val;
		for (size_t i = 0; i < equations.size(); i++){
			up = equations[i][0], down = equations[i][1];
			val = values[i];

			auto it1 = hash.find(up);
			auto it2 = hash.find(down);

			if (it1 == hash.end() && it2 == hash.end()) {
				vector<pair<string, double>> temp1({ { down, val } });
				vector<pair<string, double>> temp2({ { up, 1/val } });
				hash[up] = temp1;
				hash[down] = temp2;
			}
			// up exist, down doesn't
			if (it1 != hash.end() && it2 == hash.end()) {
				vector<pair<string, double>> temp({ {up, 1/val } });
				hash[down] = temp;

				vector<pair<string, double>> cur = it1->second;
				for (size_t j = 0; j < cur.size(); j++) {
					hash[cur[j].first].push_back({ down, (val / cur[j].second) });
				}
				hash[up].push_back({ down, val });
			}
			// on the other hand
			else if(it1 == hash.end() && it2 != hash.end()) {
				vector<pair<string, double>> temp({ { down, val } });
				hash[up] = temp;

				vector<pair<string, double>> cur = it2->second;
				for (size_t j = 0; j < cur.size(); j++) {
					hash[cur[j].first].push_back({ up, ( (1/val)/ cur[j].second) });
				}
				
				hash[down].push_back({ up, 1/val });
			}
		}

		// Query
		vector<double> ret;
		for (size_t j = 0; j < queries.size(); j++){
			up = queries[j][0];
			down = queries[j][1];
			auto q1 = hash.find(up);
			auto q2 = hash.find(down);
			if (q1 == hash.end() || q2 == hash.end()) { ret.push_back(-1.0); }
			else if (up == down && q1 == hash.end()){ ret.push_back(-1.0); }
			else {
				if (up == down) { ret.push_back(1.0); }
				else {
					int found = 0;
					vector<pair<string, double>> cur = hash[up];
					for (size_t i = 0; i < cur.size(); i++){
						if (cur[i].first == down) {
							ret.push_back(cur[i].second);
							found = 1;
							break;
						}
					}
					if (!found) {
						cur = hash[down];
						for (size_t i = 0; i < cur.size(); i++) {
							if (cur[i].first == up) {
								ret.push_back((1 / cur[i].second));
								break;
							}
						}
					}
					
				}
			}
		}

		return ret;
		
	}*/

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		map<string, string> sets;
		vector<string, vector<pair<string, double>>> tb;
		for (size_t i = 0; i < equations.size(); i++){
			string up = equations[i][0];
			string down = equations[i][1];

			
		}

	}
	
};