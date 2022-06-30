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
        HashSet<ListNode> set=new HashSet<>();  
        ListNode finalValue = null;
        ListNode A = headA;
        while (A != null){
            set.add(A);
            A = A.next;
        }
        while (headB != null) {
            if (set.contains(headB)){
                finalValue = headB;
                break;
            }
            headB = headB.next;
        }
        return finalValue;
    }
}