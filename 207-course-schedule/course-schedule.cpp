class Solution {
public:
    bool check_dfs(int start,vector<vector<int>>&adjList, vector<int>&Visited, vector<int> &pathVis){
        Visited[start] = 1;
        pathVis[start] = 1;

        for(auto it :adjList[start]){
            if(!Visited[it]){
                if(check_dfs(it,adjList,Visited,pathVis)) return true;
            }else if(pathVis[it]){
                return true;
            }
            
        }


        pathVis[start] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;

        vector<vector<int>> adjList(V);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }
        vector<int> Visited(V,0);
        vector<int> pathVis(V,0);

        for(int i=0;i<V;i++){
            if(!Visited[i]){
                if(check_dfs(i,adjList,Visited,pathVis)) {
                    return false;
                }
            }
        }

        return true;
    }
};