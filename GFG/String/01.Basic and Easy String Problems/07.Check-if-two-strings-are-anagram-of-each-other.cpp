// Check if two strings are anagram of each other

class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character,Integer> mp = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char chs = s.charAt(i);
            char cht = t.charAt(i);
            mp.put(chs, mp.getOrDefault(chs, 0) + 1);
            mp.put(cht, mp.getOrDefault(cht, 0) - 1);
            if (mp.get(chs) == 0) mp.remove(chs);
            if (chs != cht && mp.get(cht) == 0) mp.remove(cht);
        }
        return mp.size() == 0;
    }
}

// =================================================================

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
