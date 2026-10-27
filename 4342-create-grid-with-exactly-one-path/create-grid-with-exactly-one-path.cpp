class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);

        for (int i = 0; i < m; i++) {
            string res = "";

            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    res += '.';
                } else {
                    res += '#';
                }
            }
            grid[i] = res;
        }

        return grid;
    }
};