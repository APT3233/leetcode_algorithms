# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# recursive

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        if not list1 or list2:
            return list1 or list2
        
        if(list1.val < list2.val):
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1;
        
        else:
            list2.next = self.mergeTwoLists(list2.next, list2)
            return list2