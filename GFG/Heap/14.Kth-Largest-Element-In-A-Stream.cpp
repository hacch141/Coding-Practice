// Kth Largest Element In A Stream

#include <algorithm>

class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) {
        for(auto i : arr) {
            pq.push(i);
            while(pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int num) {
        pq.push(num);
        pq.pop();
        return pq.top();
    }

};

// T : O(N*LogN)
// S : O(N)
