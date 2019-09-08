/*
My solution is to use linked list, with its build in sort function
 
A better solution:
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char,int> freq;
		vector<string> bucket(s.size()+1, "");
		string res;

		//count frequency of each character
		for(char c:s) freq[c]++;
		//put character into frequency bucket
		for(auto& it:freq) {
			int n = it.second;
			char c = it.first;
			bucket[n].append(n, c);
		}
		//form descending sorted string
		for(int i=s.size(); i>0; i--) {
			if(!bucket[i].empty())
				res.append(bucket[i]);
		}
		return res;
	}
};
*/
struct MyNode {
	MyNode() {}

	MyNode(pair<char, int> p) {
		ch = p.first;
		val = p.second;
	}

	bool operator < (MyNode & n2) {
		return val < n2.val;
	}

	int val;
	char ch;
};

class SortCharByFreqSolution {
public:
	string frequencySort(string s) {
		list<MyNode>::iterator front, back;

		list<MyNode> l;
		
		unordered_map<char, list<MyNode>::iterator> mp;

		MyNode a({ s[0], 1 });
		l.push_back(a);
		front = l.begin();
		back = l.end();
		mp[s[0]] = front;
		
		for (size_t i = 1; i < s.length(); i++){
			auto it = mp.find(s[i]);
			// found
			if (it != mp.end()) {
				// update the value
				it->second->val+= 1;
				int count = it->second->val;	
			}
			// not found
			else {
				MyNode b({ s[i], 1 });
				l.push_back(b);
				mp[s[i]] = --l.end();
			}

		}
		l.sort();
		l.reverse();

		// concatenate
		string ret = "";
		for (auto k = l.begin(); k != l.end(); k++){
			for (int l = 0; l < k->val; l++) {
				ret += k->ch;
			}
		}
		return ret;
	}

};