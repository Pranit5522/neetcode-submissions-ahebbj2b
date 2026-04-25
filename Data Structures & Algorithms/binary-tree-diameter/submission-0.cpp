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
    int calc(TreeNode* root, int& maxPath){
        if(!root){
            return 0;
        }

        int left = 1 + calc(root -> left, maxPath);
        int right = 1 + calc(root -> right, maxPath);

        maxPath = max(maxPath, left + right - 1);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxPath = 0;
        calc(root, maxPath);
        return maxPath - 1;
    }
};
