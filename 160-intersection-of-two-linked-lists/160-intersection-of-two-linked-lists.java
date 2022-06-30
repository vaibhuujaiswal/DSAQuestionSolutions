/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA; //intialize each node
        ListNode b = headB;
        ListNode finalValue = null;
        while (a!= null || b!=null){ 
            //The while loop will break when both the pointer together are equal to null
            if (a == null) a = headB;
            else if (b == null) b = headA;
            if (a == b){
                finalValue = a;
                break;
            }
            // System.out.print(a.val + " ");
            // System.out.print(b.val);
            // System.out.println(" ");
            a = a.next;
            b = b.next;
        }
        return finalValue;
    }
}