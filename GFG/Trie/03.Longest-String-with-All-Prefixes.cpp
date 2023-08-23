// Longest String with All Prefixes

#include <bits/stdc++.h> 

struct Node {
    Node *links[26];
    bool flag;

    Node() {
        for(int i=0; i<26; i++) {
            links[i] = NULL;
        }
        flag = false;
    }

    bool containsKey(char c) {
        return (links[c-'a'] != NULL);
    }

    Node* get(char c) {
        return links[c-'a'];
    }

    void put(char c, Node* node) {
        links[c-'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    private:
    Node* root;

    public:
    Trie() {
        root = new Node();
    }

    void insert(string& word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool isLCP(string& word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
            if(!node->isEnd()) {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(auto i : a) {
        t.insert(i);
    }

    string ans = "";
    for(auto i : a) {
        if(t.isLCP(i)) {
            if(i.length() > ans.length()) {
                ans = i;
            }
            else if(i.length() == ans.length() && i<ans) {
                ans = i;
            }
        }
    }

    if(ans == "") return "None";
    return ans;
}
