from typing import List

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        count = [0, 0, 0]
        
        # Count the remainders when dividing by 3
        for stone in stones:
            count[stone % 3] += 1
        
        # If there are no stones with remainder 1 or remainder 2, Alice loses
        if count[1] == 0 and count[2] == 0:
            return False
        
        # If there are no stones with remainder 0, Alice wins if min(count[1], count[2]) > 0
        if count[0] == 0:
            return min(count[1], count[2]) > 0
        
        # If count[0] is even, Alice can safely keep making moves that leave Bob with no winning option
        if count[0] % 2 == 0:
            return count[1] > 0 and count[2] > 0
        else:
            # If count[0] is odd, Alice wins if the difference between count[1] and count[2] is greater than 2
            return abs(count[1] - count[2]) > 2