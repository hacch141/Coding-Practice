class LRUCache
{
    private:

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
    int capacity;
    unordered_map<int,Node*> mp;
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
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
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
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
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here  
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size() == capacity) {
            Node* temp = tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
        }
        addNode(new Node (key, value));
        mp[key] = head->next;
    }
};
