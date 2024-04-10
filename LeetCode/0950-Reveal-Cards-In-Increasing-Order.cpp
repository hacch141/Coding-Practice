// 950. Reveal Cards In Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        queue<int> q;
        for(int i = 0; i < n; i++) q.push(i);

        int ptr = 0;
        vector<int> ans(n);
        while(!q.empty()) {
            int ind = q.front();
            q.pop();
            ans[ind] = deck[ptr++];
            if(!q.empty()) {
                int a = q.front();
                q.pop();
                q.push(a);
            }
        }
        return ans;
    }
};
