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
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> wraplist = new ArrayList<List<Integer>>();
        Stack<List<Integer>> st = new Stack<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if (root == null) return wraplist;
        q.offer(root);
        while (!q.isEmpty()){
            int n = q.size();
            List<Integer> ls = new ArrayList<Integer>();
            for (int i = 0; i < n ; i++){
                if (q.peek().left != null) q.offer(q.peek().left);
                if (q.peek().right != null) q.offer(q.peek().right);
                ls.add(q.poll().val);
            }
            st.push(ls);
        }
        while (!st.isEmpty()){
            wraplist.add(st.pop());
        }
        return wraplist;
    }
}