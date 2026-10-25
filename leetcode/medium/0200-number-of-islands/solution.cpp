class Solution {
    int r , c ;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
    void bfs (vector<vector<char>>& grid, int x, int y, vector<vector<bool>> &visited){
        //  int rows = grid.size();
        //  int columns = grid[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});

         while (!q.empty()){
            auto [i,j ]  = q.front();
            q.pop();
        for(auto it:dir){
             int newi = it.first + i,newj = it.second + j;
              if(newi <0 || newi >= r || newj < 0 || newj >= c || grid[newi][newj] == '0' || visited[newi][newj]) continue;
            visited[newi][newj] = 1;
            q.push({newi,newj}); 
        }  
         }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        vector<vector<bool>> visited(r , vector<bool> (c,0));
        int isLand = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                isLand++;

                bfs(grid,i,j,visited);
                }
            }
        }
        return isLand;
    }
};