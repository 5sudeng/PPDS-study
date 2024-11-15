class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = [0, 0, 0, 0, 0]
        result = 0
        eng = ['b', 'a', 'l', 'o', 'n']
        values = [1, 1, 0.5, 0.5, 1]
        for i in range(len(text)) :
            for j in range(5) :
                if text[i] == eng[j] :
                    cnt[j] += values[j]
        
        result = int(min(cnt))

        return result;