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
    public ListNode partition(ListNode head, int x) {
        ListNode curr=head; // Pointer to traverse the original list
         // Dummy node and tail for nodes smaller than x
        ListNode dummySmall=new ListNode(-1);
        ListNode smallTail=dummySmall;
        // Dummy node and tail for nodes greater than or equal to x
        ListNode dummyLarge=new ListNode(0);
        ListNode largeTail=dummyLarge;
        while(curr!=null){
            ListNode temp=curr.next; // Save next node before breaking curr links
            if(curr.val<x){
                smallTail.next=curr; // Append current node to the small list
                smallTail=smallTail.next; //move tail of small list
            }else{
                largeTail.next=curr;  // Append current node to the large list
                largeTail=largeTail.next; //move tail of large list
            }
            curr.next=null; // Detach current node from the original list
            curr=temp; // Move to the next node
        }
        smallTail.next=dummyLarge.next;  // Connect both partitions
        return dummySmall.next;
    }
}