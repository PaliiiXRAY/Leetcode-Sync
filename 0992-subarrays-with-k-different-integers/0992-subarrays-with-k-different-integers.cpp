class Solution {
public:
    int AtMost(vector<int>&nums,int k){
        int left = 0;
        int total_sum = 0;
        unordered_map <int , int> freq;
        for(int right = 0; right<nums.size(); right++){
            freq[nums[right]]++; 
        
        while(freq.size() > k){
          freq[nums[left]]--;
          if(freq[nums[left]] == 0){
            freq.erase(nums[left]);
          }
          left++;
        }
         total_sum += right - left + 1;
        }
        return total_sum;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMost(nums , k) - AtMost(nums , k - 1);
    }
};