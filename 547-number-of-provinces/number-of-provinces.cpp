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