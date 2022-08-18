// 1338. Reduce Array Size to The Half

class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        for(auto i : mp) {
            pq.push(i.second);
        }
        int count = 0;
        for(int i=0; i<pq.size(); i++) {
            count += pq.top();
            pq.pop();
            if(count >= arr.size()/2) {
                return i+1;
            }
        }
        return 0;
    }
    
//     int minSetSize(vector<int>& arr) {  // 2nd Method
//         unordered_map<int,int> mp;
//         for(int i=0; i<arr.size(); i++) {
//             mp[arr[i]]++;
//         }
//         vector<int> freq;
//         for(auto i : mp) {
//             freq.push_back(i.second);
//         }
//         sort(freq.begin(),freq.end(),greater<int>());
//         int ans = 0;
//         int count = 0;
//         for(int i=0; i<freq.size(); i++) {
//             count += freq[i];
//             ans++;
//             if(count >= arr.size()/2) {
//                 return ans;
//             }
//         }
//         return 0;
//     }
};
