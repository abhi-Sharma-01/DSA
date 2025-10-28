class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // // My Instinct
        // int v = edges.size() + 1; // number of nodes
        // int res = -1;
        // vector<int> vis(v + 1, 0); // 1-based indexing

        // for (int i = 0; i < edges.size(); i++) { 
        //     int a = edges[i][0];
        //     int b = edges[i][1];
        //     vis[a]++;
        //     vis[b]++;
        // }

        // for (int i = 1; i <= v; i++) {
        //     if (vis[i] == edges.size()) { 
        //         res = i;
        //         break;
        //     }
        // }

        // return res;

        // Approach 2 After Visualization

        // note her we need to just check any two edges as one element always gonna occur again and again
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];

    }
};