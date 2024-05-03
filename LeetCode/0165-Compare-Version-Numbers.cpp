// 165. Compare Version Numbers

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);

        vector<int> v1, v2;
        string tmp;
        while(getline(ss1, tmp, '.')) v1.push_back(stoi(tmp));
        while(getline(ss2, tmp, '.')) v2.push_back(stoi(tmp));

        int n1 = v1.size(), n2 = v2.size();
        for(int i = 0; i < min(n1, n2); i++) {
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }

        if(n1 > n2) {
            for(int i = n2; i < n1; i++) {
                if(v1[i] > 0) return 1;
            }
        }

        if(n2 > n1) {
            for(int i = n1; i < n2; i++) {
                if(v2[i] > 0) return -1;
            }
        }
        return 0;
    }
};
