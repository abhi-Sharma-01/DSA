// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void preorder(TreeNode* node, vector<vector<int>>&edgesList){
//         if(node == NULL){
//             return;
//         }           
//         // so Before Traversing using recursion we need to store the pair 
//         if(node->left){
//             edgesList.push_back({node->val, node->left->val});
//             preorder(node->left,edgesList);
//         }
//         if(node->right){
//             edgesList.push_back({node->val, node->right->val});
//             preorder(node->right,edgesList);
//         }
//     }
//     int countNode(TreeNode* root){
//         if(root== NULL) return 0;

//         return 1+ countNode(root->left) + countNode(root->right);
//     }

//     int amountOfTime(TreeNode* root, int start) {
//         TreeNode* node = root;
//         int V= countNode(root);
//         vector<vector<int>> edgesList;
//         preorder(root, edgesList);// Now we are having the edgesList 
//         cout<<V<<endl;
//         vector<int> adjList();
        
//         return V;
//     }
// };

class Solution {
public:
    void buildGraph(TreeNode* node, unordered_map<int, vector<int>>& graph) {
        if (!node) return;

        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);  // as undirected hai 
            buildGraph(node->left, graph);
        }

        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            buildGraph(node->right, graph);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        buildGraph(root, graph);

        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; ++i) {
                int curr = q.front(); q.pop();
                for (int neighbor : graph[curr]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return minutes;
    }
};