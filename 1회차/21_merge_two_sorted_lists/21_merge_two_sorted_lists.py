# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution1(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        sentinel = ListNode()
        curNode = sentinel

        while (list1 and list2): 
            if list1.val <= list2.val:
                curNode.next = list1
                list1 = list1.next
            else :
                curNode.next = list2
                list2 = list2.next
            curNode = curNode.next
        
        ## Append the remaining nodes
        if list1 :
            curNode.next = list1
        else :
            curNode.next = list2
        
        return sentinel.next

        
class Solution2(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if list1 is None and list2 is not None:
            return list2
        elif list1 is not None and list2 is None:
            return list1
        head=None 
        prev=None
        while list1 is not None and list2 is not None:
            if list1.val<=list2.val:
                if head==None:
                    head=list1
                    prev=list1
                    list1=list1.next
                    continue
                prev.next=list1
                prev=list1
                list1=list1.next
                
            elif list1.val>list2.val:
                if head==None:
                    head=list2
                    prev=list2
                    list2=list2.next
                    continue
                prev.next=list2
                prev=list2
                list2=list2.next
        if prev==None:
            return head
        if list1 is not None:
            prev.next=list1
        else:
            prev.next=list2
        return head
        
class Solution3(object): ## 재귀적으로 푸는 방법 추가
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # 기본 케이스: 하나의 리스트가 비어 있으면 다른 리스트 반환
        if not list1:
            return list2
        if not list2:
            return list1
        
        # 재귀적으로 두 리스트를 합병
        if list1.val < list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2

