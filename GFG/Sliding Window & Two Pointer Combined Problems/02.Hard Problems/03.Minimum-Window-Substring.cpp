// Minimum Window Substring

#include <bits/stdc++.h> 
string minSubstring(string &a, string &b)
{
    // Write your code here.
    if(a.length()==0 || a.length()<b.length()) {
        return "";
    }

    unordered_map<char,int> mpa, mpb;
    for(auto ch : b) {
        mpb[ch]++;
    }

    int i=0, j=0, cnt=0;
    int n = a.length();
    string ans = "";

    while(j<n) {
        mpa[a[j]]++;
        if(mpa[a[j]] <= mpb[a[j]]) {
            cnt++;
        }

        while(i<j && cnt==b.length()) {
            string curr = a.substr(i,j-i+1);
            if(ans.length()==0 || curr.length() < ans.length()) {
                ans = curr;
            }
            mpa[a[i]]--;
            if(mpa[a[i]] < mpb[a[i]]) {
                cnt--;
            }
            i++;
        }
        
        j++;
    }

    return ans;
}
// T : O(N)
// S : O(N)



#include <bits/stdc++.h> 

// Function to check whether the current window contains
// all the characters of b or not

bool isEnough(int curr[],int req[]) {
    for(int i=0;i<26;i++) {
        if(curr[i]<req[i]) {
            return false;
        }
    }
    return true;
}

int minSubstring(string &a, string &b) {
    int req[26]={0},curr[26]={0},j=0,ans=INT_MAX;
    for(int i=0;i<b.length();i++) {
        req[b[i]-'a']++;
    }
    for(int i=0;i<a.length();i++) {
        curr[a[i]-'a']++;
        while(isEnough(curr,req)) {
            ans=min(ans,i-j+1);
            curr[a[j++]-'a']--;
        }
    }
    return ans==INT_MAX?-1:ans;
}
// T : O(N)
// S : O(1)




class Solution {
public:

    bool isValid(vector<int>& a, vector<int>& b) {
        for(int i=0; i<60; i++) {
            if(a[i] < b[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        if(t.length() > s.length()) return "";

        vector<int> freqS(60,0), freqT(60,0);
        for(auto i : t) {
            freqT[i-'A']++;
        }

        int i=0, j=0, cnt=0, st=-1, end=-1, mini=INT_MAX;
        while(j<s.length()) {
            freqS[s[j]-'A']++;
            while(isValid(freqS,freqT)) {
                if(j-i+1 < mini) {
                    st = i;
                    end = j;
                    mini = j-i+1;
                }
                freqS[s[i]-'A']--;
                i++;
            }
            j++;
        }

        if(st==-1 && end==-1) return "";
        return s.substr(st,end-st+1);
    }
};



class Solution {
public:

    string minWindow(string s, string t) {

        if(t.length() > s.length()) return "";

        vector<int> freqS(60,0), freqT(60,0);
        for(auto i : t) {
            freqT[i-'A']++;
        }

        int i=0, j=0, cnt=0, st=-1, end=-1, mini=INT_MAX;
        while(j<s.length()) {
            freqS[s[j]-'A']++;
            if(freqS[s[j]-'A'] <= freqT[s[j]-'A']) {
                cnt++;
            }
            while(cnt == t.length()) {
                if(j-i+1 < mini) {
                    st = i;
                    end = j;
                    mini = j-i+1;
                }
                freqS[s[i]-'A']--;
                if(freqS[s[i]-'A'] < freqT[s[i]-'A']) {
                    cnt--;
                }
                i++;
            }
            j++;
        }

        if(st==-1 && end==-1) return "";
        return s.substr(st,end-st+1);
    }
};
