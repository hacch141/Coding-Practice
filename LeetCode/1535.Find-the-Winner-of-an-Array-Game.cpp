// 1535. Find the Winner of an Array Game

// pointer with mod n
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        for(auto i : arr) maxi = max(maxi,i);

        if(k >= n-1) {
            return maxi;
        }

        int currEle = arr[0];
        int cnt = 0;
        int ptr = 1;

        while(1) {
            if(currEle > arr[ptr % n]) {
                cnt++;
            }
            else {
                currEle = arr[ptr % n];
                cnt = 1;
            }

            if(currEle == maxi || cnt == k) {
                return currEle;
            }
            
            ptr++;
        }

        return -1;
    }
};


// =============================================================================================


// deque
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        for(auto i : arr) maxi = max(maxi,i);
        
        if(k >= n-1) {
            return maxi;
        }

        deque<int> dq;
        for(auto i : arr) {
            dq.push_back(i);
        }

        int cnt = 0;
        int first = dq.front();
        dq.pop_front();
        int second = dq.front();
        dq.pop_front();

        int currEle = max(first,second);
        dq.push_front(min(first,second));

        while(1) {
            int next = dq.front();
            dq.pop_front();
            if(currEle > next) {
                cnt++;
                if(cnt == k) {
                    return currEle;
                }
                dq.push_back(next);
            }
            else {
                dq.push_back(currEle);
                currEle = next;
                cnt = 1;
            }
        }

        return -1;
    }
};
