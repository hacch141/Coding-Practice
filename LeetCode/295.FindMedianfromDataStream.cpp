// 295. Find Median from Data Stream

class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int> > pqmin;
    priority_queue<int, vector<int> > pqmax;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(pqmax.size() == pqmin.size()) {
            if(pqmax.size() == 0) {
                pqmax.push(num);
                return;
            }
            if (num < pqmax.top())
                pqmax.push(num);
            else
                pqmin.push(num);
        }
        else {
            if(pqmax.size() > pqmin.size()) {
                if(num >= pqmax.top())
                    pqmin.push(num);
                else { 
                    int temp = pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(num);
                }
            }
            else {
                if(num <= pqmin.top()) 
                    pqmax.push(num);
                else {
                    int temp2 = pqmin.top();
                    pqmin.pop();
                    pqmax.push(temp2);
                    pqmin.push(num);
                }
            }            
        }

    }
    
    double findMedian() {
        if(pqmax.size() == pqmin.size()) 
            return (pqmax.top()+pqmin.top())/2.0;
        else if (pqmax.size() > pqmin.size()) 
            return pqmax.top();
        else
            return pqmin.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
