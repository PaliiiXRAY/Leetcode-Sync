class Solution {
public:
bool IsPossible (int mid, vector<int>&piles, long long h){
    long long total_hours = 0;
    for (int pile : piles) {
            total_hours += (pile + mid - 1) / mid; 
        }
        return total_hours <= h;
}
    int minEatingSpeed(vector<int>& piles, long long h) {
        int ans = 0;
        long long low = 1;
        long long  high = *max_element(piles.begin(), piles.end());
        while (low <= high){
        long long mid = low + (high - low)/2;
        if(IsPossible(mid, piles , h)){
            ans = mid;
            high = mid - 1;
        }
        else {
         low = mid + 1;
        }
        } 
        return ans;
    }
};