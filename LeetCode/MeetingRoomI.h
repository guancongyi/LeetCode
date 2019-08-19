class MeetingRoomISolution {
public:
	bool canAttendMeetings(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());

		for (size_t i = 0; i < intervals.size(); i++){
			if (i + 1 < intervals.size()) {
				if (intervals[i][1] > intervals[i + 1][0]) return false;
			}
		}

		return 1;
	}
};