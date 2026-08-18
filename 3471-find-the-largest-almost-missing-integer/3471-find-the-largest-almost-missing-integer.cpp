class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
           sort(nums.begin(), nums.end());
           int r = nums[n - 1];
           return r;
        }
        // int i = 0;
        // while (i < n){
        //     return max(nums[0], nums[n-1]);
        // }
        vector <int> count (51,0);
         for(int x : nums) count[x]++;
         if ( k == 1){
            int mx = -1;
        for (int i = 0; i<=50; i++){
            if(count[i] == 1) mx = max(mx,i);
            }
            return mx;
         }
         int mx = -1;
     if (count[nums[0]] == 1) mx = max(mx, nums[0]);
     if (count[nums[n-1]] == 1) mx = max(mx, nums[n-1]);
      return mx;
    }
};