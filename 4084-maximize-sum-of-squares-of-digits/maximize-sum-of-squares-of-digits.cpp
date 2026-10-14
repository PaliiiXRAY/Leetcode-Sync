class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9LL * num < sum) return "";
        
        string result;
        result.reserve(num);
        
        while (num-- > 0) {
            int t = min(9, sum);
            result += (char)(t + '0');
            sum -= t;
        }
        
        return result;
    }
};