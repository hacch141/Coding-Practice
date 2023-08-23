// Number of Distinct Substrings in a String Using Trie

#include <bits/stdc++.h>

struct Node {
    Node* links[26];

    Node() {
        for(int i=0; i<26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char c) {
        return (links[c-'a'] != NULL);
    }

    void put(char c, Node* node) {
        links[c-'a'] = node;
    }

    Node* get(char c) {
        return links[c-'a'];
    }

};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n = s.length();
    int cnt = 0;

    Node* root = new Node();

    for(int i=0; i<n; i++) {
        Node* node = root;
        for(int j=i; j<n; j++) {
            if(!node->containsKey(s[j])) {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }

    return cnt + 1;
}
