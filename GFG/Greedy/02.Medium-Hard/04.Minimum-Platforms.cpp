// Minimum Platforms

// sweep algo
class Solution {

    public int findPlatform(int[] arr, int[] dep, int n) {

        TreeMap<Integer, Integer> map = new TreeMap<>();

        for (int i = 0; i < n; i++) {

            // Arrival → +1 platform
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);

            // Departure → -1 platform (at dep + 1)
            map.put(dep[i] + 1, map.getOrDefault(dep[i] + 1, 0) - 1);
        }

        int curr = 0;
        int maxPlatforms = 0;

        for (int change : map.values()) {
            curr += change;
            maxPlatforms = Math.max(maxPlatforms, curr);
        }

        return maxPlatforms;
    }
}

class Solution {

    public int findPlatform(int[] arr, int[] dep, int n) {

        // Time ranges from 0000 to 2359 → so 2461 is safe buffer
        int[] timeline = new int[2461];

        for (int i = 0; i < n; i++) {
            timeline[arr[i]]++;        // train arrives
            timeline[dep[i] + 1]--;    // train departs
        }

        int curr = 0;
        int maxPlatforms = 0;

        for (int i = 0; i < 2461; i++) {
            curr += timeline[i];
            maxPlatforms = Math.max(maxPlatforms, curr);
        }

        return maxPlatforms;
    }
}

// ======================================================================

    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> pt(2461,0);
    	
    	for(int i=0; i<n; i++) {
    	    pt[arr[i]]++;
    	    pt[dep[i]+1]--;
    	    
    	}
    	
    	int curr = 0, ans=1;
    	for(auto i : pt) {
    	    curr += i;
    	    ans = max(ans,curr);
    	}
    	
    	return ans;
    }
// T : O(N)
// S : O(1)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=0, j=0, ans=0;
    	while(j<n) {
    	    while(i<n && arr[i] <= dep[j]) {
    	        i++;
    	    }
    	    ans = max(ans,i-j);
    	    j++;
    	}
    	
    	return ans;
    	
    }
};

// T : O(N LogN)
// S : O(1)
