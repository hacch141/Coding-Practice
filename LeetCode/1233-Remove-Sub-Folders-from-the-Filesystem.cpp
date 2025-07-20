// 1233. Remove Sub-Folders from the Filesystem

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st;
        for(auto s : folder) st.insert(s);

        vector<string> ans;
        for(auto s : folder) {
            string curr = s;
            bool f = true;
            while(curr != "" && f) {
                while(curr.back() != '/') curr.pop_back();
                curr.pop_back();
                if(st.count(curr)) f = false;
            }
            if(f) ans.push_back(s);
        }
        return ans;
    }
};

// Trie
struct Node {
    bool end;
    map<string, Node*> mp;

    Node() {
        end = false;
    }

    bool is_end() {
        return end;
    }

    void set_end() {
        end = true;
    }

    Node* get_node(string s) {
        if(mp.find(s) != mp.end()) {
            return mp[s];
        }
        return NULL;
    }

    void set_node(string s, Node* node) {
        mp[s] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string path) {
        stringstream ss(path);
        string token;
        Node* curr = root;
        while(getline(ss, token, '/')) {
            if(!(curr->get_node(token))) {
                curr->set_node(token, new Node());
            }
            curr = curr->get_node(token);
        }
        curr->set_end();
    }

    bool is_subfolder(string path) {
        stringstream ss(path);
        string token;
        Node* curr = root;
        vector<string> v;
        while(getline(ss, token, '/')) {
            v.push_back(token);
        }
        for(int i = 0; i < v.size() - 1; i++) {
            curr = curr->get_node(v[i]);
            if(curr->is_end()) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        Trie t;
        for(auto p : folder) t.insert(p);

        vector<string> ans;
        for(auto p : folder) {
            if(!(t.is_subfolder(p))) ans.push_back(p);
        }
        return ans;
    }
};
