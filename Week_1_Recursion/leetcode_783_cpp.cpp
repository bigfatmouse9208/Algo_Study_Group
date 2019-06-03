/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.
Memory Usage: 11.1 MB, less than 70.53% of C++ online submissions for Minimum Distance Between BST Nodes.
 */
class Solution {
public:
    int minDiff = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return minDiff;
    }

    pair<int , int> dfs(TreeNode* node){ // return the smallest and largest value of the subtree rooted at node
        if (!node){
            return make_pair(NULL , NULL);
        }
        int smallest = node->val , biggest = node->val;
        if (node->left != NULL){
            auto temp_res = dfs(node->left);
            minDiff = min(minDiff , node->val - temp_res.second); // update
            smallest = temp_res.first;
        }
        if (node->right != NULL){
            auto temp_res = dfs(node->right);
            minDiff = min(minDiff , temp_res.first - node->val); // update
            biggest = temp_res.second;
        }
        return make_pair(smallest , biggest);
    }
};
