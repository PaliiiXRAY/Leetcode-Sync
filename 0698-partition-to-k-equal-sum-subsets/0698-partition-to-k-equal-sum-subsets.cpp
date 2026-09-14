class Solution {
public:
    bool backtracking(vector<int>& nums, int target, int index, vector<int>& subsetSums) {
        if (index == nums.size()) {
            return true;
        }
        for (int i = 0; i < subsetSums.size(); i++) {
            if (subsetSums[i] + nums[index] <= target) {
                subsetSums[i] += nums[index];
                
                if (backtracking(nums, target, index + 1, subsetSums)) {
                    return true;
                }
                subsetSums[i] -= nums[index];
            }
            if (subsetSums[i] == 0) {
                break;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>()); 
        vector<int> subsetSums(k, 0); 
        return backtracking(nums, target, 0, subsetSums);
    }
};