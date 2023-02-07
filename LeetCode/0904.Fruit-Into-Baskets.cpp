// 904. Fruit Into Baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int maxi = 0;
        int cnt = 0;
        int ptr = 0;
        
        for(int i=0; i<n; i++) {
            mp[fruits[i]]++;
            cnt++;
            if(mp.size() <= 2) {
                maxi = max(maxi,cnt);
            }

            while(mp.size()>2) {
                mp[fruits[ptr]]--;
                cnt--;
                if(mp[fruits[ptr]] == 0) mp.erase(fruits[ptr]);
                ptr++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
}; 





// ============================================

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int maxi = 0;
        int cnt = 0;
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            mp[fruits[i]]++;
            q.push(fruits[i]);
            if(mp.size()>2) {
                while(mp.size()>2) {
                    int remove = q.front();
                    q.pop();
                    mp[remove]--;
                    cnt--;
                    if(mp[remove] == 0) mp.erase(remove);
                }
            }
            if(q.size()>maxi) maxi = q.size();
        }
        return maxi;
    }
}; 
