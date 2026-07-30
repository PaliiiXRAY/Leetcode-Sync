class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int rem = 0;
        if (n <= 8) {
            return n;
        } else if (n <= 16) {
            rem = n - 8;
            return 2 * rem + 8;
        } else if (n <= 24) {
            rem = n - 16;
            return 3 * rem + 16 + 8;
        } else {
            return 8 + 16 + 24 + (n - 24) * 4;
        }
        return -1;
    }
};