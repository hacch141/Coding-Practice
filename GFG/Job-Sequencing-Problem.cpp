class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool compare(Job a, Job b) {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        int lastDead = arr[0].dead;
        for(int i=1; i<n; i++) {
            lastDead = max(lastDead,arr[i].dead);
        }
        
        vector<int> check(lastDead+1,-1);
        
        int cntJobs = 0;
        int maxProfit = 0;
        for(int i=0; i<n; i++) {
            for(int j=arr[i].dead; j>0; j--) {
                if(check[j] == -1) {
                    check[j] = arr[i].id;
                    maxProfit += arr[i].profit;
                    cntJobs++;
                    break;
                }
            }
        }
        return {cntJobs,maxProfit};
    } 
};
