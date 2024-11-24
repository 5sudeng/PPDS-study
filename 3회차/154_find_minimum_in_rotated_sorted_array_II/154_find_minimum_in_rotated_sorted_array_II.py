def find_min(nums):
    left, right = 0, len(nums) - 1

    while left < right:
        mid = (left + right) // 2

        # If the middle element is greater than the rightmost, the minimum is in the right half
        if nums[mid] > nums[right]:
            left = mid + 1
        # If the middle element is less than the rightmost, the minimum is in the left half (including mid)
        elif nums[mid] < nums[right]:
            right = mid
        # If the middle element is equal to the rightmost, we can't be certain of the half, so reduce the search space
        else:
            right -= 1

    return nums[left]