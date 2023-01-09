// 299. Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int n1 = secret.length();
        int n2 = secret.length();
        if(n1 == 0) return "0A0B";
        vector<int> sVec(10,0);
        vector<int> gVec(10,0);
        int bulls = 0;
        int cows = 0;
        for(int i=0; i<n1; i++) {
            char a = secret[i];
            char b = guess[i];
            if(a==b) bulls++;
            else {
                sVec[a-'0']++;
                gVec[b-'0']++;
            }
        }
        for(int i=0; i<10; i++) {
            cows += min(sVec[i],gVec[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,pair<int,int>> mp;
        int n1 = secret.length();
        int n2 = secret.length();
        for(int i=0; i<n1; i++) {
            int freq = mp[secret[i]].second+1;
            mp[secret[i]] = {i,freq};
            cout << mp[secret[i]].first << " " << mp[secret[i]].second << endl;
        }
        int bulls = 0;
        int cows = 0;
        for(int i=0; i<min(n1,n2); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
                mp[secret[i]].second--;
            }
        }
        for(int i=0; i<n2; i++) {
            if(mp[guess[i]].second > 0 && secret[i] != guess[i]) {
                cows++;
                mp[guess[i]].second--;
            }
        }
        string ans = "";
        ans += to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
