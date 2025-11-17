class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjList(V);

        for(auto edge:prerequisites){
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<int> inedge(V);
        for(int i=0;i<V;i++){
            for(auto it:adjList[i]){
                inedge[it]++;
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
            for(auto it:adjList[node]){
                inedge[it]--;
                if(inedge[it]==0){
                    q.push(it);
                }
            }
        
        }

        if(topo.size()<V){
            return false;
        }

        return true;
    }
};