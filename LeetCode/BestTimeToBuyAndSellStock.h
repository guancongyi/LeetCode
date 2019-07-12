class BestProfitSolution {
public:
	int maxProfit(vector<int>& prices) {
		int lowest = 100000;
		int best = 0;
		for (size_t i = 0; i < prices.size(); i++){
			lowest = (prices[i] < lowest) ? prices[i] : lowest;
			if (i == 0) { continue; }
			else {
				best = (best <= (prices[i] - lowest)) ? (prices[i] - lowest) : best;
			}
		}
		return best;
	}
};