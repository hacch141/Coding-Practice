// 460. LFU Cache

struct Node {
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        freq = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
    map<int,Node*> mp;
    map<int,List*> freqListmp;
    int maxSizeCache;
    int minFreq;
    int currSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;    
    }

    void updateFreqList(Node* node) {
        mp.erase(node->key);
        freqListmp[node->freq]->removeNode(node);

        if(node->freq==minFreq && freqListmp[node->freq]->size==0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if(freqListmp.find(node->freq+1) != freqListmp.end()) {
            nextHigherFreqList = freqListmp[node->freq+1];
        }
        node->freq += 1;
        nextHigherFreqList->addFront(node);
        freqListmp[node->freq] = nextHigherFreqList;
        mp[node->key] = node;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            updateFreqList(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0) {
            return;
        }
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            updateFreqList(node);
        }
        else {
            if(currSize == maxSizeCache) {
                List* l = freqListmp[minFreq];
                mp.erase(l->tail->prev->key);
                freqListmp[minFreq]->removeNode(l->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListmp.find(minFreq) != freqListmp.end()) {
                listFreq = freqListmp[minFreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            mp[key] = node;
            freqListmp[minFreq] = listFreq;
        }
    }
};
