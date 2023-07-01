// 1539. Kth Missing Positive Number

// BS
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high) {
            int mid = (high-low)/2 + low;

            if(arr[mid]-mid-1 >= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // arr[high] + more
        // arr[high] + (k - misstill)
        // arr[high] + (k - ((arr[high] - high - 1)))
        // k + high + 1
        return low + k;
    }
};



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
