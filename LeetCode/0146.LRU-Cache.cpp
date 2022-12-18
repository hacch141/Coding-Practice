// 146. LRU Cache

class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int _key, int _val) {
                key = _key;
                val = _val;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prev = delNode->prev;
        Node* next = delNode->next;
        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* resNode = mp[key];
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return resNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size() == cap) {
            Node* temp = tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
        }
        addNode(new Node (key, value));
        mp[key] = head->next;
    }
};
