class Solution {
public:
    bool check_dfs(int node, vector<vector<int>>&adjList,vector<int>&Vis,vector<int> &pathVis){
        Vis[node] = 1;
        pathVis[node] = 1;

        for(auto nbr: adjList[node]){
            if(!Vis[nbr]){
                if(check_dfs(nbr, adjList, Vis, pathVis)) return true;
            }else if(pathVis[nbr]){
                return true;
            }
        }

        pathVis[node] = 0; // we need to unvisit the node 
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        if(prerequisites.size()==0) return true;
        vector<vector<int>> adjList(V);
        for(auto edge:prerequisites){
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> Vis(V,0);
        vector<int> pathVis(V,0);


        for(int i=0;i<V; i++){
            if(!Vis[i]){
                if(check_dfs(i,adjList,Vis,pathVis)) return false;
            }
        }

        return true;// i.e No cycle found , so we can complete the courses without any deadlock        
    }
};