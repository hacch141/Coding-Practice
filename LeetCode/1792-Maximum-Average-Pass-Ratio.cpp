// 1792. Maximum Average Pass Ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq;
        double sum = 0, cnt = 0;
        for(auto it : classes) {
            double a = it[0], b = it[1];
            if(a == b) sum++;
            else pq.push({((a + 1) / (b + 1)) - (a / b), a, b});
        }

        while(extraStudents && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            it[1]++; it[2]++;
            it[0] = ((it[1] + 1) / (it[2] + 1)) - (it[1] / it[2]);
            pq.push(it);
            extraStudents--;
        }

        while(!pq.empty()) {
            sum += pq.top()[1] / pq.top()[2];
            pq.pop();
        }

        return sum / classes.size();
    }
};
