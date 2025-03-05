// 2579. Count Total Number of Colored Cells

class Solution {
public:
    long long coloredCells(int n) {
        return (1LL * n * n) + (1LL * (n - 1) * (n - 1));
    }
};

// ====================================================

1+(4×1)+(4×2)+...+(4×(n−1))
Recognizing that the sum inside the parentheses is simply the arithmetic series 1+2+...+(n−1), we use the formula for the sum of the first m natural numbers:
1 + 4×(n−1)×n/2
Expanding and simplifying, we get:
1+2×(n−1)×n

class Solution {
public:
    long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
};

// ====================================================

class Solution {
public:
    long long coloredCells(int n) {
        long long numBlueCells = 1;
        int addend = 4;
        while (--n) {
            numBlueCells += addend;
            addend += 4;
        }
        return numBlueCells;
    }
};
