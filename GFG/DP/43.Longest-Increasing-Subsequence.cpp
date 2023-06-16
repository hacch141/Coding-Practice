// Longest Increasing Subsequence

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       int ans = 1;
       vector<int> dp(n,1);
       vector<int> temp;
       temp.push_back(a[0]);
       for(int i=1; i<n; i++) {
           if(a[i]>temp.back()) {
               temp.push_back(a[i]);
               ans++;
           }
           else {
               int ind = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
               temp[ind] = a[i];
           }
       }
       return ans;
    }
};
