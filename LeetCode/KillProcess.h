/*
Each process only has one parent process, but may have one or more children processes.
This is just like a tree structure. Only one process has PPID that is 0, 
which means this process has no parent process. 
All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes,
where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, 
return a list of PIDs of processes that will be killed in the end. 
You should assume that when a process is killed, all its children processes will be killed. 
No order is required for the final answer



Solution:

data structure: unordered_map<int, vector<int>>
it's like an adjacent list, each key is the ppid, value is a 
list of children process

*/



class KillProcessSolution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map<int, vector<int>> hash;
		
		for (size_t i = 0; i < ppid.size(); i++){
			auto it = hash.find(ppid[i]);
			if (it != hash.end()) {
				it->second.push_back(pid[i]);
			}
			else {
				vector<int> temp;
				temp.push_back(pid[i]);
				hash[ppid[i]] = temp;
			}
		}
		
		vector<int> ret;
		stack<int> s;
		s.push(kill);
		while (!s.empty()) {
			ret.push_back(s.top());
			auto it2 = hash.find(s.top());
			s.pop();
			if (it2 != hash.end()) {
				for (size_t i = 0; i < it2->second.size(); i++) {
					s.push(it2->second[i]);
				}
			}

		}			
		return ret;
		

	}
};