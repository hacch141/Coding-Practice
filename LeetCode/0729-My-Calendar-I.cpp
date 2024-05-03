// 729. My Calendar I

class MyCalendar {
public:

    set<pair<int,int>> st;
    MyCalendar() {
        
    }

    bool isOverlap(int s1, int e1, int s2, int e2) {
        return !(e1 <= s2 || e2 <= s1);
    }
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end});
        if(it != st.end()) {
            pair<int,int> p1 = *it;
            if(isOverlap(start, end, p1.first, p1.second)) return false;
        }
        if(it != st.begin()) {
            it--;
            pair<int,int> p2 = *it;
            if(isOverlap(start, end, p2.first, p2.second)) return false;
        }
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
