class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        result = " ".join(reversed(words))
        return result