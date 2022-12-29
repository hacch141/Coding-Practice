// 1834. Single-Threaded CPU

class Solution {
public:

    struct compare{
        bool operator()(pair<int,int> p1, pair<int,int> p2) {
            // if pair have same processingTimei then we will consider task with the smallest index
            if(p1.second == p2.second) {
                // return lesser index task
                return p1.first > p2.first;
            }
            // return lesser processingTime task
            return p1.second > p2.second;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> v(n, vector<int> (3));
        for(int i=0; i<n; i++) {
          
            // v[i][0] = enqueueTimei of ith task
            // v[i][1] = processingTimei of ith task
            // v[i][2] = index of ith task
            v[i] = { tasks[i][0] , tasks[i][1] , i };
        }
      
        // sort them according to enqueueTimei of task
        sort(v.begin(),v.end());

        int cnt = 0;
        long long time = v[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;
        vector<int> ans;
      
        while(true) {
          
            // if task is sufficient to enter by enqueueTime
            // then push it to the priority queue
            while(cnt<n && v[cnt][0]<=time) {
                pq.push({v[cnt][2],v[cnt][1]});
                cnt++;
            }
          
            //  the CPU is idle and there are no available tasks to process
            //  it will add next task after required time
            if(pq.empty() && cnt<n) {
                pq.push({v[cnt][2],v[cnt][1]});
                time = v[cnt][0];
                cnt++;
            } 
            // CPU is not idel and have task to perform
            else {
                auto curr = pq.top();
                pq.pop();
                ans.push_back(curr.first);
                time += curr.second;
            }
            // all task are inserted into pq
            // and also successfully completed them
            // time to break the loop all done...
            if(pq.empty() && cnt==n) break;
        }
        return ans;
    }
};
