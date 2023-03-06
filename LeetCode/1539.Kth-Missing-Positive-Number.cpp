// 1539. Kth Missing Positive Number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        pair<int,int> p = {0,1};
        for(int i=0; i<n; i++) {
            while(p.second != arr[i]) {
                p.second++;
                p.first++;
                if(p.first == k) return p.second-1;
            }
            p.second++;
        }
        while(p.first != k) {
            p.first++;
            p.second++;
        }
        return p.second-1;
    }
};
