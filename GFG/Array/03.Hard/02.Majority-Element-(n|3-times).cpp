// Majority Element (n/3 times)

class Solution {
    public List<Integer> majorityElement(int[] nums) {

        int n = nums.length;

        int cnt1 = 0, cnt2 = 0;
        int ele1 = Integer.MAX_VALUE;
        int ele2 = Integer.MAX_VALUE;

        // Step 1: Find potential candidates
        for (int num : nums) {
            if (num == ele1) {
                cnt1++;
            }
            else if (num == ele2) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                cnt1 = 1;
                ele1 = num;
            }
            else if (cnt2 == 0) {
                cnt2 = 1;
                ele2 = num;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify candidates
        int c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == ele1) c1++;
            if (num == ele2) c2++;
        }

        List<Integer> ans = new ArrayList<>();

        if (c1 > n / 3) ans.add(ele1);
        if (c2 > n / 3) ans.add(ele2);

        Collections.sort(ans);

        return ans;
    }
}

// =====================================================================================

#include <bits/stdc++.h>

vector<int> majorityElement(vector<int> v) {
  	// Write your code here
  	int n = v.size();
  
  	int cnt1=0, cnt2=0;
  	int ele1=INT_MAX, ele2=INT_MAX;
  
  	for(int i=0; i<n; i++) {
    		if(cnt1==0 && v[i]!=ele2) {
      			cnt1 = 1;
      			ele1 = v[i];
    		}
    		else if(cnt2==0 && v[i]!=ele1) {
      			cnt2 = 1;
      			ele2 = v[i];
    		}
    		else if(v[i] == ele1) {
    			  cnt1++;
    		}
    		else if(v[i] == ele2) {
    			  cnt2++;
    		}
    		else {
      			cnt1--;
      			cnt2--;
    		}
  	}
  
  	vector<int> ans;
  	int c1=0, c2=0;
  	for(auto i : v) {
    		if(i==ele1) c1++;
  		  if(i==ele2) c2++;
  	}
  
  	if(c1>n/3) ans.push_back(ele1);
  	if(c2>n/3) ans.push_back(ele2);
  
  	sort(ans.begin(),ans.end());
  	
  	return ans;
}
// T : O(N)
// S : O(1)


vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    //declaring a map:
    map<int,int> mpp;

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;

        //checking if v[i] is
        // the majority element:
        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }

    return ls;
}
// T : O(N * Log N)
// S : O(N)


vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}
// T : O(N^2)
// S : O(1)
