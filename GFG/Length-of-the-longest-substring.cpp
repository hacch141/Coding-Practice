// Length of the longest substring

class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int n = S.length();
        vector<int> mpp(256,-1);
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right<n) {
            if(mpp[S[right]] != -1) {
                left = max(left,mpp[S[right]]+1);
            }
            mpp[S[right]] = right;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};


class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int> prev(256,-1);
        int n = S.length();
        int i = 0;
        int ans = 0;
        
        for(int j=0; j<S.length(); j++) {
            i = max(i,prev[S[j]]+1);
            int maxend = j-i+1;
            ans = max(ans,maxend);
            prev[S[j]] = j;
        }
        return ans;
    }
};
