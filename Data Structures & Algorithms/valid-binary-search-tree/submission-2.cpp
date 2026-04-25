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
    bool inorder(TreeNode* curr, int &prev) {
        if(!curr){
            return true;
        }
        if(!inorder(curr->left, prev)){
            return false;
        }
        if(prev >= curr -> val){
            return false;
        }
        prev = curr -> val;
        return inorder(curr->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        int prev = -1001;
        return inorder(root, prev);
    }
};
