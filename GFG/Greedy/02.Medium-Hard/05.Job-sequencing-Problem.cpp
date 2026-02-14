// Job sequencing Problem

class Job {
    int id;
    int dead;
    int profit;

    Job(int id, int dead, int profit) {
        this.id = id;
        this.dead = dead;
        this.profit = profit;
    }
}

class Solution {

    // DSU Find with Path Compression
    private int find(int s, int[] parent) {
        if (parent[s] == s)
            return s;
        return parent[s] = find(parent[s], parent);
    }

    public int[] JobScheduling(Job[] arr, int n) {

        // 1️⃣ Sort jobs by profit descending
        Arrays.sort(arr, (a, b) -> b.profit - a.profit);

        // 2️⃣ Find maximum deadline
        int maxDeadline = 0;
        for (Job job : arr) {
            maxDeadline = Math.max(maxDeadline, job.dead);
        }

        // 3️⃣ Initialize DSU
        int[] parent = new int[maxDeadline + 1];
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int totalProfit = 0;
        int totalJobs = 0;

        // 4️⃣ Process jobs
        for (Job job : arr) {

            int availableSlot = find(job.dead, parent);

            if (availableSlot > 0) {
                totalProfit += job.profit;
                totalJobs++;

                // Mark this slot as filled
                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }

        return new int[]{totalJobs, totalProfit};
    }
}

// ======================================================================

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
