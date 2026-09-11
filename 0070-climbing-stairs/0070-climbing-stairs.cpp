class Solution {
public:
//less goooooo, easy prblm again so here we are using 1D array for this simple ques, basically here  we are saving in a memory
//as you already know, it gets similar to fibonacci series now,
//so dp[i] will be the memory and the exact ways to climb or reach the step no i
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n+1,0);
      dp[1] = 1;
      dp[2] = 2;
      for(int i = 3;i<=n;i++){
      dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
    }
};