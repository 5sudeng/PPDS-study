def solution(K, A):
    """
    Given an integer K and a non-empty list A of integers,
    returns the maximum number of ropes of length greater than or equal to K
    that can be created by tying adjacent ropes.

    Parameters:
    - K: Integer, the minimum required length of each rope.
    - A: List of integers, lengths of the individual ropes.

    Returns:
    - Integer, the maximum number of ropes of length >= K.
    """
    count = 0            # Number of ropes with length >= K
    current_length = 0   # Length of the current rope being formed

    for length in A:
        current_length += length  # Tie the current rope with the next one
        if current_length >= K:
            count += 1            # Found a rope of sufficient length
            current_length = 0    # Reset to start forming a new rope

    return count

# Example usage:
if __name__ == "__main__":
    K = 4
    A = [1, 2, 3, 4, 1, 1, 3]
    result = solution(K, A)
    print(f"The maximum number of ropes of length >= {K} is: {result}")