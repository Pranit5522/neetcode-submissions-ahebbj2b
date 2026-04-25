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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size() != 1){
            vector<int> row;
            while(q.front()){
                TreeNode* curr = q.front();
                if(curr -> left){
                    q.push(curr -> left);
                }
                if(curr -> right){
                    q.push(curr -> right);
                }
                row.push_back(curr -> val);
                q.pop();
            }
            q.pop();
            q.push(NULL);
            ans.push_back(row);
        }

        return ans;
    }
};
