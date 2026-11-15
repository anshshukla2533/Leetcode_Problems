class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<vector<int>>& prerequisites,int node,vector<bool>&vis,vector<bool>&pathvis){
   vis[node]=true;
   pathvis[node]=true;
     for(auto ne:adj[node]){
        if(!vis[ne] && ne!=node){
            if(dfs(adj,prerequisites,ne,vis,pathvis))return true;
        }else if(pathvis[ne])return true;
     }
     pathvis[node]=false;
     return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<bool>vis(numCourses,false);
          vector<bool>pathvis(numCourses,false);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
        if(!vis[i]){
        if(dfs(adj,prerequisites,i,vis,pathvis))return false;
        }
        }
        return true;


    }
};