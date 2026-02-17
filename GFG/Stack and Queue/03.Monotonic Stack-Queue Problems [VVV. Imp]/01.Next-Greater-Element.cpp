// Next Greater Element

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        Stack<Integer> stack = new Stack<>();
        Map<Integer, Integer> map = new HashMap<>();

        // Process nums2
        for (int num : nums2) {

            while (!stack.isEmpty() && stack.peek() < num) {
                map.put(stack.pop(), num);
            }

            stack.push(num);
        }

        // Elements left in stack have no greater element
        while (!stack.isEmpty()) {
            map.put(stack.pop(), -1);
        }

        // Build answer for nums1
        int[] result = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {
            result[i] = map.get(nums1[i]);
        }

        return result;
    }
}

// ================================================================

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

