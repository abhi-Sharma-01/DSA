/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void  graph_edges(TreeNode* node, vector<vector<int>> & edgeList){
        if(node == NULL) return ;

        if(node->left){
            edgeList.push_back({node->val,node->left->val});
            // edgeList[node->left->val].push_back(node->val);
            graph_edges(node->left,edgeList);
        }

        if(node->right){
            edgeList.push_back({node->val, node->right->val});
            // edgeList[node->right->val].push_back(node->val);
            graph_edges(node->right,edgeList);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> edgeList;
        TreeNode* node = root;
        graph_edges(node,edgeList);
        // As in the adjList we have to store the elelment in respective node number but as treenode can have value 
        // not necessarily similar as that of the index of vector we generally use in the garph 

        // vector<vector<int>> adjList(n)// generally used in the graph normally 
        //  but here we are going to us the 

        map<int, vector<int>> adjList;
        for(auto edge:edgeList){
            int u = edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); // we gonna need oth the edges as undirected 
        }

        unordered_set<int> visited;// so here we have initlaize set which is going to store the element 
        queue<int> q;
        q.push(start);
        visited.insert(start);
        int min_time = -1;

        while(!q.empty()){
            int size = q.size();
            min_time++;

            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(int neigh: adjList[node] ){
                    if(!visited.count(neigh)){
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }

        return min_time;
    }
};