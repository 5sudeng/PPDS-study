# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 문제 설명 : singly linked list의 head가 input으로 주어질 때 중간노드 return 하기.

class Solution:
    # 첫번째 나이브한 풀이
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #length 구한 뒤 length//2로 중간노드 구함
        cnt=0
        cur=head
        while cur:
            cnt+=1
            cur=cur.next
        for i in range(cnt//2):
            head=head.next
        return head
    # 두번째 풀이
    def middleNode2(self, head: Optional[ListNode]) -> Optional[ListNode]:       
        # 투포인터
        '''
        두 포인터 사용: 빠른 포인터(fast)와 느린 포인터(slow)를 사용합니다.
				fast 포인터는 한 번에 두 칸씩 이동하고, slow 포인터는 한 번에 한 칸씩 이동합니다.
				반복: fast 포인터가 리스트의 끝에 도달하면 slow 포인터는 중간 지점에 도달하게 됩니다.
				리스트의 길이가 홀수이면 정확히 중간 노드를 가리키고, 짝수이면 두 번째 중간 노드를 가리키게 됩니다.
				'''
        fast=head
        slow=fast
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
       