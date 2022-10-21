// 167. Two Sum II - Input Array Is Sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size()-1;
        int low = 0;
        int high = n;
        while(low <= high) {
            if(numbers[low]+numbers[high] < target) {
                low++;
            }
            else if (numbers[low]+numbers[high] > target){
                high--;
            }
            else {
                return {low+1,high+1};
            }
        }
        return {};
    }
};
