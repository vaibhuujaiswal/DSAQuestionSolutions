/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode node = head;
        ListNode prev = dummy;
        
        while(node != null) {
            if(node.val != val) {
                prev.next = node;
                prev = node;
            }
            node = node.next;
        }
        if(prev != null)
            prev.next = null;
        return dummy.next;
    }
}