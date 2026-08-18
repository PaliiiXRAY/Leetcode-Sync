class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (power > 0) {
            if (power % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            power /= 2;
        }
        
        return result;
    }
};
