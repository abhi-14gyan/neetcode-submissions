class Solution {
public:
    int maxi = 0;
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    void bfs(int row , int col , vector<vector<int>>&vis , vector<vector<int>>&grid){
        vis[row][col] = 1;
        int count=0;
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            count++;
            q.pop();

            for(int i=0 ; i<4 ; i++){
                int nrow = delrow[i] + r;
                int ncol = delcol[i] + c;
                if(nrow >=0 && nrow <grid.size() && ncol >=0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        maxi = max(maxi,count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    bfs(i,j,vis,grid);
                }
            }
        }
        return maxi;
    }
};
