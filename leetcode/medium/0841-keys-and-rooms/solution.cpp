class Solution {
public:
int n;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vector<bool> visited(n);
        queue<int>q;
        q.push(0);
    
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = 1;
            for(auto it: rooms[node]){
             if(!visited[it]) q.push(it);
            }
        }
        for(bool b : visited) if(b==0) return 0;
        return 1;
        }
};