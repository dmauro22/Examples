# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: 'ListNode', l2: 'ListNode') -> 'ListNode':
        merged = ListNode(0)
        
        walker = merged
        
        while l1 or l2:
            
            if not l1:
                walker.next = l2
                return merged.next
            
            if not l2:
                walker.next = l1
                return merged.next
                
            if l1.val <= l2.val:
                walker.next = ListNode(l1.val)
                l1 = l1.next
                walker = walker.next
            
            else:
                walker.next = ListNode(l2.val)
                l2 = l2.next
                walker = walker.next

            
        return merged.next
