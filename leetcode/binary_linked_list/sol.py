
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        

class Solution:
    def getDecimalValue(self, head: ListNode):
        dimension = self.GetLinkedListLength(head)
        decimal_value = 0
        list_iter = head
        while list_iter:
            if list_iter.val == 1:
                decimal_value += 2 ** (dimension - 1)
            dimension -= 1
            list_iter = list_iter.next
        return decimal_value
        
    def GetLinkedListLength(self, head: ListNode):
        counter = 0
        temp_iter = head
        while temp_iter:
            counter += 1
            temp_iter = temp_iter.next
        return counter
        