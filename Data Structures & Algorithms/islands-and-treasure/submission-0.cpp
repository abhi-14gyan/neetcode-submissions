class Solution {
public:
    int INF = 2147483647;
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for(int i=0 ; i<4 ; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == INF){
                    grid[nrow][ncol] = t+1;
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
};
