# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        # 노드가 0, 1, 2개인 경우, 그대로 반환
        if not head or not head.next or not head.next.next:
            return head

        odd_tail = head
        even_head = head.next
        even_tail = head.next

        idx = 3
        curr = head.next.next
        while curr:
            if idx % 2 == 1:
                odd_tail.next = curr
                odd_tail = curr
            else:
                even_tail.next = curr
                even_tail = curr
            curr = curr.next
            idx += 1

        odd_tail.next = even_head
        even_tail.next = None
        return head