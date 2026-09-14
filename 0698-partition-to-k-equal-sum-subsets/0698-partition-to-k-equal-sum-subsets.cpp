class Solution {
public:
    bool solve(int mask, vector<int>& arr, int target, int k, int bucket_no,
               int bucket_sum, vector<int>& dp) {
        if (bucket_no == k) {
            return true;
        }
        if (bucket_sum == target) {
            return solve(mask, arr, target, k, bucket_no + 1, 0, dp);
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
        for (int i = 0; i < arr.size(); i++) {
            if ((mask & (1 << i)) == 0) {
                if (bucket_sum + arr[i] <= target) {
                    int new_mask = mask | (1 << i);
                    if (solve(new_mask, arr, target, k, bucket_no,
                              bucket_sum + arr[i], dp)) {
                        return dp[mask] = 1;
                    }
                }
            }
        }
        return dp[mask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        int n = nums.size();
        vector<int> dp(1 << n, -1);
        return solve(0, nums, target, k, 0, 0, dp);
    }
};