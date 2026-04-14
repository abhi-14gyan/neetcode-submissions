class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>&vis, int node , int n){
        vis[node]=1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it,n);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                count++;
                dfs(adj,vis,i,n);
            }
        }
        return count;
    }
};
