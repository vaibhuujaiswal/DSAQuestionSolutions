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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        if (root == NULL) return output;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++){
                TreeNode* ele = q.front(); q.pop();
                temp.push_back(ele->val);
                if (ele->left != NULL) q.push(ele->left);
                if (ele->right != NULL) q.push(ele->right);
            }
            output.push_back(temp);
        }
        reverse(output.begin(),output.end());
        return output;
    }
};