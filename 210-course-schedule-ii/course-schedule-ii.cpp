class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList,vector<int>& visited,vector<int>& pathVisited,vector<int>& result) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (int it : adjList[node]) {
            if (!visited[it]) {
                if (dfs(it, adjList, visited, pathVisited, result)) return true;
            } else if (pathVisited[it]) {
                return true;
            }
        }

        pathVisited[node] = 0;
        result.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=  numCourses;

        vector<vector<int>> adjList(V);
        for(auto edge:prerequisites){
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(V, 0), pathVisited(V, 0), result;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i, adjList, visited, pathVisited, result)) {
                    return {}; 
                }
            }
        }

        return result;
    }
};