// 473. Matchsticks to Square

class Solution {
public:
    
    bool already(vector<int> sides, int pos) {
        for(int i=0; i<pos; i++) {
            if(sides[i]==sides[pos]) 
                return true;
        }
        return false;
    }
    
    bool recurse(vector<int> sides, int pos, int target, vector<int> v) {
        if(pos == v.size()) {
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        }
        for(int i=0; i<4; i++) {
            if(sides[i]+v[pos]>target || already(sides, i)) {
                continue;
            }
            sides[i] += v[pos];
            if(recurse(sides, pos+1, target, v)) {
                return true;
            }
            sides[i] -= v[pos];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) { 
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        vector<int> sides(4, 0);
        
        if(sum%4 || matchsticks.size()<4 || matchsticks[0]>(sum/4)) {
            return false;
        }
        
        return recurse(sides, 0, sum/4, matchsticks);
    }
};
