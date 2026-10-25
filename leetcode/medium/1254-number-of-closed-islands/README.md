# Number of Closed Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An  *island*  is a maximal 4-directionally connected group of `0s` and a  *closed island*  is an island  **totally**  (all left, top, right, bottom) surrounded by `1s.`

Return the number of  *closed islands*.

 

 **Example 1:** 

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

 **Example 2:** 

```
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

```

 **Example 3:** 

```
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

```

 

 **Constraints:** 

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 55.01%)  
**Memory:** 12.9 MB (beats 95.61%)  
**Submitted:** 2026-10-25T18:05:18.386Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-closed-islands/)