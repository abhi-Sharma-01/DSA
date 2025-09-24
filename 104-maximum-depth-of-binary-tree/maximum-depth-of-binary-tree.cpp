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
        int maxDepth(TreeNode* root){
            if(root==NULL) return 0;
            int leftheight = maxDepth(root->left);
            int rightheight = maxDepth(root->right);

            return 1 + max(leftheight , rightheight);
        }
};
//     int maxDepth(TreeNode* root) {
//    
//         // Method 2: Using the level order where we can use counter
//         int height =0;
//         // vector<vector<int> > res;
//         if(root== NULL) return height;

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()){
//             int size= q.size();
//             height++;
//             for(int i=0;i<size;i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }

//             } 
            
//         }

//         return height;

//     }
// };