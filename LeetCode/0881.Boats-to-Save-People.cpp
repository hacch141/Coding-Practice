// 881. Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), l = 0, r = n - 1, boat = 0;
        while(l <= r) {
            if(l == r || (people[l] + people[r] <= limit)) {
                l++;
            }
            r--;
            boat++;
        }
        return boat;
    }
};
