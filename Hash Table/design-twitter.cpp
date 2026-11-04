#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Twitter {
private:
    int time;
   
  unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    std::vector<int> getNewsFeed(int userId) {
        priority_queue<std::pair<int, int>> maxHeap;
        if (tweets.find(userId) != tweets.end()) {
            const auto& userTweets = tweets[userId];
            int count = 0;
            for (auto it = userTweets.rbegin(); it != userTweets.rend() && count < 10; ++it, ++count) {
                maxHeap.push(*it);
            }
        }
        if (following.find(userId) != following.end()) {
            for (int followeeId : following[userId]) {
                if (tweets.find(followeeId) != tweets.end()) {
                    const auto& followeeTweets = tweets[followeeId];
                    int count = 0;
                    for (auto it = followeeTweets.rbegin(); it != followeeTweets.rend() && count < 10; ++it, ++count) {
                        maxHeap.push(*it);
                    }
                }
            }
        }

       
        vector<int> res;
        int k = 0;
        while (!maxHeap.empty() && k < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            k++;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }
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