class Contest {
	std::vector<int> scores;
	Contest& operator=(Contest);
public:
	Contest(std::vector<int> v) : scores{ v } {
		std::cout << "Before swapping the scores: ";
		//copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	void print_scores() {
		std::cout << "After swapping the scores: ";
		//copy(scores.begin(), scores.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	void swap(Contest& other);
};

class SubArrayProductLessThanKSolution {
public:
	int test(vector<int> nums, int k) {
		if (nums.size() == 0) return 0;
		int left = 0, mult = 1, count = 0;
		for (size_t right = 0; right < nums.size(); right++) {
			mult *= nums[right];
			while (left < right && mult >= k) {
				mult /= nums[left];
				left++;
			}
			if (mult < k)count += right - left + 1;
		}
		return count;
	}

	void swap_scores(std::vector<int> first, std::vector<int> second) {
		Contest first_contest(first);
		Contest second_contest(second);

		  /*
		   * 3. Swap the scores of the both the contest objects.
		   */
		vector<int>* ptr1 = (vector<int>*) & first_contest;
		vector<int>* ptr2 = (vector<int>*) & second_contest;
		swap(*ptr1, *ptr2);
		


	}
};