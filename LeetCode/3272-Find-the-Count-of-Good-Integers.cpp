// 3272. Find the Count of Good Integers

class Solution {
public:
    long long gen_pal(long long num, bool& is_odd) {
        long long tmp = num;
        if(is_odd) tmp /= 10;
        while(tmp) {
            num *= 10;
            num += tmp % 10;
            tmp /= 10;
        }
        return num;
    }

    void generate_palindrome(long long num, long long len, long long k, bool is_odd, map<string,long long>& mp) {
        string s = to_string(num);
        if(s.length() == len && num != 0) {
            long long pal = gen_pal(num, is_odd);
            if(pal % k != 0) return;
            s = to_string(pal);
            sort(s.begin(), s.end());
            mp[s] = pal;
            return;
        }

        for(int i = 0; i < 10; i++) {
            if(num == 0 && i == 0) continue;
            generate_palindrome(num * 10 + i, len, k, is_odd, mp);
        }
    }

    long long get_factorial(long long n) {
        long long f = 1;
        for(int i = 1; i <= n; i++) {
            f *= i;
        }
        return f;
    }

    long long get_pnc(long long num) {
        string s = to_string(num);
        int n = s.length();
        map<long long,long long> mp;
        for(int i = 0; i < n; i++) {
            mp[num % 10]++;
            num /= 10;
        }
        long long cnt = (n - mp[0]) * get_factorial(n - 1);

        for(auto &it : mp) {
            cnt /= get_factorial(it.second);
        }

        return cnt;
    }
    
    long long countGoodIntegers(int n, int k) {
        map<string,long long> mp;
        generate_palindrome(0, (n + 1) / 2, k, n & 1, mp);

        long long ans = 0;
        for(auto &it : mp) {
            ans += get_pnc(it.second);
        }

        return ans;
    }
};
