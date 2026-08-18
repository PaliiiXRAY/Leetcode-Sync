class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        int n = nums.size();
        bool flag = false;
        for (int num : nums) {
            xorr ^= num;
            if (num != 0)  flag = true;
        }
    if (xorr != 0) return n;
    if (!flag) return 0;
    return n-1;
    }
};