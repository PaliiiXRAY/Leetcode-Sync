class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        int m = s1.size();
        int n = s2.size();
        
        if (i >= m) return n - j;
        if (j >= n) return m - i;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
        } else {
            int ins = 1 + solve(s1, s2, i, j + 1, dp);
            int del = 1 + solve(s1, s2, i + 1, j, dp);
            int repl = 1 + solve(s1, s2, i + 1, j + 1, dp);
            
            return dp[i][j] = min(ins, min(del, repl));
        }
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(word1, word2, 0, 0, dp);
    }
};