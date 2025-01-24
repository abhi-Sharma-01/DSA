class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0 = unvisited, 1 = visiting, 2 = safe

        vector<int> safeNodes;
        for (int i = 0; i < n; ++i) {
            if (isSafe(i, graph, state)) {
                safeNodes.push_back(i);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
    
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] > 0) {
            return state[node] == 2;
        }
        
        state[node] = 1;
        for (int next : graph[node]) {
            if (state[next] == 2) {
                continue;
            }
            if (state[next] == 1 || !isSafe(next, graph, state)) {
                return false;
            }
        }
        
        state[node] = 2;
        return true;
    }
};
