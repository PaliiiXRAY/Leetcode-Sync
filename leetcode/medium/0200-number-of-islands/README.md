# Number of Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return  *the number of islands*.

An  **island**  is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

 **Example 1:** 

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

```

 **Example 2:** 

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'.

## Solution

**Language:** C++  
**Runtime:** 29 ms (beats 40.13%)  
**Memory:** 23.6 MB (beats 24.05%)  
**Submitted:** 2026-10-05T09:57:04.013Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-islands/)