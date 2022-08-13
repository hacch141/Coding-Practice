// Anagram of String

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends



int ana(string &small, string &big) {
    
}

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
// Your code goes here
    string small, big;
    int ans;
    if(str1.length()>=str2.length()) {
        small = str2;
        big = str1;
    }
    else {
        small = str1;
        big = str2;
    }
    unordered_map<char,int> mp;
    int cnt = 0;
    for(int i=0; i<small.length(); i++) {
        mp[small[i]]++;
    }
    for(int i=0; i<big.length(); i++) {
        mp[big[i]]--;
    }
    for(auto i : mp) {
        cnt += abs(i.second);
    }
    return cnt;
}
