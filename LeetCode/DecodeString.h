/*
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

Solution:
use c++ string, find ] first, then split string, and create a new 
string block to replace the orignial encoded string.
kind of brutal force...

*/


class DecodeStringSolution {
public:
	string decodeString(string s) {
		string ret = "";

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

				string newLeft = left.substr(0, start-numDigits);
				//concatenate
				string temp = "";
				for (size_t j = 0; j < num; j++){	temp += block;}

				//cout << block << " /" << temp << " /" << right << endl;
				ret = newLeft + temp + right;
			}
			s = ret;
		}

		return s;
		
	}
};