class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();
        int maxi = amount + 1;
        vector<int>dp(amount + 1, maxi);
        dp[0] = 0;
        for (int i = 1; i<= amount; i++){
            for (int coin : coins){
                if (i - coin >= 0){
                    dp[i] = min(dp[i] , 1 +dp[i-coin] );
                }
            }
        }
        if(dp[amount] == maxi){
            return -1;
        }
        return dp[amount];
    }
};