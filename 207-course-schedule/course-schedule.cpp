class Solution {
public:
 bool dfs(int start,vector<vector<int>>&graph,vector<int>&path,vector<int>&visited )
    {
        visited[start] =1;
        path[start]=1;
        
        for(int i=0;i<graph[start].size();i++)
        {
            if(graph[start][i]==1 && visited[i]==1 && path[i]==1) return true;
            
            if(graph[start][i]==1 && visited[i]==0)
            {
               if( dfs(i,graph,path,visited)) return true;
            }
            
        }
        path[start] =0;
        
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& edges) {
       
        vector<int>visited(v,0),path(v,0);
        vector<vector<int>>graph(v,vector<int>(v,0));
        
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            graph[y][x]=1;
        }
        
        for(int i=0;i<v;i++)
        {
            if(visited[i] ==0)
            {
                if(dfs(i,graph,path,visited)) return false;
            }
        }
        
        return true;
    }
};