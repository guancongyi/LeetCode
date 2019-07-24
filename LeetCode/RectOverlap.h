/*
case1:
dumb solution, need to improve it!!!
there are 4 cases in total, overlap from four corners...
*/

class RectOverlapSolution {
public:
	bool isRectangleOverlap1(vector<int>& rec1, vector<int>& rec2) {
		int xLB = rec2[0], xRB = rec2[2];
		int yLB = rec2[1], yRB = rec2[1];
		int yLT = rec2[3], yRT = rec2[3];
		if ((rec2[0] > rec1[0] && rec2[0] < rec1[2]) && (rec2[1] > rec1[1] && rec2[1] < rec1[3])) { return true; }
		if ((rec2[1] > rec1[0] && rec2[1] < rec1[2]) && (rec2[2] > rec1[1] && rec2[2] < rec1[3])) { return true; }
		if ((rec2[0] == rec2[2]) || (rec1[0] == rec1[2]) || (rec2[1] == rec2[3]) || (rec1[1] == rec1[3])) { return false; }
		
		// overlap from left
		if ((xRB > rec1[0] && xLB < rec1[2]) && (yRT >= rec1[1]) && yRB <= rec1[3]) { return true; }
		// overlap from right
		if ((xRB > rec1[0] && xLB < rec1[2]) && (yLT >= rec1[1]) && yLB <= rec1[3]) { return true; }

		// overlap from outside
		if ((rec1[0] > rec2[0] && rec1[0] < rec2[2]) && (rec1[1] > rec2[1] && rec1[1] < rec2[3])) { return true; }
		if ((rec1[1] > rec2[0] && rec1[1] < rec2[2]) && (rec1[2] > rec2[1] && rec1[2] < rec2[3])) { return true; }

		return false;

	}

	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
		int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];

		return x1<x4 & x2 > x3 & y1 < y4 & y2 >y3;

	}
};