class Solution {
public:
    // bool check_bfs (int start, vector<vector<int>>&graph,vector<int> &color){
    //     // This is the BFS approach of question where we check using the adjancent node of each node and putting it into the queue
    //     queue<int> q;
    //     q.push(start);
    //     color[start] = 0;
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();

    //         for(auto it: graph[node]){
    //             if(color[it]== -1){
    //                 color[it] = !color[node];
    //                 q.push(it);
    //             }else if (color[it]== color[node]){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;

    // }

    bool check_dfs(int start, int col , vector<vector<int>> &graph, vector<int> &color){
        color[start] = col;
        for(auto it: graph[start]){
            if(color[it]== -1){
                // col = !col; // we can directly write it in the function
                if(check_dfs(it, !col,graph,color)== false){
                    return false;
                }
            }else if(color[it] == color[start]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {


        int V= graph.size();        
        vector<int> color(V+1, -1);

        // This for the  BFS approach 

        // for(int i=0;i<V;i++){  // we can directly do checking in this function but to chekc the connected component we need to check for each component 
        //     if(color[i]== -1){
        //         if(check_bfs(i,graph,color)== false){
        //             return false;
        //         }
        //     }
        // }

        // Now Below is the code for the current DFS Approach

        for(int i=0;i<V;i++){
            if(color[i]== -1){
                if(color[i]==-1){
                    if(check_dfs(i,0,graph,color) == false){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};