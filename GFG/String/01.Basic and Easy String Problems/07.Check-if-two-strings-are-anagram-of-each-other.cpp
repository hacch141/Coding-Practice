// Check if two strings are anagram of each other

#include <bits/stdc++.h>

bool isAnagram(string str1, string str2)
{
    //Write your code here
    vector<int> freq(26);
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1 != n2) return false;
    for(int i=0; i<n1; i++) {
        freq[str1[i]-'a']++;
        freq[str2[i]-'a']--;
    }
    for(auto i : freq) {
        if(i != 0) return false;
    }
    return true;
}
// T : O(N)
// S : O(1)


#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string str1, string str2) {
    //Write your code here
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return (str1 == str2);
}

// T : O(N*Log N  + M*Log M)
// S : O(1)
