class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        char min_char = s[0], max_char = s[0];
        bool isSorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) isSorted = false;
            if (s[i] < min_char) min_char = s[i];
            if (s[i] > max_char) max_char = s[i];
        }

        if (isSorted) return 0;
        if (n == 2) return -1;
        if (s[0] == min_char || s[n - 1] == max_char)
            return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == min_char || s[i] == max_char)
                return 2;
        }

        return 3;
    }
};