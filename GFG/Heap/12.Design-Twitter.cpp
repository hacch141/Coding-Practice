// Design Twitter

class Twitter {
    Map<Integer,Set<Integer>> following;
    Map<Integer,List<int[]>> post;
    int time;

    public Twitter() {
        following = new HashMap<>();
        post = new HashMap<>();
        time = 1;
    }
    
    public void postTweet(int userId, int tweetId) {
        post.computeIfAbsent(userId, k -> new ArrayList<>()).add(new int[]{time, tweetId});
        time++;
    }
    
    public List<Integer> getNewsFeed(int userId) {
        // <time, tweetId, tweetUserId, Idx>
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        if (post.containsKey(userId)) {
            List<int[]> p =  post.get(userId);
            int[] lastPost = p.get(p.size() - 1);
            pq.add(new int[]{lastPost[0], lastPost[1], userId, p.size() - 1});
        }

        if (following.containsKey(userId)) {
            for (int f : following.get(userId)) {
                if (post.containsKey(f)) {
                    List<int[]> p =  post.get(f);
                    int[] lastPost = p.get(p.size() - 1);
                    pq.add(new int[]{lastPost[0], lastPost[1], f, p.size() - 1});
                }
            }
        }

        List<Integer> feed = new ArrayList<>();
        while (feed.size() < 10 && !pq.isEmpty()) {
            int[] curr = pq.poll();
            int tweetId = curr[1];
            int tweetUserId = curr[2];
            int idx = curr[3];
            feed.add(tweetId);
            if (idx > 0) {
                List<int[]> p =  post.get(tweetUserId);
                int[] lastPost = p.get(idx - 1);
                pq.add(new int[]{lastPost[0], lastPost[1], tweetUserId, idx - 1});
            }
        }

        return feed;
    }
    
    public void follow(int followerId, int followeeId) {
        following.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (following.containsKey(followerId)) {
            following.get(followerId).remove(followeeId);
        }
    }
}

// =======================================================================================

class Twitter {
public:
    unordered_map<int,unordered_set<int>> friends;
    priority_queue<vector<int>> post;
    int time;
    
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post.push({time,userId,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<vector<int>> pq = post;
        int cnt = 0;
        while(!pq.empty() && cnt<10) {
            vector<int> top = pq.top();
            pq.pop();
            if(top[1] == userId || friends[userId].count(top[1])) {
                feed.push_back(top[2]);
                cnt++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

// T : O(N*LogN)
// S : O(N)
