// Merge two sorted arrays without e

// leetcode
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
  	int n = a.size();
  	int m = b.size();
  
  	int left = n-1;
  	int right = 0;
  	while(left >= 0 && right< m) {
    		if(a[left] > b[right]) {
      			swap(a[left],b[right]);
      			left--;
      			right++;
    		}
    		else {
    			  break;
    		}
  	}
  	sort(a.begin(),a.end());
  	sort(b.begin(),b.end());
}
// T : O(M + N + N*Log N + M*Log M)
// S : O(1)


/*
Time Complexity: O(N * (M + N) + MlogM), where 'N' is the size of 'A' and 'M' is the size of 'B'.
Space Complexity: O(1)
*/

#include<vector>

// Function to swap two integers 'a' and 'b'.
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size(), m = b.size();
	
	// Iterating over the positions of 'N' smallest integers.
	for(int i = 0; i < n; ++i){
		int flag = i;
		int least = a[i];
		
		// Finding the minimum among the remaining elements of 'A'.
		for(int j = i; j < n; ++j){
			if(a[j] < least){
				least = a[j];
				flag = j;
			}
		}
		
		// Finding the minimum among the elements of 'B'.
		for(int j = 0; j < m; ++j){
			if(b[j] < least){
				least = b[j];
				flag = j;
			}
		}
		
		// Swapping 'A[i]' with the least element.
		if(flag < n && flag >= i && a[flag] == least)
			swap(a[i], a[flag]);
		else
			swap(a[i], b[flag]);
	}
	
	// Sorting the array 'B'.
	sort(b.begin(), b.end());
}


void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}
// T : O(N + M)
// S : :(N + M)



// Gap Method
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

// T : O((n+m)*log(n+m))
// S : O(1)
