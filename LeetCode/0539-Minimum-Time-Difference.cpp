// 539. Minimum Time Difference

class Solution {
public:
    int getDiff(string& s1, string& s2) {
        int h1 = stoi(s1.substr(0, 2)), h2 = stoi(s2.substr(0, 2));
        int m1 = stoi(s1.substr(3)), m2 = stoi(s2.substr(3));
        int c1 = h1 * 60 + m1, c2 = h2 * 60 + m2;
        if(c1 > c2) swap(c1, c2);
        return min(abs(c1 - c2), c1 + (24 * 60) - c2);
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size(), mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mn = min(mn, getDiff(timePoints[i], timePoints[(i + 1) % n]));
        }
        return mn;
    }
};


// ============================================================


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mnt;
        int n = timePoints.size(), mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            int h1 = stoi(timePoints[i].substr(0, 2)), m1 = stoi(timePoints[i].substr(3));
            int m = h1 * 60 + m1;
            mnt.push_back(m);
        }
        sort(mnt.begin(), mnt.end());
        for(int i = 0; i < n - 1; i++) {
            mn = min(mn, mnt[i + 1] - mnt[i]);
        }
        return min(mn, abs(24 * 60 + mnt[0] - mnt[n - 1]));
    }
};


