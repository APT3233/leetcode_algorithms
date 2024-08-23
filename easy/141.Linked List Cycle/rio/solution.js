/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let firstPointer = head;
    let secondPointer = head;

    while(firstPointer && firstPointer.next){
        firstPointer = firstPointer.next.next;
        secondPointer = secondPointer.next;

        if(firstPointer === secondPointer) return true;
    }
    return false;  
};