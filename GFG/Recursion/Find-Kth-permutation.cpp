class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> nums;
        int fact = 1;
        for(int i=1; i<n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k-1;
        string ans = "";
        while(true) {
            ans = ans + to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            if(nums.size() == 0) break;
            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};
