class Solution {
public:
        int m,n;
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    if(helper(i,j,grid) == true) ans++;
                }
            }
        }
        return ans;   
    }
    bool helper(int i, int j, vector<vector<int>>&grid){
        if( i < 0 || j < 0 || i >= m || j >= n) return false ;
        if(grid[i][j] == 1  ) return true ;
        grid[i][j] = 1 ;
        bool f =  helper(i+1, j , grid)  ;
        bool g =  helper(i-1, j , grid)  ;
        bool h =  helper(i, j+1 , grid)  ;
        bool k =  helper(i, j-1 , grid)  ;
    return f && g && h && k ;
    }
};