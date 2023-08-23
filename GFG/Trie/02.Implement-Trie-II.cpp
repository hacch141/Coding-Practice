// Implement Trie – II

#include <bits/stdc++.h> 

struct Node {
    Node* links[26];
    int cntEndWith;
    int cntPrefix;

    Node() {
        for(int i=0; i<26; i++) {
            links[i] = NULL;
        }
        cntEndWith = 0;
        cntPrefix = 0;
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

    void increaseEndWith() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void decreaseEndWith() {
        cntEndWith--;
    }

    void decreasePrefix() {
        cntPrefix--;
    }

    int getcntEndWith() {
        return cntEndWith;
    }

    int getcntPrefix() {
        return cntPrefix;
    }

};

class Trie{

    private:
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getcntEndWith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getcntPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return;
            }
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEndWith();
    }
};
