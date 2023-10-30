// 1356. Sort Integers by The Number of 1 Bits

class Solution {
public:

    static int n_bits(int a) {
        int cnt = 0;
        while(a > 0) {
            a = a&(a-1);
            cnt++;
        }
        return cnt;
    }

    static bool compare(int a, int b) {
        int cnt_a = n_bits(a);
        int cnt_b = n_bits(b);
        if(cnt_a == cnt_b) {
            return a < b;
        }
        return cnt_a < cnt_b;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>>temp;
        for(auto &val: arr)
        {
            int x=val;
            int cnt=0;
            while(x!=0)
            {
                x=x&(x-1);
                cnt++;
            }
            temp.push_back({cnt,val});
            
        }

        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            arr[i]=temp[i].second;
        }
        return arr;
    }
};
