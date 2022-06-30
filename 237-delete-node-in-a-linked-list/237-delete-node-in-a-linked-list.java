/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode value = node; //condition given that we can't remove tail node.
        while (value.next.next != null){
            value.val = value.next.val;
            value.next.val = node.val;
            value = value.next;
        }
        value.val = value.next.val;
        value.next = null;
    }
}