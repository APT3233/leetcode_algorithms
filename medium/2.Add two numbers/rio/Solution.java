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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);

        ListNode l3 = head;
        int carryNum = 0;
            while(l1 != null || l2 != null){
                int val_1 = (l1 != null)? l1.val : 0;
                int val_2 = (l2 != null)? l2.val: 0;

                int currentSum = val_1 + val_2 + carryNum;
                carryNum = currentSum / 10;
                int last_digit = currentSum % 10;

                ListNode newNode = new ListNode(last_digit);
                l3.next = newNode;


                if(l1 != null) l1 = l1.next;
                if(l2 != null) l2 = l2.next;

                l3 = l3.next;
            }

    if(carryNum > 0){
        ListNode newNode = new ListNode(carryNum);
        l3.next = newNode;
        l3 = l3.next;
    }
    return head.next;
    }
}