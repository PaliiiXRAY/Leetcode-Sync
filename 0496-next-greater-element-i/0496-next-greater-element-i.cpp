class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      unordered_map <int,int> mp;
       stack<int>s;
       for (int num : nums2){
        while (!s.empty() && s.top() < num) {
            mp[s.top()] = num;
            s.pop();
        }
         s.push(num);
       }
       while (!s.empty()) {
            mp[s.top()] = -1;
            s.pop();
        }
        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        
        return ans;
     
    }
};