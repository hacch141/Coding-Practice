// Sort An Array of 0s, 1s and 2s

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high) {
        if(arr[mid] == 1) {
            mid++;
        }
        else if(arr[mid] == 0) {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 2) {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
// T : O(N)
// S : O(1)


/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where N is the length of the array/list.
*/

void sortArray(vector<int>& arr, int n)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    int index = 0;

    while (zero--)
    {
        arr[index] = 0;
        index++;
    }

    while(one--)
    {
        arr[index] = 1;
        index++;
    }

    while(two--)
    {
        arr[index] = 2;
        index++;
    }
}


/*
    Time Complexity : O(Nlog(N))
    Space Complexity : O(1)

    where N is the length of the array/list.
*/


#include<algorithm>

void sortArray(vector<int>& arr, int n)
{
    sort(arr.begin(), arr.end());
}
