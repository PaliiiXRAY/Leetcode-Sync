# Number of Provinces

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A  **province**  is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return  *the total number of  **provinces***.

 

 **Example 1:** 

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

```

 **Example 2:** 

```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

```

 

 **Constraints:** 

- 1 <= n <= 200
- n == isConnected.length
- n == isConnected[i].length
- isConnected[i][j] is 1 or 0.
- isConnected[i][i] == 1
- isConnected[i][j] == isConnected[j][i]

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-10-05T10:22:00.518Z  

```cpp
class Solution {
    
public:
int n;
 void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;
        for (int j = 0; j<n; j++){
            if (isConnected[node][j] == 1 && visited[j] == 0) q.push(j);
        }
    }

 }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool>visited(n);
        int ans = 0;
        for (int i = 0; i< n; i++){
            if(!visited[i]) {
                bfs(isConnected, visited, i); 
                ans++;
                }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-provinces/)