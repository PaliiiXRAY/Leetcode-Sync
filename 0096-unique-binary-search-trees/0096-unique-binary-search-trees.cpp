class Solution {
public:
    int numTrees(int n) {
        //Catalan numbers formula used here 
        long long ans = 1;
        for (int i = 1; i<=n; i++){
            ans = ans * (4*i - 2) / (i+1);
        }
        return ans;
    }
};