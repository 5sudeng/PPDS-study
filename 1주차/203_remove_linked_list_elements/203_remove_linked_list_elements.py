'''
head of liked list가 주어지고, val이 주어지면, liked list에서 val 값을 갖는 모든 노드는 지우고, 
head를 반환

linked list에서 searching, deleting을 하면 됨.


Example 2:

Input: head = [], val = 1
Output: []


Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
'''

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        '''
        Optional[ListNode]
        head : ListNode class로 주어주든, 혹은 None으로 주어진다는 뜻.
        '''
        
        if not head:
            return None
        
  
        current = head
        prev = None

        while(current):
            
            #find node and pop
            if current.val == val:
                if current == head:
                    head = current.next
                
                else:
                    prev.next = current.next

            else:
                prev = current #넘어가는게 current == val이 아닐 때만, 맞으면 넘어가면 안됨.
            current = current.next

        return head
    

#번외
def create_liked_list(values : list):
    if not values:
        return None
    
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head



def print_liked_list(head : Optional[ListNode]):
    current = head
    elements =[]
    while(current):
        elements.append(current.val)
        current = current.next

    print(" -> ".join(map(str, elements)))
        

def main():
    
    values = [1,2,6,3,4,5,6]
    values =[7,7,7,7]
    values = [1,2,2,1]
    head = create_liked_list(values)
    print_liked_list(head)
    val = 2

    sol = Solution()
    new_head = sol.removeElements(head, val)
    print_liked_list(new_head)
    

if __name__ == "__main__":
    main()