/*
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

Solution1:
use c++ string, find ] first, then split string, and create a new 
string block to replace the orignial encoded string.
kind of brutal force...


Solution2:
Using recursive, built a state machine inside the recursive function
pass the i by reference so that the value will be updated. This method took 
less memory but not faster.
*/


class DecodeStringSolution {
public:
	/*Iterative way*/
	string decodeString1(string s) {	
		while (1) {
			if (s.find_first_of(']') == string::npos) { break; }
			else {
				//find blocks
				int end = s.find_first_of(']');
				string right = s.substr(end + 1, s.length() - 1);
				string left = s.substr(0, end);
				int start = left.find_last_of('[');
				string block = left.substr(start + 1, end);

				//find count
				int numDigits = 0;
				int num = 0;

				int back = start - 1;
				while(isdigit(s[back])){
					int d = s[back] - '0';
					num += d*pow(10,numDigits);
					numDigits++;
					back--;
					if (back == -1) { back = 0; break; }
				}
				//concatenate
				string temp = "";
				for (size_t j = 0; j < num; j++){	temp += block;}

				//cout << block << " /" << temp << " /" << right << endl;
				s = left.substr(0, start - numDigits) + temp + right;
			}
			
		}

		return s;
		
	}

	string decodeString(string s) {
		int i = 0;
		return helper(i, s);
	}

	string helper(int &i, string s) {
		string block = "";
		int num = 0;
		for (;  i< s.length(); i++){
			char cur = s[i];
			if (cur == '['){
				string temp = helper(++i, s);
				for (size_t j = 0; j < num; j++) { block += temp; }
				num = 0;
				continue;
			}
			else if (cur == ']') {
				
				return block;
			}
			else if (isdigit(cur)) {
				if (num == 0) { num = cur - '0'; }
				else { num = num * 10 + cur - '0'; }
			}
			else {
				block += cur;
			}
		}
		return block;
	}

};