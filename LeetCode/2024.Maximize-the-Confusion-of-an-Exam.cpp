// 2024. Maximize the Confusion of an Exam


// Single Two Pointer
class Solution {
public:

    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0, r=0, cntT=0, cntF=0, n=answerKey.length(), ans=0;

        for(r=0; r<n; r++) {
            answerKey[r] == 'T' ? cntT++ : cntF++;
            while(l < r && cntT > k && cntF > k) {
                answerKey[l] == 'T' ? cntT-- : cntF--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};


// ==============================================================================

class Solution {
public:

    int helper(string answerKey, int k, char ch) {
        int l=0, r=0, cnt=0, n=answerKey.length(), ans=0;

        for(r=0; r<n; r++) {
            if(answerKey[r] == ch) {
                cnt++;
            }

            while(cnt > k) {
                if(answerKey[l] == ch) {
                    cnt--;
                }
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = helper(answerKey,k,'T');
        int f = helper(answerKey,k,'F');
        return max(t,f);
    }
};


