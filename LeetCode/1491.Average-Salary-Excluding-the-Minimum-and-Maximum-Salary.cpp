// 1491. Average Salary Excluding the Minimum and Maximum Salary

class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        double n = salary.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto i : salary) {
            ans += i;
            maxi = max(maxi,i);
            mini = min(mini,i);
        }
        ans = (ans-mini-maxi)/(n-2);
        return ans;
    }
};
