// 2491. Divide Players Into Teams of Equal Skill

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size(), sum = skill[0] + skill[n - 1];
        bool f = true;
        long long ans = 0;
        for(int i = 0; i < n / 2; i++) {
            if(skill[i] + skill[n - 1 - i] != sum) return -1;
            ans += skill[i] * skill[n - 1 - i];
        }
        return ans;
    }
};
