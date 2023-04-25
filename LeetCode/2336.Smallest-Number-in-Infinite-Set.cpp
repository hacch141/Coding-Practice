// 2336. Smallest Number in Infinite Set

class SmallestInfiniteSet {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> v;

    SmallestInfiniteSet() {
        v.push_back(false);
        for(int i=1; i<=1000; i++) {
            pq.push(i);
            v.push_back(true);
        }
    }
    
    int popSmallest() {
        if(pq.size() != 0) {
            int a = pq.top();
            pq.pop();
            v[a] = false;
            return a;
        }
        return -1;
    }
    
    void addBack(int num) {
        if(!v[num]) {
            v[num] = true;
            pq.push(num);
        }
    }
};
