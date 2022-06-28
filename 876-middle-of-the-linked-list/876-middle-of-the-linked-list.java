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
    public ListNode middleNode(ListNode head) {
        ListNode tail = head;
        ListNode finalNode = head;
        int len = 0;
        while (tail != null){
            len++;
            tail = tail.next;
        }
        if (len % 2 == 0){
            len = 1 + ((len - 1)/2);
            len++;
        }else{len = 1 + ((len - 1)/2);}
        
        for (int i = 0; i < len-1; i++){ //check
            finalNode = finalNode.next;
        }
        return finalNode;
    
    }
}