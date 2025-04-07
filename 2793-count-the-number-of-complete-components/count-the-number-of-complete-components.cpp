class Solution {
public:
    void traversal(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& component) {
        visited[node] = 1;
        component.push_back(node);
        for (int neighbor : adjList[node]) {
            if (visited[neighbor] == 0) {
                traversal(neighbor, adjList, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                vector<int> component;// for each unvisited node new vector start hoga
                traversal(i, adjList, visited, component);

                //yeh hai to count total edges inside the component
                int edgeCount = 0;
                for (int node : component) {
                    edgeCount += adjList[node].size();
                }

                // Total undirected edges is half of total degrees
                edgeCount /= 2;

               
                int size = component.size();
                if (edgeCount == (size * (size - 1)) / 2) {
                    count++;
                }
            }
        }
        return count;
    }
};
