#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Step 1: Use unsigned int to dodge the signed overflow trap
        vector<unsigned int> dp(target + 1, 0);
        
        // Base case: 1 way to make amount 0
        dp[0] = 1;
        
        // Step 2: Amount loop on the OUTSIDE (Permutations logic)
        for (int i = 1; i <= target; i++) {
            
            // Step 3: Coin loop on the INSIDE
            for (int num : nums) {
                // If the coin can physically fit into the current amount
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};