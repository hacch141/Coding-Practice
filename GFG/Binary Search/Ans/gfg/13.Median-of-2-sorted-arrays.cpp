// Median of 2 sorted arrays

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}
// T : O(n1+n2)
// S : O(n1+n2)


double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

// T : O(n1+n2)
// S : O(1)


double median(vector<int>& a, vector<int>& b) {
  	// Write your code here.
  	int n1 = a.size();
  	int n2 = b.size();
  	int n = n1+n2;
  
  	if(n1 > n2) return median(b,a);
  
  	int low = 0;
  	int high = n1;
  
  	// number of ele on left part
  	int left = (n+1)/2; 
  
  	while(low <= high) {
    		int mid1 = (high-low)/2 + low;  // r1 index
    		int mid2 = left - mid1;         // r2 index
    
    		int l1 = INT_MIN, l2 = INT_MIN;
    		int r1 = INT_MAX, r2 = INT_MAX;
    
    		// left half index
    		if(mid1-1 >= 0) l1 = a[mid1-1];
    		if(mid2-1 >= 0) l2 = b[mid2-1];
    
    		// right half index 
    		if(mid1 < n1) r1 = a[mid1];
    		if(mid2 < n2) r2 = b[mid2];
    
    		if(l1<=r2 && l2<=r1) {
      			if(n%2 == 1) return max(l1,l2);
      			else return (double)(max(l1,l2) + min(r1,r2)) / 2.0;
    		}
    		else if(l1 > r2) {
    			  high = mid1 - 1;
    		}
    		else if(l2 > r1) {
    			  low = mid1 + 1;
    		}
  	}
  	return 0;
}
// T : O(Log min(n1,n2))
// S : O(1)
