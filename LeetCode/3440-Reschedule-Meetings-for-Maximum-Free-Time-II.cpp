// 3440. Reschedule Meetings for Maximum Free Time II

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0;
        
        int left_mx_gap = 0;
        for(int i = 0; i < n; i++) {
            int meet_dur = endTime[i] - startTime[i];
            int left_end = i > 0 ? endTime[i - 1] : 0;
            int right_st = i + 1 < n ? startTime[i + 1] : eventTime;
            int total_dur = right_st - left_end;

            if(meet_dur > left_mx_gap) {
                total_dur -= meet_dur;
            }

            ans = max(ans, total_dur);
            left_mx_gap = max(left_mx_gap, startTime[i] - left_end);
        }

        int right_mx_gap = 0;
        for(int i = n - 1; i >= 0; i--) {
            int meet_dur = endTime[i] - startTime[i];
            int left_end = i > 0 ? endTime[i - 1] : 0;
            int right_st = i + 1 < n ? startTime[i + 1] : eventTime;
            int total_dur = right_st - left_end;

            if(meet_dur > right_mx_gap) {
                total_dur -= meet_dur;
            }

            ans = max(ans, total_dur);
            right_mx_gap = max(right_mx_gap, right_st - endTime[i]);
        }

        return ans;
    }
};
