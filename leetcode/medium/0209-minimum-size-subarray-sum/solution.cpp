class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0 , i = 0 , n = nums.size() , sum = 0 , ans = INT_MAX ;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                sum -= nums[i];
                ans = min(ans , j - i + 1 ) ; 
                i++;

            }
        j++;
        }
    return ans == INT_MAX ? 0 : ans ;
    }
};