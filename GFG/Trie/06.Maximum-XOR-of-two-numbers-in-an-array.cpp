// Maximum XOR of two numbers in an array

#include <bits/stdc++.h>

struct Node {
    Node *bits[2];

    Node() {
        bits[0] = NULL;
        bits[1] = NULL;
    }

    bool containsKey(int bit) {
        return (bits[bit] != NULL);
    }

    Node* get(int bit) {
        return bits[bit];
    }

    void put(int bit, Node* node) {
        bits[bit] = node;
    }
};

class Trie {
    private:
    Node* root;

    public:

    Trie() {
        root = new Node();
    }

    void insert(int& num) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int& num) {
        Node* node = root;
        int maxi = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)) {
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie t;
    for(auto i : A) {
        t.insert(i);
    }

    int ans = 0;
    for(auto i : A) {
        ans = max(ans, t.getMax(i));
    }

    return ans;
}
