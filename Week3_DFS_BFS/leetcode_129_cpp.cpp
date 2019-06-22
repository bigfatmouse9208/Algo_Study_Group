/**
top-down method
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
Memory Usage: 12.4 MB, less than 55.98% of C++ online submissions for Sum Root to Leaf Numbers.
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
private:
    int sum = 0;

    void dfs(TreeNode* node , int curr){
        if (!node){
            return;
        }
        curr = curr * 10 + node->val;
        if (!node->left && !node->right){
            sum += curr;
            return;
        }
        if (node->left){
            dfs(node->left , curr);
        }
        if (node->right){
            dfs(node->right , curr);
        }
        return;
    }

public:
    int sumNumbers(TreeNode* root) {
        if (!root){
            return 0;
        }
        dfs(root , 0);
        return sum;
    }
};
