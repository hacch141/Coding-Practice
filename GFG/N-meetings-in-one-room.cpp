class Solution
{
    public:
    
    struct meeting {
        int st;
        int end;
        int idx;
    };
    
    static bool compare(meeting m1, meeting m2) {
        if(m1.end == m2.end) {
            return m1.idx < m2.idx;
        }
        return m1.end < m2.end;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0; i<n; i++) {
            meet[i].st = start[i];
            meet[i].end = end[i];
            meet[i].idx = i;
        }
        
        sort(meet, meet+n, compare);
        int maxMeet = 1;
        int limit = meet[0].end;
        for(int i=1; i<n; i++) {
            if(meet[i].st > limit) {
                maxMeet++;
                limit = meet[i].end;
            }
        }
        return maxMeet;
    }
};
