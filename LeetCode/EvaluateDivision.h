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
		map<string, double> coeffs;
		//unordered_map<string, vector<string>> tb;
		for (size_t i = 0; i < equations.size(); i++){
			string up = equations[i][0];
			string down = equations[i][1];
			double val = values[i];
			auto numer = sets.find(up);
			auto denom = sets.find(down);
			// case 1: both do not exist in any set.
			if (numer == sets.end() && denom == sets.end()) {
				sets[up] = up, sets[down] = up;
				coeffs[up] = 1.0, coeffs[down] = val;
				//vector<string> temp({ up, down });
				//tb[up] = temp;
			}
			// case 2: both exist
			if ((numer != sets.end() && denom != sets.end()) && (numer->second!=denom->second)) {
				string numerP = numer->second;
				string denomP = denom->second;
				if (numerP == denomP) { continue; }
				// merge the parents in the table

				// find the coeff
				double coeff = val * coeffs[up] / coeffs[down];
				// update the coeffs and change parent in sets
				for (auto x : sets) {
					if (x.second == denomP) {
						sets[x.first] = numerP;
						coeffs[x.first] = coeffs[x.first] * coeff;
					}
				}
				// merge ???
				//tb[up].insert(tb[up].end(), tb[down].begin(), tb[down].end());
			}
			// case 3: one exists
			if ((numer != sets.end() || denom != sets.end()) && (!(numer != sets.end() && denom != sets.end()))) {
				if (numer == sets.end()) {
					//numer add to denom
					// add coeffs first
					coeffs[up] = coeffs[down]/val;
					// add to sets
					sets[up] = sets[down];
					// update table ???
					//tb[down].push_back(up);
				}
				else {
					coeffs[down] = coeffs[up] * val;
					sets[down] = sets[up];
					//tb[up].push_back(down);
				}
			}
			
		}

		// Query
		vector<double> ret;
		for (size_t k = 0; k < queries.size(); k++){
			auto it1 = sets.find(queries[k][0]);
			auto it2 = sets.find(queries[k][1]);
			if ((it1 == sets.end() || it2 == sets.end()) && (queries[k][0] != queries[k][1])) { ret.push_back(-1.0); continue; }
			if ((it1 == sets.end() && it2 == sets.end())) { ret.push_back(-1.0); continue; }
			if ((it1->second == it2->second) ) {
				ret.push_back(coeffs[it2->first] / coeffs[it1->first]);
			}
			else {
				ret.push_back(-1.0);
			}
		}
		return ret;

	}
	
};