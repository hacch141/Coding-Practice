// 1780. Check if Number is a Sum of Powers of Three

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            // Check if this power should be used twice
            if (n % 3 == 2) return false;

            // Divide n by 3 to move to the next greater power
            n /= 3;
        }

        // The ternary representation of n consists only of 0s and 1s
        return true;
    }
};

// ===============================================================================

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = 0;

        // Find the largest power that is smaller or equal to n
        while (pow(3, power) <= n) {
            power++;
        }

        while (n > 0) {
            // Add current power to the sum
            if (n >= pow(3, power)) n -= pow(3, power);
            // We cannot use the same power twice
            if (n >= pow(3, power)) return false;
            // Move to the next power
            power--;
        }

        // n has reached 0
        return true;
    }
};

// =====================================================================

class Solution {
public:
    bool checkPowersOfThree(int n) { return checkPowersOfThreeHelper(0, n); }

private:
    bool checkPowersOfThreeHelper(int power, int n) {
        // Base case: if n becomes 0, we have successfully formed the sum
        if (n == 0) return true;

        // If the current power of 3 exceeds n, we can't use it, so return false
        if (pow(3, power) > n) return false;

        // Option 1: Include the current power of 3 and subtract it from n
        bool addPower = checkPowersOfThreeHelper(power + 1, n - pow(3, power));

        // Option 2: Skip the current power of 3 and try with the next power
        bool skipPower = checkPowersOfThreeHelper(power + 1, n);

        // Return true if either option leads to a valid solution
        return addPower || skipPower;
    }
};
