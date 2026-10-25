class Solution {
public:
    int numSquares(int n) {
        //we need minimum count, so init with the max imp value n+1
        vector<int>dp(n+1,n+1);
        //takes 0 squares to make the sum 0
        dp[0] = 0;
        for (int i = 1; i<=n; i++){
            for (int j = 1; j*j <= i; j++){
                int square = j*j;
                dp[i] = min(dp[i],dp[i-square] + 1);
            } 
        }
        return dp[n];
    }
};