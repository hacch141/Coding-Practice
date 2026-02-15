// Task Scheduler

// logical
class Solution {

    public int leastInterval(char[] tasks, int n) {

        int[] freq = new int[26];
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        Arrays.sort(freq);
        int maxFreq = freq[25];

        // Calculate idle slots
        int idleSlots = (maxFreq - 1) * n;

        // Fill idle slots using other tasks
        for (int i = 24; i >= 0; i--) {
            idleSlots -= Math.min(maxFreq - 1, freq[i]);
        }

        return tasks.length + Math.max(0, idleSlots);
    }
}

// Max-Heap
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] f = new int[26];
        for (char ch : tasks) f[ch - 'A']++;

        PriorityQueue<int[]> availableTasks = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; i++) {
            if (f[i] > 0) {
                availableTasks.add(new int[]{f[i], i});
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) q.add(-1);

        int time = 0;
        int remaining = tasks.length;
        while (remaining > 0) {
            if (!availableTasks.isEmpty()) {
                q.add(availableTasks.poll()[1]);
                remaining--;
            }
            else {
                q.add(-1);
            }
            int currTask = q.poll();
            if (currTask != -1) {
                f[currTask]--;
                if (f[currTask] > 0) availableTasks.add(new int[]{f[currTask], currTask});
            }
            time++;
        }

        return time;
    }
}

// Mah-Heap
class Solution {

    public int leastInterval(char[] tasks, int n) {

        int[] freq = new int[26];
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Max Heap (based on frequency)
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

        // Add non-zero frequencies to heap
        for (int f : freq) {
            if (f > 0) {
                maxHeap.offer(f);
            }
        }

        // Step 3: Cooldown queue
        Queue<int[]> cooldown = new LinkedList<>();
        int time = 0;

        while (!maxHeap.isEmpty() || !cooldown.isEmpty()) {

            time++;

            if (!maxHeap.isEmpty()) {
                int remaining = maxHeap.poll() - 1;

                if (remaining > 0) {
                    cooldown.offer(new int[]{remaining, time});
                }
            }

            // If cooldown finished, push back into heap
            if (!cooldown.isEmpty() && time >= cooldown.peek()[1] + n) {
                maxHeap.offer(cooldown.poll()[0]);
            }
        }

        return time;
    }
}

// =========================================================================

struct compare {
    bool operator()(pair<char,int>& p1, pair<char,int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto i : tasks) {
            mp[i]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare> pq(mp.begin(),mp.end());
        queue<pair<int,pair<char,int>>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time += 1;
            if(!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                it.second--;
                if(it.second >= 1) {
                    q.push({time,it});
                }
            }
            if(!q.empty() && time >= q.front().first+n) {
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};

// T : O(N * LogN)
// S : O(N)


#include <bits/stdc++.h> 
int taskScheduler(string tasks, int n, int t) {
    // Write your code here
    unordered_map<char,int> mp;
    int maxi = INT_MIN;
    int cntmaxi = 0;
    for(auto i : tasks) {
        mp[i]++;
        if(mp[i] == maxi) {
            cntmaxi++;
        }
        else if(mp[i] > maxi) {
            maxi = mp[i];
            cntmaxi = 1;
        }
    }
    int available = (maxi - 1)*(t - cntmaxi + 1);
    int remain = n - (cntmaxi*maxi);
    int idel = max(0,available - remain);
    return n + idel;
}
// T : O(N * LogN)
// S : O(N)
