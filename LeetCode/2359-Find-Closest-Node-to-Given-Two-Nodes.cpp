// 2359. Find Closest Node to Given Two Nodes

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;

        int n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        int d = 0;
        vector<bool> vis1(n, false);

        while(node1 != -1 && !vis1[node1]) {
            vis1[node1] = true;
            dist1[node1] = d;
            d++;
            node1 = edges[node1];
        }

        d = 0;
        vector<bool>vis2(n, false);
        while(node2 != -1 && !vis2[node2]) {
            vis2[node2] = true;
            dist2[node2] = d;
            d++;
            node2 = edges[node2];
        }

        int ans = -1, mx = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(max(dist1[i], dist2[i]) < mx) {
                mx = max(dist1[i], dist2[i]);
                ans = i;
            }
        }

        return ans;
    }
};
