class CountingBitsSolution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num + 1, -1);
		int twos = 2;
		while (twos <= num) {
			dp[twos] = 1;
			twos *= 2;
		}


		int val = 3;
		int base;
		for (int i = 0; i < num + 1; i++) {
			if (i == 0) dp[i] = 0;
			if (i == 1) dp[i] = 1;

			if (dp[i] != -1) base = i;
			else dp[i] = dp[base] + dp[i - base];

		}
		return dp;
	}

};