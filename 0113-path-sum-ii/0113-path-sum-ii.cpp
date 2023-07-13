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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        if (root == NULL) return output;
        if (root->left == NULL and root->right == NULL){
            if (targetSum == root->val){
                vector<int> o;
                o.push_back(root->val);
                output.push_back(o);
                return output;
            }
            return output;
        }
        vector<int> temp;
        ps(root,targetSum,output,temp);       
        return output;
    }
    
    void ps(TreeNode* root,int targetSum,vector<vector<int>> &output,vector<int> temp){
        if (root == NULL) return;
        if (root->left == NULL and root->right == NULL){
            if (targetSum == root->val){
                temp.push_back(root->val);
                output.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        ps(root->left,targetSum - root->val, output, temp);
        ps(root->right,targetSum - root->val, output, temp);
        return;
    }
    
};