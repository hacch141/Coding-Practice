// 1814. Count Nice Pairs in an Array

class Solution {
public:

    int getReverse(int num) {
        int rev = 0;

        while(num > 0) {
            int digit = num%10;
            rev = (rev*10) + digit;
            num /= 10;
        }

        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num : nums) {
            int rev = getReverse(num);
            mp[num-rev]++;
        }

        int ans = 0;
        int mod = 1e9+7;
        for(auto i : mp) {
            int freq = i.second;
            ans = (ans + (1LL*freq*(freq-1))/2) % mod;
        }

        return ans;
    }
};





class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int num:nums) {
            int dup = num;
            int rev = 0;
            while(dup>0) {
                rev = rev*10 + dup%10;
                dup = dup/10;
            }
            ans+= mp[(num-rev)];
            ans = ans%1000000007;
            mp[(num-rev)]++;
        }
        return ans;
    }
};
