class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prereq) {
        
        vector<vector<int>> adjList(V);
        vector<int> indegree(V);
        for(auto edge: prereq){
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        // stack<int> st;
        queue<int> q;

        for(int i=0;i<V;i++){
            if(indegree[i]== 0){
                // st.push(i);
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nbr : adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }   
        if(topo.size()< V) return {};

        reverse(topo.begin(),topo.end());
        return topo;
    }
};