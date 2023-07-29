// Design Twitter

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
