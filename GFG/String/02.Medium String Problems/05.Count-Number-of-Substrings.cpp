// Count Number of Substrings

#include <bits/stdc++.h>

int getTotalSubStr(string &s, int k) {
    unordered_map<char,int> mp;
    int i=0, j=0, ans=0;
    int n = s.length();

    while(j<n) {
        mp[s[j]]++;
        while(mp.size() > k) {
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }
        ans += j-i+1;
        j++;
    }

    return ans;
}

int countSubStrings(string str, int k) 
{
    // Write your code here.
    return getTotalSubStr(str,k) - getTotalSubStr(str,k-1);
}
// T : O(N)
// S : O(K)

// =============================================================================

#include <bits/stdc++.h>

int helper(string &str, int k) {
    int n = str.size();

    vector<int> freq(26,0);
    int cnt=0, ans=0, i=0, j=0;

    while(j<n) {
        if(freq[str[j]-'a']==0) {
            cnt++;
        }
        freq[str[j]-'a']++;

        while(cnt>k) {
            freq[str[i]-'a']--;
            if(freq[str[i]-'a'] == 0) cnt--;
            i++;
        }

        ans += j - i + 1;
        j++;
    }
    return ans;
}

int countSubStrings(string str, int k) 
{
    // Write your code here.
    return helper(str,k) - helper(str,k-1);
}
// T : O(N)
// S : O(1)








#include <bits/stdc++.h>

int countk1(string &str) {
    int n = str.size();
    unordered_map<char,int> mp;
    int i=0,j=0, ans=0;

    while(1) {
        bool f1=false, f2=false;

        while(j<n) {
            f1 = true;
            mp[str[j]]++;
            if(mp.size() > 1) {
                mp[str[j]]--;
                if(mp[str[j]]==0) mp.erase(str[j]);
                break;
            }
            j++;
        }

        while(mp.size() == 1) {
            f2 = true;
            ans += j-i;
            mp[str[i]]--;
            if(mp[str[i]] == 0) mp.erase(str[i]);
            i++;
        }

        if(f1==false && f2==false) {
            break;
        }
    }
    return ans;
}

int countSubStrings(string str, int k) 
{
    // Write your code here.
    int n = str.size();
    if(k==1) return countk1(str);

    unordered_map<char,int> mps, mpb;
    int is=0, ib=0, i=0, ans=0;

    while(1) {
        bool f1=false, f2=false, f3=false;

        while(ib < n) {
            f1 = true;
            mpb[str[ib]]++;
            if(mpb.size() > k) {
                mpb[str[ib]]--;
                if(mpb[str[ib]]==0) mpb.erase(str[ib]);
                break;
            }
            ib++;
        }

        while(is < n) {
            f2 = true;
            mps[str[is]]++;
            if(mps.size() > k-1) {
                mps[str[is]]--;
                if(mps[str[is]]==0) mps.erase(str[is]);
                break;
            }
            is++;
        }
        
        while(mpb.size()==k && mps.size()==k-1) {
            f3 = true;
            ans += ib-is;
            mpb[str[i]]--;
            mps[str[i]]--;
            if(mpb[str[i]] == 0) mpb.erase(str[i]);
            if(mps[str[i]] == 0) mps.erase(str[i]);
            i++;
        }

        if(f1==false && f2==false && f3==false) {
            break;
        }
    }
    return ans;
}
// T : O(N)
// S : O(N)
