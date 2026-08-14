class Twitter {
public:
   int time = 0;
        unordered_map <int , vector <pair<int,int>>> tweet;
        unordered_map <int, unordered_set <int>> following;
    Twitter() {
     
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> v;
        for (auto it: tweet[userId]){
            v.push_back(it);
        }
       for (auto it: following[userId]){
        for (auto i: tweet[it]){
            v.push_back(i);
        }
       }
       sort(v.rbegin(),v.rend());
       vector <int> ans;
       for (auto s: v){
         if (ans.size()>=10) break;
         ans.push_back(s.second);
       }
       return ans;
    }
    
    void follow(int followerId, int followeeId) {
         following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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