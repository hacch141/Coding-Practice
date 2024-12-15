// 1792. Maximum Average Pass Ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq;

        for(auto& cls : classes) {
            double pass = cls[0], total = cls[1];
            double current = pass / total;
            double next = (pass + 1) / (total + 1);
            double improvement = next - current;
            pq.push({improvement, pass, total});
        }

        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();
            double pass = top[1], total = top[2];
            pass += 1;
            total += 1;
            double current = pass / total;
            double next = (pass + 1) / (total + 1);
            double improvement = next - current;
            pq.push({improvement, pass, total});
        }

        double totalRatio = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            totalRatio += top[1] / top[2];
        }

        return totalRatio / classes.size();
    }
};
