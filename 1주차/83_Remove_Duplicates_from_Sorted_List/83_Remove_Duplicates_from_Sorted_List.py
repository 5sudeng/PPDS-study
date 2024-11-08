from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = head
        while current and current.next:
            if current.val == current.next.val:
                # Skip the duplicate node
                current.next = current.next.next
            else:
                # Move to the next distinct element
                current = current.next
        return head

def create_linked_list(nums):
    """Creates a linked list from a list of numbers and returns the head."""
    if not nums:
        return None
    head = ListNode(nums[0])
    current = head
    for num in nums[1:]:
        current.next = ListNode(num)
        current = current.next
    return head

def print_linked_list(head):
    """Prints the linked list in a readable format."""
    elements = []
    current = head
    while current:
        elements.append(str(current.val))
        current = current.next
    print(" -> ".join(elements))

def main():
    solution = Solution()

    # Test Case 1: Empty list
    nums1 = []
    head1 = create_linked_list(nums1)
    result1 = solution.deleteDuplicates(head1)
    print("Test Case 1:")
    print_linked_list(result1)  # Expected Output: (nothing)

    # Test Case 2: List with no duplicates
    nums2 = [1, 2, 3, 4, 5]
    head2 = create_linked_list(nums2)
    result2 = solution.deleteDuplicates(head2)
    print("\nTest Case 2:")
    print_linked_list(result2)  # Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    # Test Case 3: List with consecutive duplicates
    nums3 = [1, 1, 2, 3, 3]
    head3 = create_linked_list(nums3)
    result3 = solution.deleteDuplicates(head3)
    print("\nTest Case 3:")
    print_linked_list(result3)  # Expected Output: 1 -> 2 -> 3

    # Test Case 4: All elements are duplicates
    nums4 = [2, 2, 2, 2, 2]
    head4 = create_linked_list(nums4)
    result4 = solution.deleteDuplicates(head4)
    print("\nTest Case 4:")
    print_linked_list(result4)  # Expected Output: 2

    # Test Case 5: Large list with random duplicates
    nums5 = [1, 1, 1, 2, 3, 3, 4, 4, 5, 5, 5]
    head5 = create_linked_list(nums5)
    result5 = solution.deleteDuplicates(head5)
    print("\nTest Case 5:")
    print_linked_list(result5)  # Expected Output: 1 -> 2 -> 3 -> 4 -> 5

if __name__ == "__main__":
    main()