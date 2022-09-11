//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(pq.empty() == true || x<pq.top()) {
            pq.push(x);
        }
        else {
            minpq.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(pq.size() > minpq.size()+1) {
           minpq.push(pq.top());
           pq.pop();
        }
        else if(minpq.size() > pq.size()+1) {
            pq.push(minpq.top());
            minpq.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
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


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
