// 295. Find Median from Data Stream

class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.empty() == true || num<pq.top()) {
            pq.push(num);
        }
        else {
            minpq.push(num);
        }
        balanceHeap();
    }
    
    void balanceHeap() {
        if(pq.size() > minpq.size()+1) {
            minpq.push(pq.top());
            pq.pop();
        }
        else if(minpq.size() > pq.size()+1) {
            pq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(pq.size() == minpq.size()) {
            return (pq.top()+minpq.top())/2.0;
        }
        else {
            if(pq.size() > minpq.size()) {
                return (double)pq.top();
            }
            else {
                return (double)minpq.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// class MedianFinder {   // 2nd Method
// public:

//     priority_queue<int, vector<int>, greater<int> > pqmin;
//     priority_queue<int, vector<int> > pqmax;
    
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
    
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
//         if(pqmax.size() == pqmin.size()) {
//             if(pqmax.size() == 0) {
//                 pqmax.push(num);
//                 return;
//             }
//             if (num < pqmax.top())
//                 pqmax.push(num);
//             else
//                 pqmin.push(num);
//         }
//         else {
//             if(pqmax.size() > pqmin.size()) {
//                 if(num >= pqmax.top())
//                     pqmin.push(num);
//                 else { 
//                     int temp = pqmax.top();
//                     pqmax.pop();
//                     pqmin.push(temp);
//                     pqmax.push(num);
//                 }
//             }
//             else {
//                 if(num <= pqmin.top()) 
//                     pqmax.push(num);
//                 else {
//                     int temp2 = pqmin.top();
//                     pqmin.pop();
//                     pqmax.push(temp2);
//                     pqmin.push(num);
//                 }
//             }            
//         }

//     }
    
//     double findMedian() {
//         if(pqmax.size() == pqmin.size()) 
//             return (pqmax.top()+pqmin.top())/2.0;
//         else if (pqmax.size() > pqmin.size()) 
//             return pqmax.top();
//         else
//             return pqmin.top();
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
