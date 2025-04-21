class Twitter {
public:
    // for tweets -> userId: timestamp, tweetid
    unordered_map<int, vector<pair<int, int>>> tweets;

    // follows: userId: followId
    unordered_map<int, unordered_set<int>> userFollow;

    // timestamp
    int timestamp = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        int counter = 0;
        vector<int> result;

        for (auto& tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        for (int followeeId : userFollow[userId]) {
            for (auto& tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        userFollow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollow[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */