// 133. Clone Graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<int,Node*>& mp) {

        vector<Node*> neighbour;
        Node* clone = new Node(node->val);
        mp[node->val] = clone;

        for(auto it : node->neighbors) {

            if(mp.find(it->val) != mp.end()) {
                neighbour.push_back(mp[it->val]); 
            }
            
            else {
                neighbour.push_back(dfs(it,mp));
            }

        }
        
        clone->neighbors = neighbour;
        return clone;
    }

    Node* cloneGraph(Node* node) {

        if(node == NULL) {
            return NULL;
        }

        unordered_map<int,Node*> mp;
        if(node->neighbors.size()==0) {
            Node* clone= new Node(node->val);
            return clone;
        }

        return dfs(node,mp);
    }
};
