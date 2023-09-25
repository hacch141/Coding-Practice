// Job sequencing Problem

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compare(Job& j1, Job& j2) {
        return j1.profit > j2.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        int maxDeadline = INT_MIN;
        for(int i=0; i<n; i++) {
            maxDeadline = max(maxDeadline , arr[i].dead);
        }
        
        vector<int> check(maxDeadline+1,-1);
        int _profit = 0;
        int _jobs = 0;
        
        for(int i=0; i<n; i++) {
            int ind = arr[i].dead;
            for(int j=arr[i].dead; j>0; j--) {
                if(check[j] == -1) {
                    check[j] = arr[i].id;
                    _profit += arr[i].profit;
                    _jobs++;
                    break;
                }
            }
        }
        
        return {_jobs,_profit};
    } 
};

// T : O(N LogN)
// S : O(1)
