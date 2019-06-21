/**
Runtime: 16 ms, faster than 82.99% of C++ online submissions for Find Bottom Left Tree Value.
Memory Usage: 20.9 MB, less than 48.80% of C++ online submissions for Find Bottom Left Tree Value.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int findBottomLeftValue(TreeNode* root) {
        ans = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            for (int n = q.size() ; n > 0 ; n--){
                auto curr = q.front();
                q.pop();
                if (curr->left != NULL){
                    q.push(curr->left);
                }
                if (curr->right != NULL){
                    q.push(curr->right);
                }
            }
            if (!q.empty()){
                ans = q.front()->val;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};
