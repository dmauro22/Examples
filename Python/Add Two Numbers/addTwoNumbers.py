# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        l3 = ListNode(0)
        
        walker = l3
        
        carry = 0
        
        total = 0
        
        while (l1 or l2 or carry):
        
            if l1:
                total += l1.val
                l1 = l1.next
        
            if l2:
                total += l2.val
                l2 = l2.next
                
            if carry:
                total += 1
                carry = 0
        
            if total > 9:
                carry = 1
                total %= 10
            
            walker.next = ListNode(total)
            
            total = 0
            
            walker = walker.next
        
        return l3.next
        
