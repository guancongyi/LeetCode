/*
First sort the vector according to starting time
Then, use min heap to keep track of the end time

Find the room that can be vacate first when allocating.
*/

class myComparator
{
public:
	int operator() (const vector<int>& v1, const vector<int>& v2)
	{
		return v2[1] < v1[1];
	}
};

class MeetingRoomIISolution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		// sort base on starting time
		sort(intervals.begin(), intervals.end());

		// add to min heap
		int rooms = 0;
		priority_queue<vector<int>, vector<vector<int>>, myComparator> pq;
		vector<int> min_, cur;
		for (size_t i = 0; i < intervals.size(); i++) {
			cur = intervals[i];
			pq.push(cur);
			min_ = pq.top();

			if (cur[0] < min_[1]) { rooms++; }
			if (cur[0] >= min_[1]) { pq.pop(); }

		}

		return rooms;
	}
};
