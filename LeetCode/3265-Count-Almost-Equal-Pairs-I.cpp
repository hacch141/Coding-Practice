// 3265. Count Almost Equal Pairs I

class Solution {
public:

    bool ok(int a, int b) {
        if(a == b) return true;

        int a1, b1, a2, b2, cnt = 0;
        while(a != 0 || b != 0) {
            int l1 = a % 10, l2 = b % 10;
            a /= 10, b /= 10;
            if(l1 != l2) {
                cnt++;
                if(cnt == 1) {
                    a1 = l1, b1 = l2;
                }
                else if(cnt == 2) {
                    a2 = l1, b2 = l2;
                }
            }
        }

        if(cnt == 2) {
            return (a1 == b2) && (a2 == b1);
        }
        
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                cnt += ok(nums[i], nums[j]);
            }
        }
        return cnt;
    }
};

// ===============================================================================


class Solution {
public:
    bool ok(int a, int b) {
        string num1 = to_string(a), num2 = to_string(b);
        int len1 = num1.length(), len2 = num2.length();
        if(len1 < len2) {
            swap(num1, num2);
            swap(len1, len2);
        }

        string zr = "";
        for(int i = 0; i < (len1 - len2); i++) zr += '0';
        num2 = zr + num2;

        vector<int> v;
        for(int i = 0; i < len1; i++) {
            if(num1[i] != num2[i]) v.push_back(i);
        }

        if(v.size() == 0) return true;

        if(v.size() == 2) {
            return (num1[v[0]] == num2[v[1]]) && (num1[v[1]] == num2[v[0]]);
        }
        
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                cnt += ok(nums[i], nums[j]);
            }
        }
        return cnt;
    }
};
