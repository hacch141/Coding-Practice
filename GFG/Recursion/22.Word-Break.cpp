// Word Break

class Solution
{
public:

    bool solve(int ind, int &n, string &s, unordered_set<string> &st) {
        if(ind == n) {
            return true;
        }
        
        for(int i=ind; i<n; i++) {
            if(st.count(s.substr(ind,i-ind+1))) {
                if(solve(i+1,n,s,st) == true) return true;
            }
        }
        
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.length();
        unordered_set<string> st;
        for(auto i : B) {
            st.insert(i);
        }
        
        return solve(0,n,A,st);
    }
};
// T : O(n^n)
// S : O(n + STACK)


#include <bits/stdc++.h>

void solve(int ind, int &len, string &s, unordered_set<string> &st, string &curr, vector<string> &ans) {
    if(ind == len) {
        curr.pop_back();
        ans.push_back(curr);
        curr += " ";
        return;
    }
        
    for(int i=ind; i<len; i++) {
        if(st.count(s.substr(ind,i-ind+1))) {
            curr += s.substr(ind,i-ind+1) + " ";
            solve(i+1,len,s,st,curr,ans);
            curr.resize(curr.size() - (i-ind+2));
        }
    }
}

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    //  write your code here.
    int len = s.length();
        
    unordered_set<string> st;
    for(auto i : dict) {
        st.insert(i);
    }
        
    vector<string> ans;
    string curr = "";
    solve(0,len,s,st,curr,ans);
    return ans;
}
// T : O(n^n)
// S : O(n + STACK)



/*
    Time Complexity: O( N*(2^N) )
    Space Complexity: O( N*(2^N) )
    Where N is the length of sentence.
*/

vector<string> getAllValidSentencesHelper(string &sentence, int idx, unordered_set<string> &dictionary, unordered_map<int, vector<string>> &dp, int size)
{
    // base case
    if (idx == size)
    {
        return {""};
    }

    //  Already has a solution for the current sentence, then simply return the solution.
    if (dp.find(idx) != dp.end())
    {
        return dp[idx];
    }

    vector<string> subPart, completePart;
    string word = "";

    /*
        Start exploring the sentence from the index until we wouldn't find 'j' such that substring [index,j] exists in the dictionary as a word.
    */
    for (int j = idx; j < size; j++)
    {

        word.push_back(sentence[j]);
        if (dictionary.count(word) == 0)
        {
            continue;
        }

        //  Get the answer for rest of sentence from 'j' to sentence.size().
        subPart = getAllValidSentencesHelper(sentence, j + 1, dictionary, dp, size);

        //  Append "word" with all the answer what we got.
        for (int i = 0; i < subPart.size(); i++)
        {
            if (subPart[i].size() != 0)
            {
                subPart[i] = word + " " + subPart[i];
            }
            else
            {
                subPart[i] = word + "" + subPart[i];
            }
        }

        //  finally store the all.
        for (auto sub : subPart)
        {
            completePart.push_back(sub);
        }
    }

    //  Store all the answer what we got from the current index.
    return dp[idx] = completePart;
}
vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    // dp[idx] will store the all possible sentence which has been formed for the current idx to end of the given sentence.
    unordered_map<int, vector<string>> dp;

    //  For optimisation to check the weather, any word exists in the dictionary or not.
    unordered_set<string> d;

    for (auto word : dict)
    {
        d.insert(word);
    }
    return getAllValidSentencesHelper(s, 0, d, dp, s.size());
}
