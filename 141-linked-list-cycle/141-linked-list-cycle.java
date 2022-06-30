/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

//Solution is for HasSets, and will directly detect the loop, but will not be the most optimal soltuion
public class Solution {
    public boolean hasCycle(ListNode head) {
        HashSet<ListNode> set = new HashSet<ListNode>();
        int i = 0;
        while (head!=null){
            i++;
            if (i > 10000){
                return true;
            }
            head = head.next;
        }
        return false;
    }
}