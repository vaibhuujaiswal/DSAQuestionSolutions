/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

//method-I using level

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> wrapList = new ArrayList<Double>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if (root == null) return wrapList;
        q.offer(root);
        while (!q.isEmpty()){
            int n = q.size();
            double total = 0;
            for (int i = 0; i < n; i++){
                if (q.peek().left != null) q.offer(q.peek().left);
                if (q.peek().right != null) q.offer(q.peek().right);
                total += q.poll().val;
            }
            wrapList.add(total/n);
        }
        return wrapList;
    }
}