class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() { timeStamp = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for (auto& t : tweets[userId])
            pq.push(t);

        for (int followee : follows[userId]) {
            for (auto& t : tweets[followee]) {
                pq.push(t);
            }
        }

        vector<int> feed;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
    }
};
