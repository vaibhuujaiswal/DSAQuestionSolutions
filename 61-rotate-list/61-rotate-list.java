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
    public ListNode rotateRight(ListNode head, int k) {
        ListNode tail = head;
        if (head == null || k == 0){
            return head;
        }
        int len = 1;
        while (tail.next!= null){
            len++;
            tail = tail.next;
        }
        k = k % len;
        tail.next = head;
        for (int i = 0; i < len - k; i++){
            head = head.next;
            tail = tail.next;
        }
        tail.next = null;
        return head;
    }
}