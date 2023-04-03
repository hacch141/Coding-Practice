// 881. Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int low = 0;
        int high = people.size()-1;
        int ans = 0;
        while(low<=high) {
            if(low==high) {
                ans++;
                break;
            }
            if(people[low]+people[high] <= limit) {
                ans++;
                low++;
                high--;
            }
            else {
                ans++;
                high--;
            }
        }
        return ans;
    }
};
