class CountPrimesSolution {
public:
	int countPrimes(int n) {

		vector<int> tb(n, 1);
		for (int i = 3; i < n; i += 2) {
			for (int j = 3; i * j < n; j += 2) {
				tb[i * j] = 0;
			}
		}

		int count = 1;
		for (int i = 3; i < n; i += 2) {
			if (tb[i] == 1) {
				cout << i << endl;
				count++;
			}
		}
		if (n <= 2) return 0;
		return count;
	}


};