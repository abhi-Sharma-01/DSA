class Solution {
public:
    bool check_bfs(int first,vector<vector<int>>&graph, vector<int> &color){
        queue<int> q;
        q.push(first);
        color[first] = 0;

        while(!q.empty()){
            int  node = q.front();
            q.pop();

            for(int nbr : graph[node]){
                if(color[nbr] == -1){
                    color[nbr] = !color[node];
                    q.push(nbr);
                }else if(color[nbr] == color[node]){ // i.e already colored hai
                    return false;
                } 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // we are having an adjList -> graph
        // Now we need to find the if we apply color on graph no two adjacent should be of same color
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i =0;i<V;i++){
            if(color[i]== -1){ // starting from the very first node we will traverse the adjacent node and color them just opposite to the node 
                if(!check_bfs(i,graph,color)) return false;
            }
        }

        return true;
    }
};