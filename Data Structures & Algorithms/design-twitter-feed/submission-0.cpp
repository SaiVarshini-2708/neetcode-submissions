class Twitter {
public:

    // timestamp, userId, tweetId
    vector<pair<int, pair<int, int>>> tweets;

    // follower -> set of followees
    unordered_map<int, set<int>> mp;

    int t = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets.push_back({t, {userId, tweetId}});
        t++;
    }

    vector<int> getNewsFeed(int userId) {

        // min-heap based on timestamp
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (int i = 0; i < tweets.size(); i++) {

            int time = tweets[i].first;
            int tweetUser = tweets[i].second.first;
            int tweetId = tweets[i].second.second;

            // Tweet is from user himself
            // OR from someone he follows
            if (tweetUser == userId ||
                mp[userId].find(tweetUser) != mp[userId].end()) {

                pq.push({time, tweetId});

                // Keep only 10 most recent
                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Currently oldest -> newest
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        mp[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        mp[followerId].erase(followeeId);
    }
};