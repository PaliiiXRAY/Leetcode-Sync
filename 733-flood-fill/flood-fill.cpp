class Solution {
public:
vector<pair<int,int>> dir = {{1,0}, {-1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        queue<pair<int,int>>q;

        q.push({sr,sc});
             int curr = image[sr][sc];
             image[sr][sc] = color;
        while(!q.empty()){
            auto[i,j] = q.front();
            q.pop();
       
          for (auto it: dir){
            int newi = it.first + i, newj = it.second + j;
            if(newi < 0 || newi >= r || newj < 0 || newj >= c || image[newi][newj] == color) continue;
           if(image[newi][newj] == curr) {
            image[newi][newj] = color; q.push({newi,newj}); 
            }
          }
        }

        // for (int i = 0; i<r; i++){
        //     for (int j = 0; j<c; j++){

        //     }
        // }
        return image;
    }
};