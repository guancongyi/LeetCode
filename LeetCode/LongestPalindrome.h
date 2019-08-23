class LongestPalindromeSolution {
public:
	string longestPalindromeExceedTime(string s) {
		pair<int, int> longest = {0,-1};
		int flag = true;

		for (int i = 0; i < s.length(); i++){
			int left = i;
			if (i + 1 == s.length()) break;
			for (int j = i+1; j < s.length(); j++){
				flag = true;
				int right = j;
				left = i;
				if (s[right] == s[left]) {
					while (left <= right) {
						if (s[right] != s[left]) { flag = false; break; }
						right--;
						left++;
					}
					if (flag == true) {
						if ((j - i) > (longest.second - longest.first)) {
							longest = { i,j };
							
						}
					}
				}

			}
		}
		if (longest.second-longest.first==-1)return s.substr(0,1);
		return s.substr(longest.first, longest.second - longest.first + 1);
	}

	/*
	There are 2 cases where a palindrome will be formed
	1. same as prev (keep going right)
	2. same as prev (left and right both move) 
	3. prev = next
	*/
	string longestPalindrome(string s) {
		pair<int, int> longest = { 0,-1 };
		char prev = 0, next = s.length()-1;
		int left, right;
		for (int i = 0; i < s.length(); i++){
			if ( (i - 1) >= 0) prev = s[i - 1];
			char cur = s[i];
			if ( (i + 1) < s.length()) next = s[i + 1];

			// case 1:
			if (cur == prev) {
				left = i-1; right = i;
				// check left and right to get the possible palindrome
				while (( right < s.length()) && s[left] == s[right]) { right++; }
				right--;
				if ((right - left ) > (longest.second - longest.first)) {
					longest = { left, right  }; i = right;
				}
			}
			// case 2:
			if (cur == prev) {
				left = i - 1 - 1; right = i+1;
				while ((left >= 0 && right < s.length()) && s[left] == s[right]) { left--; right++; }
				left++;
				right--;
				if ((right - left) > (longest.second - longest.first)) {
					longest = { left , right }; i = right;
				}
			}
			// case 3:
			if (prev == next) {
				left = i - 1; right = i + 1;
				while ((left >= 0 && right < s.length()) && s[left] == s[right]) {left--;right++;}
				left++;
				right--;
				if ((right - left ) > (longest.second - longest.first)) {
					longest = { left , right }; i = right;
				}
			}
		}

		if (longest.second - longest.first == -1)return s.substr(0, 1);
		return s.substr(longest.first, longest.second - longest.first + 1);
	}

};