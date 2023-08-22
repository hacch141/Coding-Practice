// Next Greater Element

/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the array.
*/

#include <stack>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Create a vetor to store next Greater elements
    vector<int> ans(n);

    // Stack, to keep track of next greater element
    stack<int> s;

    // Traverse in reverse fashion in the array
    for (int i = n - 1; i >= 0; i--)
    {
        //If current element is greater than or equal to stack's top
        //element, we can pop it since now it will never get picked
        //as the next greater element
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }

        //If stack is not empty, stack's top element is
        //the next greater element, else there is none
        if (!s.empty())
        {
            ans[i] = s.top();
        }
        else
        {
            ans[i] = -1;
        }

        // Push current element onto stack
        s.push(arr[i]);
    }

    // return final answer vector
    return ans;
}




/*
    Time Complexity - O(n ^ 2)
    Space Complexity - O(1)

    Where 'n' is the number of elements in the array.
*/

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Create a vetor to store next Greater elements
    vector<int> ans(n);

    // Initialize every index with -1
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }

    // Traverse in the array
    for (int i = 0; i < n; i++)
    {
        // Traverse from next index to end
        for (int j = i + 1; j < n; j++)
        {
            //As soon as we find a greater element
            //We update the answer and break
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    // return final answer vector
    return ans;
}
