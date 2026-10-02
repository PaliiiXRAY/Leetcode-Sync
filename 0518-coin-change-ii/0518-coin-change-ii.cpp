class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //here 0 intialization cause no of ways counting
        vector <unsigned int> dp(amount+1,0);
        //exactly one way to make coin 0 right 
        dp[0] = 1;
         for (int coin: coins){
            for (int i = coin; i <= amount; i++){
                dp[i] = dp[i] + dp[i-coin];
            }
         }
         return dp[amount];
    }
};