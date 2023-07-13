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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL and root->right == NULL) return root->val;
        int sum = 0;
        roottoleaf(root->left,root->val,sum);
        roottoleaf(root->right,root->val,sum);
        return sum;
    }
    
    void roottoleaf(TreeNode* root,int curr,int &sum){
        if (root == nullptr) return;
        if (root->left == nullptr and root->right == nullptr) {
            curr = (curr * 10) + root->val;
            sum += curr;
            return;
        }
        curr = (curr * 10) + root->val;
        roottoleaf(root->left,curr,sum);
        roottoleaf(root->right,curr,sum);
        return;
    }
};