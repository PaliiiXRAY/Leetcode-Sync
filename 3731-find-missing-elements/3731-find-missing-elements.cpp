class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size();  i++){
            int current = nums[i];
            int prev = nums[i-1];
            if(current - prev > 1){
                for (int m = prev +1; m < current;  m++)
                ans.push_back(m);
            }
        }
          return ans;
    }
};