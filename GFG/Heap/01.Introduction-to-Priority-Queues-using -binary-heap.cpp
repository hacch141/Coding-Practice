// Introduction to Priority Queues

void heapify(int i, vector<int>& heap, int& n) {
    int largest = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;
    
    if(lc < n && heap[largest] < heap[lc]) {
        largest = lc;
    }

    if(rc < n && heap[largest] < heap[rc]) {
        largest = rc;
    }

    if(largest != i) {
        swap(heap[largest] , heap[i]);
        heapify(largest, heap, n);
    }
}

int pop(vector<int> &heap)
{
    // Write you code here.
    int n = heap.size();
    if(n == 0) return -1;
    
    int ele = heap[0]; 
    heap[0] = heap.back();
    
    heap.pop_back();
    n--;
    
    heapify(0,heap,n);
    return ele;
}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }
