class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> inedge(V);
        vector<vector<int>> adjListRev(V);
        for(int i=0;i<V;i++){
            for(auto it :graph[i]){
                adjListRev[it].push_back(i);
                inedge[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inedge[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjListRev[node]){
                inedge[it]--;
                if(inedge[it]==0){
                    q.push(it);
                }
            }
        }
        
        sort(topo.begin(),topo.end());

        return topo;
    
        
    }
};