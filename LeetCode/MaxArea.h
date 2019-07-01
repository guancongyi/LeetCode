/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

method 1:
n^2

method 2:
left and right pointer
1. check left and right
2. check left left, and right right

*/

class SolutionMaxArea {
public:
	int maxArea(vector<int>& height) {
		/*
		int len = height.size();
		int maxArea = 0;
		// iterate the array(n*n)
		for (size_t i = 0; i < len; i++)
		{
			int h = height[i];
			for (size_t j = i ; j < len; j++)
			{
				int w = j - i;
				int area;
				if (height[i] < height[j]) {
					area = h * w;
				}
				else {
					area = height[j] * w;
				}
				
				if (area >= maxArea) { maxArea = area; }
			}
		}

		return maxArea;
		*/

		int maxArea = 0;
		int l = 0, r = height.size()-1;

		while (l < r) {
			maxArea = max(maxArea, min(height[l],height[r])*(r-l));
			if (height[l] > height[r]) {
				r--;
			}
			else {
				l++;
			}

		}
		return maxArea;

	}

	int max(int max, int value) {
		if (value >= max) {
			return value;
		}
		return max;
	}

	int min(int v1, int v2) {
		if (v1 < v2) {
			return v1;
		}
		return v2;
	}

	
};