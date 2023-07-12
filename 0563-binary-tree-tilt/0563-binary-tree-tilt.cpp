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
    int findTilt(TreeNode* root) {
        int sum = 0;
        find(root,sum);
        return sum;
    }
    
    int find(TreeNode* root,int &sum) {
        if (root == NULL) return 0;
        int leftSum = find(root->left,sum);
        int rightSum = find(root->right,sum);
        sum += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};