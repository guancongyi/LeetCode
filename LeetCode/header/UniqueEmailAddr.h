class UniqueEmailAddrSolution {
public:
	int numUniqueEmails(vector<string>& emails) {
		int count = 0; int flag = 0;
		string cur, valid;
		unordered_map<string, int> um;
		for (int i = 0; i < emails.size(); i++) {
			cur = emails[i];
			for (int j = 0; j < cur.length(); j++) {
				if (cur[j] == '.' || (flag == 1 && cur[j] != '@'))continue;
				else if (cur[j] == '+') flag = 1;
				else if (cur[j] == '@') {
					valid += cur.substr(j, cur.length() - j - 1);
					break;
				}
				else valid += cur[j];
			}
			um[valid] = 1;
			flag = 0;
			valid = "";
		}
		return um.size();
	}
};