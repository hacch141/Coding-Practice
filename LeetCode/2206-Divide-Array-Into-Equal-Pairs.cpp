// 2206. Divide Array Into Equal Pairs

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> f(501, 0);
        for(auto &i : nums) f[i]++;
        for(auto &i : f) {
            if(i % 2) return false;
        }
        return true;
    }
};

// =========================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Sort array to group equal elements together
        sort(nums.begin(), nums.end());

        // Check consecutive pairs in sorted array
        for (int pos = 0; pos < nums.size(); pos += 2) {
            // If any pair doesn't match, we can't form n equal pairs
            if (nums[pos] != nums[pos + 1]) {
                return false;
            }
        }

        // All pairs found successfully
        return true;
    }
};

// ==========================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Find maximum value in array
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(num, maxNum);
        }

        // Toggle pair status for each number
        vector<bool> needsPair(maxNum + 1, false);
        for (int num : nums) {
            needsPair[num] = !needsPair[num];
        }

        // Check if any number remains unpaired
        for (int num : nums) {
            if (needsPair[num]) {
                return false;
            }
        }

        return true;
    }
};

// ========================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Track unpaired numbers
        unordered_set<int> unpaired;

        // Add numbers to set if unseen, remove if seen
        for (int num : nums) {
            if (unpaired.count(num)) {
                unpaired.erase(num);
            } else {
                unpaired.insert(num);
            }
        }

        // Return true if all numbers were paired
        return unpaired.empty();
    }
};
